#include"MetadataManager.h"
#include"StorageEngine.h"
#include"InitSQL.h"
#include<stdio.h>
#include<Windows.h>
#include<io.h>

bool mkdir() {
	return CreateDirectory("..\\SQLFile", NULL);		/*�������ݿ�ϵͳ���ļ���*/
}

bool mkfile() {
	FILE* fp;

	/*�򿪿�Ԫ���ݱ��������ھʹ�����Ԫ���ݱ�*/
	fopen_s(&fp, "..\\SQLFile\\system_db", "wb");
	if (fp == NULL) 
		return false;
	fclose(fp);
	
	/*������ϵͳ�ı�Ԫ���ݱ��������ھʹ����ļ�*/
	fopen_s(&fp, "..\\SQLFile\\system_table", "wb");
	if (fp == NULL) 
		return false;
	fclose(fp);

	/*������ϵͳ����Ԫ���ݱ��������ھʹ����ļ�*/
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

	/*��system_db���м���������*/
	setTableNode(tablenode, "system_db\0", 1, 20);		/* system_db�����Ϣ */
	write_row(sp, tableNodeToRow(tablenode));
	setTableNode(tablenode, "system_table\0", 3, 28);	/* system_table�����Ϣ */
	write_row(sp, tableNodeToRow(tablenode));
	setTableNode(tablenode, "system_col\0", 6, 57);		/* system_col�����Ϣ */
	write_row(sp, tableNodeToRow(tablenode));

	close(sp);
	deleteStorageNode(sp);
	deleteTableNode(tablenode);
}

void insertSYSCol() {
	colNode* colnode = createColNode();
	storageNode* sp = createStorageNode();
	open(sp, "system_col", 57);
	
	/*��system_db����Ԫ��Ϣ����system_col*/
	setColNode(colnode, "dbname\0", "system_db\0", 2, 20, 0);
	write_row(sp, colNodeToRow(colnode));

	/*��system_table����Ԫ��Ϣ����system_col*/
	setColNode(colnode, "tablename\0", "system_table\0", 2, 20, 0);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "colnum\0", "system_table\0", 1, 4, 1);
	write_row(sp, colNodeToRow(colnode));
	setColNode(colnode, "rowlength\0", "system_table\0", 1, 4, 2);
	write_row(sp, colNodeToRow(colnode));

	/*��system_col����Ԫ��Ϣ����system_col*/
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
		
	if (_access("..\\SQLFile", 0) == 0) {	/* ʹ��WIN API�ж����ݿ�ϵͳ�ļ����Ƿ��Ѵ��� */
		//������б��е���Ч��
		//cleanFile("..\\SQLFile\\");

		return true;
	}
	/*�������ݿ�ϵͳ�ļ��м����Ԫ���ݱ�*/
	if (!mkdir() || !mkfile()) 
		return false;
	insertSYSTable();
	insertSYSCol();
	return true;
}


//���ļ�������Ч�е�����
void clean(char* filename, char* foldername) {
	//ʹ���ȸ��ƺ�����ķ����������ļ�
	char* str = new char[100];
	strcpy(str, foldername);
	strcat(str, filename);
	FILE* fp1 = fopen(str, "rb");		//���ݱ��ļ�
	char* str1 = new char[100];
	strcpy(str1, str);			//ԭ��ı���

	strcpy(str, foldername);
	strcat(str, "temp.data");
	FILE* fp2 = fopen(str, "wb");		//��ʱ�ļ�
	char* str2 = new char[100];
	strcpy(str2, str);		//temp�ļ��ı���


	//�õ�foldername����ĩβ�ļ��е�����
	int length = 0;			//���ݿ����ĳ���
	int index = strlen(foldername) - 2;			//ĩβ���±�.ע��ĩβ��\\��ʵ��һ��\����һ��Ϊת���
	/*if (index < 0)
		return;*/
	while (foldername[index] != '\\'){
		str[length] = foldername[index];
		/* *(str+length) = *(foldername + index);	*/		//����������±���ʽ��ֵ�ᱨ�������Ϊʲô
		length++;
		index--;
	}
	str[length] = '\0';
	char* folder = new char[30];		//��ĩβ�ļ��е�����
	for (int i = 0; i < length; i++) {
		folder[i] = str[length - 1 - i];
	}
	folder[length] = '\0';


	//�ڱ�Ԫ���ݱ��в��ұ���Ԫ��ĳ���
	tableNodeList* list = selectDBTable(filename, folder);

	if (list->num == 0) {
		fclose(fp1);
		fclose(fp2);
		int flag = remove(str2);
		return;
	}
		
	int rowlength = list->head->rowlength +1;		//�����ļ���һ�еĳ���

	char* row = new char[rowlength];

	while (fread(row, rowlength, 1, fp1)) {//��һ������
		if (row[0] == (bool)true)			//��Ч��
			;
		else
			fwrite(row, rowlength, 1, fp2);			//����Ч�и��Ƶ�temp.data�ļ���
	}
	
	//ɾ��ԭ�ļ�������temp.data������
	fclose(fp1);
	fclose(fp2);
	remove(str1);		//ɾ��
	rename(str2, str1);		//������



	//������Դ


	return;
}


void cleanFile(char* foldername) {		/*/ ���foldername�Դ�'\\'  */
	//��ȡ��ǰ�ļ������ļ�����������Ϣ
	struct _finddata_t fileinfo;		//�����ļ���Ϣ�Ľṹ��
	intptr_t Handle;		//�ļ����
	int count = 0;			//��ǰ�ļ������ļ�������


	char* temp = new char[100];
	strcpy(temp, foldername);
	Handle = _findfirst(strcat(temp, "*"), &fileinfo);
	if (Handle == -1L)
		return;			//�ļ�����û���ļ�

	/*���飬�������*/
	_findnext(Handle, &fileinfo);
	_findnext(Handle, &fileinfo);

	//������ǰ�ļ����µ��ļ���������ͨ�ļ���������Ч�У������ļ��У��ݹ����
	do {	
		if (fileinfo.attrib & _A_SUBDIR  ) {		//�ļ���
			strcpy(temp, foldername);
			strcat(temp, fileinfo.name);
			cleanFile(strcat(temp, "\\"));
		}
		else		//��ͨ�ļ�
			clean(fileinfo.name, foldername);
		
	} while (_findnext(Handle,&fileinfo)==0);


	_findclose(Handle);
	//������Դ


	return;
}


