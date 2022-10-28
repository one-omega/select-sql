#include"MetadataManager.h"
#include"StorageEngine.h"
#include"InitSQL.h"
#include<stdio.h>
#include<Windows.h>
#include<io.h>

bool mkdir() {
	return CreateDirectory("..\\SQLFile", NULL);		/*创建数据库系统的文件夹*/
}

bool mkfile() {
	FILE* fp;

	/*打开库元数据表，若不存在就创建库元数据表*/
	fopen_s(&fp, "..\\SQLFile\\system_db", "wb");
	if (fp == NULL) 
		return false;
	fclose(fp);
	
	/*打开属于系统的表元数据表，若表不存在就创建文件*/
	fopen_s(&fp, "..\\SQLFile\\system_table", "wb");
	if (fp == NULL) 
		return false;
	fclose(fp);

	/*打开属于系统的列元数据表，若表不存在就创建文件*/
	fopen_s(&fp, "..\\SQLFile\\system_col", "wb");
	if (fp == NULL) 
		return false;
	fclose(fp);

	return true;
}

void insertSYSTable() {
	tableNode* tablenode = createTableNode();
	storageNode* sp = createStorageNode();
	open(sp, "system_table", 28);

	/*向system_db表中加入数据行*/
	setTableNode(tablenode, "system_db\0", 1, 20);		/* system_db表的信息 */
	write_row(sp, tableNodeToRow(tablenode));
	setTableNode(tablenode, "system_table\0", 3, 28);	/* system_table表的信息 */
	write_row(sp, tableNodeToRow(tablenode));
	setTableNode(tablenode, "system_col\0", 6, 57);		/* system_col表的信息 */
	write_row(sp, tableNodeToRow(tablenode));

	close(sp);
	deleteStorageNode(sp);
	deleteTableNode(tablenode);
}

void insertSYSCol() {
	colNode* colnode = createColNode();
	storageNode* sp = createStorageNode();
	open(sp, "system_col", 57);
	
	/*将system_db的列元信息加入system_col*/
	setColNode(colnode, "dbname\0", "system_db\0", 2, 20, 0);
	write_row(sp, colNodeToRow(colnode));

	/*将system_table的列元信息加入system_col*/
	setColNode(colnode, "tablename\0", "system_table\0", 2, 20, 0);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "colnum\0", "system_table\0", 1, 4, 1);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "rowlength\0", "system_table\0", 1, 4, 2);
	write_row(sp, colNodeToRow(colnode));

	/*将system_col的列元信息加入system_col*/
	setColNode(colnode, "colname\0", "system_col\0", 2, 20, 0);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "tablenum\0", "system_col\0", 2, 20, 1);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "coltype\0", "system_col\0", 1, 4, 2);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "coltypename\0", "system_col\0", 2, 5, 3);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "size\0", "system_col\0", 1, 4, 4);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "order\0", "system_col\0", 1, 4, 5);
	write_row(sp, colNodeToRow(colnode));

	close(sp);
	deleteStorageNode(sp);
	deleteColNode(colnode);
}

bool init() {
		
	if (_access("..\\SQLFile", 0) == 0) {	/* 使用WIN API判断数据库系统文件夹是否已创建 */
		//清除所有表中的无效行
		//cleanFile("..\\SQLFile\\");

		return true;
	}
	/*创建数据库系统文件夹即相关元数据表*/
	if (!mkdir() || !mkfile()) 
		return false;
	insertSYSTable();
	insertSYSCol();
	return true;
}


//对文件进行无效行的清理
void clean(char* filename, char* foldername) {
	//使用先复制后改名的方法来清理文件
	char* str = new char[100];
	strcpy(str, foldername);
	strcat(str, filename);
	FILE* fp1 = fopen(str, "rb");		//数据表文件
	char* str1 = new char[100];
	strcpy(str1, str);			//原表的表名

	strcpy(str, foldername);
	strcat(str, "temp.data");
	FILE* fp2 = fopen(str, "wb");		//临时文件
	char* str2 = new char[100];
	strcpy(str2, str);		//temp文件的表名


	//得到foldername中最末尾文件夹的名称
	int length = 0;			//数据库名的长度
	int index = strlen(foldername) - 2;			//末尾的下标.注意末尾的\\其实是一个\，另一个为转义符
	/*if (index < 0)
		return;*/
	while (foldername[index] != '\\'){
		str[length] = foldername[index];
		/* *(str+length) = *(foldername + index);	*/		//如果用数组下标形式赋值会报错，不清楚为什么
		length++;
		index--;
	}
	str[length] = '\0';
	char* folder = new char[30];		//最末尾文件夹的名称
	for (int i = 0; i < length; i++) {
		folder[i] = str[length - 1 - i];
	}
	folder[length] = '\0';


	//在表元数据表中查找表中元组的长度
	tableNodeList* list = selectDBTable(filename, folder);

	if (list->num == 0) {
		fclose(fp1);
		fclose(fp2);
		int flag = remove(str2);
		return;
	}
		
	int rowlength = list->head->rowlength +1;		//物理文件中一行的长度

	char* row = new char[rowlength];

	while (fread(row, rowlength, 1, fp1)) {//读一行数据
		if (row[0] == (bool)true)			//无效行
			;
		else
			fwrite(row, rowlength, 1, fp2);			//将有效行复制到temp.data文件中
	}
	
	//删除原文件，并将temp.data重命名
	fclose(fp1);
	fclose(fp2);
	remove(str1);		//删除
	rename(str2, str1);		//重命名



	//回收资源


	return;
}


void cleanFile(char* foldername) {		/*/ 设计foldername自带'\\'  */
	//获取当前文件夹下文件的数量等信息
	struct _finddata_t fileinfo;		//储存文件信息的结构体
	intptr_t Handle;		//文件句柄
	int count = 0;			//当前文件夹下文件的数量


	char* temp = new char[100];
	strcpy(temp, foldername);
	Handle = _findfirst(strcat(temp, "*"), &fileinfo);
	if (Handle == -1L)
		return;			//文件夹下没有文件

	/*经验，不会解释*/
	_findnext(Handle, &fileinfo);
	_findnext(Handle, &fileinfo);

	//遍历当前文件夹下的文件，若是普通文件，清理无效行；若是文件夹，递归调用
	do {	
		if (fileinfo.attrib & _A_SUBDIR  ) {		//文件夹
			strcpy(temp, foldername);
			strcat(temp, fileinfo.name);
			cleanFile(strcat(temp, "\\"));
		}
		else		//普通文件
			clean(fileinfo.name, foldername);
		
	} while (_findnext(Handle,&fileinfo)==0);


	_findclose(Handle);
	//回收资源


	return;
}


