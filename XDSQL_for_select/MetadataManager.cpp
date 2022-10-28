#include"MetadataManager.h"
#include"StorageEngine.h"
#include<stdio.h>
#include<string.h>


/* 宏定义，各个系统表物理文件中元组的长度（以字节为单位），物理文件中的数据没有'\0' */
#define DBNodeLength 20				/*库元数据表的元组长度*/
#define TableNodeLength 28			/*表元数据表的元组长度*/
#define ColNodeLength 57			/*列元数据表的元组长度*/



char* dbNodeToRow(dbNode* node) {
	char* row = new char[DBNodeLength+1];
	row[DBNodeLength] = '\0';
	memcpy_s(row, DBNodeLength, node->dbname, DBNodeLength);
	return row;
}



dbNode* rowToDBNode(char* row) {
	dbNode* node = createDBNode();

	memcpy_s(node->dbname, DBNodeLength+1 , row, DBNodeLength+1);

	return node;
}




char* tableNodeToRow(tableNode* node) {
	char* row = new char[TableNodeLength+1];
	row[TableNodeLength] = '\0';

	/*将tableNode中的各个成员的值加入字符串row*/
	memcpy_s(row, 20, node->tablename, 20);
	memcpy_s(row + 20, 4, &node->colnum, 4);	/*通过 &node->colnum 获得整数的地址，然后用memcpy_s将整数的的四个字节依次拷贝到字符串中*/
	memcpy_s(row + 24, 4, &node->rowlength, 4);

	return row;
}




tableNode* rowToTableNode(char* row) {
	tableNode* node = createTableNode();

	memcpy_s(node->tablename, 20, row, 20);
	memcpy_s(&node->colnum, 4, row + 20, 4);
	memcpy_s(&node->rowlength, 4, row + 24, 4);

	return node;
}

char* colNodeToRow(colNode* node) {
	char* row = new char[ColNodeLength+1];
	row[ColNodeLength] = '\0';

	memcpy_s(row, 20, node->colname, 20);
	memcpy_s(row + 20, 20, node->tablename, 20);
	memcpy_s(row + 40, 4, &node->coltype, 4);
	memcpy_s(row + 44, 5, node->coltypename, 5);
	memcpy_s(row + 49, 4, &node->size, 4);
	memcpy_s(row + 53, 4, &node->order, 4);

	return row;
}

colNode* rowToColNode(char* row) {
	colNode* node = createColNode();

	memcpy_s(node->colname, 20, row, 20);
	memcpy_s(node->tablename, 20, row + 20, 20);
	memcpy_s(&node->coltype, 4, row + 40, 4);
	memcpy_s(node->coltypename, 5, row + 44, 5);
	memcpy_s(&node->size, 4, row + 49, 4);
	memcpy_s(&node->order, 4, row + 53, 4);

	return node;
}

dbNode* createDBNode() {
	dbNode* node = new dbNode;
	node->dbname = new char[21];		/*字符串要比元组长度多留一个字节储存'\0'*/
	node->dbname[20] = '\0';
	node->next = NULL;

	return node;
}

tableNode* createTableNode() {
	tableNode* node = new tableNode;
	node->tablename = new char[21];
	node->tablename[20] = '\0';
	node->next = NULL;

	return node;
}

colNode* createColNode() {
	colNode* node = new colNode;
	node->colname = new char[21];
	node->colname[20] = '\0';
	node->tablename = new char[21];
	node->tablename[20] = '\0';
	node->coltypename = new char[5];
	node->coltypename[4] = '\0';
	node->next = NULL;

	return node;
}

void setDBNode(dbNode* node, char* dbname) {
	memcpy_s(node->dbname, 20, dbname, 20);
	node->next = NULL;
}

void setTableNode(tableNode* node, char* tablename, int colnum, int rowlength) {
	memcpy_s(node->tablename, 20, tablename, 20);
	node->colnum = colnum;
	node->rowlength = rowlength;
	node->next = NULL;
}

void setColNode(colNode* node, char* colname, char* tablename, int coltype, int size, int order) {
	memcpy_s(node->colname, 20, colname, 20);
	memcpy_s(node->tablename, 20, tablename, 20);
	node->coltype = coltype;
	if (coltype == 1) memcpy_s(node->coltypename, 4, "INT\0", 4);
	if (coltype == 2) memcpy_s(node->coltypename, 5, "CHAR\0", 5);
	node->size = size;
	node->order = order;
	node->next = NULL;
}

void deleteDBNode(dbNode* node) {
	delete[] node->dbname;
	delete node;
}

void deleteTableNode(tableNode* node) {
	delete[] node->tablename;
	delete node;
}

void deleteColNode(colNode* node) {
	delete[] node->colname;
	delete[] node->tablename;
	delete[] node->coltypename;
	delete node;
}

void addDBNode(dbNodeList* list, dbNode* node) {
	if (list->num == 0) 
		list->head = node;
	else 
		list->tail->next = node;

	list->tail = node;
	list->num++;
}

void addTableNode(tableNodeList* list, tableNode* node) {
	if (list->num == 0) list->head = node;
	else list->tail->next = node;

	list->tail = node;
	list->num++;
}

void addColNode(colNodeList* list, colNode* node) {
	if (list->num == 0) list->head = node;
	else list->tail->next = node;

	list->tail = node;
	list->num++;
}

void deleteDBNodeList(dbNodeList* list) {
	int i;
	dbNode* node;


	for (i = 0; i < list->num; i++) {
		node = list->head;
		list->head = list->head->next;
		deleteDBNode(node);
	}
	delete list;
}

void deleteTableNodeList(tableNodeList* list) {
	int i;
	tableNode* node;

	for (i = 0; i < list->num; i++) {
		node = list->head;
		list->head = list->head->next;
		deleteTableNode(node);
	}
	delete list;
}

void deleteColNodeList(colNodeList* list) {
	int i;
	colNode* node;

	for (i = 0; i < list->num; i++) {
		node = list->head;
		list->head = list->head->next;
		deleteColNode(node);
	}
	delete list;
}

void appendTableNodeList(tableNodeList* list1, tableNodeList* list2) {
	/*list1或list2链表为空的特殊情况*/
	if (list2->num == 0) return;
	if (list1->num == 0) {
		list1->head = list2->head;
		list1->tail = list2->tail;
		list1->num = list2->num;
		return;
	}

	/*一般情况*/
	list1->tail->next = list2->head;
	list1->tail = list2->tail;
	list1->num += list2->num;
	return;
}

void appendColNodeList(colNodeList* list1, colNodeList* list2) {
	if (list2->num == 0) return;
	if (list1->num == 0) {
		list1->head = list2->head;
		list1->tail = list2->tail;
		list1->num = list2->num;
		return;
	}
	list1->tail->next = list2->head;
	list1->tail = list2->tail;
	list1->num += list2->num;
	return;
}

bool insertDB(dbNode* node) {
	/*创建文件节点，打开系统的库元数据表*/
	storageNode* sp = createStorageNode();
	open(sp, "system_db", DBNodeLength);
	if (sp->fp == NULL) {
		printf("open system_db error");
		return false;
	}

	/*向库元数据表中写入一行新的数据*/
	if (!write_row(sp, dbNodeToRow(node))) {
		printf("insert system_db error");
		return false;
	}

	/*关闭物理文件*/
	close(sp);

	/*删除文件节点*/
	deleteStorageNode(sp);

	return true;
}

bool deleteDB(char* dbname) {
	/*创建文件结构体，打开系统库元数据表*/
	storageNode* sp = createStorageNode();
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return false;
	}

	/*初始化文件读写指针*/
	rnd_init(sp);
	/*循环以在文件中找到指定的数据库信息所在行*/
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);		/*在文件中读取一行数据*/
		if (row == NULL) 
			continue;			/*物理文件中的行标志位被置为true，即已删除*/

		/*在有效行中寻找所需的数据行*/
		dbNode* node = rowToDBNode(row);		
		if (strcmp(node->dbname, dbname) == 0) {
			delete_row(sp);		/*命中并执行删除*/
			break;				/*退出循环*/
		}
		deleteDBNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

dbNodeList* selectDB(char* dbname) {
	
	storageNode* sp = createStorageNode();		/* 创建文件结构体sp */
	dbNodeList* nodelist = new dbNodeList;		/* 创建dnNodeList链表 */
	
	/*打开系统库元数据表*/
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return nodelist;
	}

	rnd_init(sp);		/*初始化文件读写指针*/

	
	/* 遍历库元数据表的物理文件查找目标数据库 */
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;

		/*在有效行中查找*/
		dbNode* node = rowToDBNode(row);
		if (dbname == NULL||strcmp(node->dbname, dbname) == 0) 
			addDBNode(nodelist,node);			/*将目标dbNode节点加入链表*/
		
	}

	close(sp);
	deleteStorageNode(sp);
	return nodelist;			/*使用链表储存找到的数据库节点，并将链表返回*/
}

bool updateDB(dbNode* newNode) {
	storageNode* sp = createStorageNode();			/*创建文件结构体*/
	
	/*打开库元数据表文件*/
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return false;
	}

	rnd_init(sp);
	/*遍历文件来找到目标行*/
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;

		dbNode* node = rowToDBNode(row);
		if (strcmp(node->dbname, newNode->dbname) == 0) 
			update_row(sp,dbNodeToRow(newNode));			/*使用newnode中的信息对目标行进行更新*/
		deleteDBNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

bool createDBTable(char* dbname) {	
	char* filename;
	if(dbname!=NULL)
		filename = stringcat(dbname, "\\system_table");			/*构造表元数据表的路径*/
	else 
		filename = "system_table";		/*若未指定数据库，则该表元数据表储存系统表的信息*/

	return create(filename);		/*创建文件*/
}

bool insertDBTable(tableNode* node, char* dbname) {
	storageNode* sp = createStorageNode();		/*创建文件节点*/
	char* filename = stringcat(dbname, "\\system_table");		/*构造文件路径*/
	open(sp, filename, TableNodeLength);		/*打开文件*/

	if (sp->fp == NULL) {
		printf("open system_table error");
		return false;
	}

	/*向表元数据表末尾写入一行数据*/
	if (!write_row(sp, tableNodeToRow(node))) {
		printf("insert system_table error");
		return false;
	}

	close(sp);
	deleteStorageNode(sp);

	return true;
}

bool deleteDBTable(char* tablename, char* dbname) {
	/*打开表元数据表*/
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_table");
	open(sp, filename, TableNodeLength);
	if (sp->fp == NULL) {
		printf("open system_table error");
		return false;
	}

	rnd_init(sp);
	/*遍历文件找到目标行*/
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;
		tableNode* node = rowToTableNode(row);
		if (strcmp(node->tablename, tablename) == 0) 
			delete_row(sp);
		deleteTableNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

tableNodeList* selectDBTable(char* tablename, char* dbname) {
	storageNode* sp = createStorageNode();
	tableNodeList* nodelist = new tableNodeList;
	char* filename;
	if (dbname != NULL)			/*属于数据库的表元数据表*/
		filename = stringcat(dbname, "\\system_table");
	else		/*属于系统的表元数据表*/
		filename = "system_table";
	open(sp, filename, TableNodeLength);
	if (sp->fp == NULL) {
		printf("open system_table error");
		return nodelist;
	}

	rnd_init(sp);
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;
		tableNode* node = rowToTableNode(row);
		if (tablename == NULL || strcmp(node->tablename, tablename) == 0) 
			addTableNode(nodelist, node);
		//deleteTableNode(node); 由于节点作为返回值传出，故不删除节点。
	}

	close(sp);
	deleteStorageNode(sp);
	return nodelist;
}

bool updateDBTable(tableNode* newNode, char* dbname) {
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_table");
	open(sp, filename, TableNodeLength);
	if (sp->fp == NULL) {
		printf("open system_table error");
		return false;
	}

	rnd_init(sp);
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;

		tableNode* node = rowToTableNode(row);
		if (strcmp(node->tablename,newNode->tablename) == 0) 
			update_row(sp,tableNodeToRow(newNode));
		deleteTableNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

bool dropDBTable(char* dbname) {
	char* filename = stringcat(dbname, "\\system_table");
	return drop(filename);
}

bool createTableCol(char* dbname) {
	char* filename;
	if (dbname != NULL)
		filename = stringcat(dbname, "\\system_col");
	else 
		filename = "system_col";
	return create(filename);
}

bool insertTableCol(colNodeList* list, char* dbname) {
	/*打开列元数据表*/
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_col");
	open(sp, filename, ColNodeLength);
	if (sp->fp == NULL) {
		printf("open system_col error");
		return false;
	}

	colNode* node = list->head;			/*可能一次会插入多个列*/
	int i = 0;
	/*将链表中所有的行都插入列元数据表*/
	for (i = 0; i < list->num; i++) {
		if (!write_row(sp, colNodeToRow(node))) {
			printf("insert system_col error");
			return false;
		}
		node = node->next;
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

bool deleteTableCol(char* tablename, char* dbname) {
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_col");
	open(sp, filename, ColNodeLength);
	if (sp->fp == NULL) {
		printf("open system_col error");
		return false;
	}
		
	rnd_init(sp);
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;
		colNode* node = rowToColNode(row);
		if (strcmp(node->tablename, tablename) == 0) 
			delete_row(sp);
		deleteColNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

colNodeList* selectTableCol(char* tablename, char* dbname) {
	storageNode* sp = createStorageNode();
	colNodeList* nodelist = new colNodeList;

	/* 获取列元系统表的文件名 */
	char* filename;
	if (dbname != NULL)
		filename = stringcat(dbname, "\\system_col");
	else 
		filename = "system_col";

	/*打开文件*/
	open(sp, filename, ColNodeLength);			
	if (sp->fp == NULL) {
		printf("open system_col error");
		return nodelist;
	}

	rnd_init(sp);
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;
		colNode* node = rowToColNode(row);
		if (strcmp(node->tablename, tablename) == 0) 
			addColNode(nodelist, node);
		//deleteColNode(node); 由于节点作为返回值传出，故不删除节点。
	}

	close(sp);
	deleteStorageNode(sp);
	return nodelist;
}

bool dropTableCol(char* dbname) {
	char* filename = stringcat(dbname, "\\system_col");
	return drop(filename);
}