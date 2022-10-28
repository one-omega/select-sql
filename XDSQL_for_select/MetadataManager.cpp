#include"MetadataManager.h"
#include"StorageEngine.h"
#include<stdio.h>
#include<string.h>


/* �궨�壬����ϵͳ�������ļ���Ԫ��ĳ��ȣ����ֽ�Ϊ��λ���������ļ��е�����û��'\0' */
#define DBNodeLength 20				/*��Ԫ���ݱ��Ԫ�鳤��*/
#define TableNodeLength 28			/*��Ԫ���ݱ��Ԫ�鳤��*/
#define ColNodeLength 57			/*��Ԫ���ݱ��Ԫ�鳤��*/



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

	/*��tableNode�еĸ�����Ա��ֵ�����ַ���row*/
	memcpy_s(row, 20, node->tablename, 20);
	memcpy_s(row + 20, 4, &node->colnum, 4);	/*ͨ�� &node->colnum ��������ĵ�ַ��Ȼ����memcpy_s�������ĵ��ĸ��ֽ����ο������ַ�����*/
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
	node->dbname = new char[21];		/*�ַ���Ҫ��Ԫ�鳤�ȶ���һ���ֽڴ���'\0'*/
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
	/*list1��list2����Ϊ�յ��������*/
	if (list2->num == 0) return;
	if (list1->num == 0) {
		list1->head = list2->head;
		list1->tail = list2->tail;
		list1->num = list2->num;
		return;
	}

	/*һ�����*/
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
	/*�����ļ��ڵ㣬��ϵͳ�Ŀ�Ԫ���ݱ�*/
	storageNode* sp = createStorageNode();
	open(sp, "system_db", DBNodeLength);
	if (sp->fp == NULL) {
		printf("open system_db error");
		return false;
	}

	/*���Ԫ���ݱ���д��һ���µ�����*/
	if (!write_row(sp, dbNodeToRow(node))) {
		printf("insert system_db error");
		return false;
	}

	/*�ر������ļ�*/
	close(sp);

	/*ɾ���ļ��ڵ�*/
	deleteStorageNode(sp);

	return true;
}

bool deleteDB(char* dbname) {
	/*�����ļ��ṹ�壬��ϵͳ��Ԫ���ݱ�*/
	storageNode* sp = createStorageNode();
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return false;
	}

	/*��ʼ���ļ���дָ��*/
	rnd_init(sp);
	/*ѭ�������ļ����ҵ�ָ�������ݿ���Ϣ������*/
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);		/*���ļ��ж�ȡһ������*/
		if (row == NULL) 
			continue;			/*�����ļ��е��б�־λ����Ϊtrue������ɾ��*/

		/*����Ч����Ѱ�������������*/
		dbNode* node = rowToDBNode(row);		
		if (strcmp(node->dbname, dbname) == 0) {
			delete_row(sp);		/*���в�ִ��ɾ��*/
			break;				/*�˳�ѭ��*/
		}
		deleteDBNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

dbNodeList* selectDB(char* dbname) {
	
	storageNode* sp = createStorageNode();		/* �����ļ��ṹ��sp */
	dbNodeList* nodelist = new dbNodeList;		/* ����dnNodeList���� */
	
	/*��ϵͳ��Ԫ���ݱ�*/
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return nodelist;
	}

	rnd_init(sp);		/*��ʼ���ļ���дָ��*/

	
	/* ������Ԫ���ݱ�������ļ�����Ŀ�����ݿ� */
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;

		/*����Ч���в���*/
		dbNode* node = rowToDBNode(row);
		if (dbname == NULL||strcmp(node->dbname, dbname) == 0) 
			addDBNode(nodelist,node);			/*��Ŀ��dbNode�ڵ��������*/
		
	}

	close(sp);
	deleteStorageNode(sp);
	return nodelist;			/*ʹ���������ҵ������ݿ�ڵ㣬����������*/
}

bool updateDB(dbNode* newNode) {
	storageNode* sp = createStorageNode();			/*�����ļ��ṹ��*/
	
	/*�򿪿�Ԫ���ݱ��ļ�*/
	if (!open(sp, "system_db", DBNodeLength)) {
		printf("open system_db error");
		return false;
	}

	rnd_init(sp);
	/*�����ļ����ҵ�Ŀ����*/
	while (!isEOF(sp))
	{
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;

		dbNode* node = rowToDBNode(row);
		if (strcmp(node->dbname, newNode->dbname) == 0) 
			update_row(sp,dbNodeToRow(newNode));			/*ʹ��newnode�е���Ϣ��Ŀ���н��и���*/
		deleteDBNode(node);
	}

	close(sp);
	deleteStorageNode(sp);
	return true;
}

bool createDBTable(char* dbname) {	
	char* filename;
	if(dbname!=NULL)
		filename = stringcat(dbname, "\\system_table");			/*�����Ԫ���ݱ��·��*/
	else 
		filename = "system_table";		/*��δָ�����ݿ⣬��ñ�Ԫ���ݱ���ϵͳ�����Ϣ*/

	return create(filename);		/*�����ļ�*/
}

bool insertDBTable(tableNode* node, char* dbname) {
	storageNode* sp = createStorageNode();		/*�����ļ��ڵ�*/
	char* filename = stringcat(dbname, "\\system_table");		/*�����ļ�·��*/
	open(sp, filename, TableNodeLength);		/*���ļ�*/

	if (sp->fp == NULL) {
		printf("open system_table error");
		return false;
	}

	/*���Ԫ���ݱ�ĩβд��һ������*/
	if (!write_row(sp, tableNodeToRow(node))) {
		printf("insert system_table error");
		return false;
	}

	close(sp);
	deleteStorageNode(sp);

	return true;
}

bool deleteDBTable(char* tablename, char* dbname) {
	/*�򿪱�Ԫ���ݱ�*/
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_table");
	open(sp, filename, TableNodeLength);
	if (sp->fp == NULL) {
		printf("open system_table error");
		return false;
	}

	rnd_init(sp);
	/*�����ļ��ҵ�Ŀ����*/
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
	if (dbname != NULL)			/*�������ݿ�ı�Ԫ���ݱ�*/
		filename = stringcat(dbname, "\\system_table");
	else		/*����ϵͳ�ı�Ԫ���ݱ�*/
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
		//deleteTableNode(node); ���ڽڵ���Ϊ����ֵ�������ʲ�ɾ���ڵ㡣
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
	/*����Ԫ���ݱ�*/
	storageNode* sp = createStorageNode();
	char* filename = stringcat(dbname, "\\system_col");
	open(sp, filename, ColNodeLength);
	if (sp->fp == NULL) {
		printf("open system_col error");
		return false;
	}

	colNode* node = list->head;			/*����һ�λ��������*/
	int i = 0;
	/*�����������е��ж�������Ԫ���ݱ�*/
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

	/* ��ȡ��Ԫϵͳ����ļ��� */
	char* filename;
	if (dbname != NULL)
		filename = stringcat(dbname, "\\system_col");
	else 
		filename = "system_col";

	/*���ļ�*/
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
		//deleteColNode(node); ���ڽڵ���Ϊ����ֵ�������ʲ�ɾ���ڵ㡣
	}

	close(sp);
	deleteStorageNode(sp);
	return nodelist;
}

bool dropTableCol(char* dbname) {
	char* filename = stringcat(dbname, "\\system_col");
	return drop(filename);
}