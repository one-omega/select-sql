#include"QueryProcessor.h"
#include "StorageClass.h"		//������queryprocessor.hͷ�ļ������� WHY?

//using namespace std;

char* usedatabase;			/*��ǰʹ�õ����ݿ�*/

void setUseDB(char* dbname) {
//	if (usedatabase != NULL) delete[] usedatabase;
	usedatabase = new char[strlen(dbname)+1];
	strcpy_s(usedatabase, strlen(dbname)+1, dbname);
}

char* dbnameADDtablename(char* dbname, char* tablename) {
	char* fileend = stringcat("\\", tablename);
	char* filename = stringcat(dbname, fileend);
	return filename;
}

bool isMateDataTable(char* tablename) {
	if (strcmp("system_db", tablename) == 0 
		|| strcmp("system_table", tablename) == 0
		|| strcmp("system_col", tablename) == 0 )
		return true;
	else
		return false;
}

void setColInColData(coldatanode* coldatanode, colNode* colnode) {
	coldatanode->colname = colnode->colname;
	coldatanode->tablename = colnode->tablename;
	coldatanode->coltype = colnode->coltype;
	coldatanode->size = colnode->size;
	coldatanode->data = new char[colnode->size];
	coldatanode->data[0] = '\0';
}

void setDataInColData(coldatanode* coldatanode, char* data) {
	memcpy_s(coldatanode->data, coldatanode->size, data, coldatanode->size);
}

void colListToDataArray(colNodeList* list, coldatanode* dataarray) {
	colNode* node = list->head;
	for (int i = 0; i < list->num; i++) {
		setColInColData(dataarray+i, node);		/*�������е�i+1��Ԫ�ش���*/
		node = node->next;
	}
}

void colDataToRow(coldatanode* dataarray, int arraynum, char* row) {
	int offset = 0;
	for (int i = 0; i < arraynum; i++) {
		memcpy_s(row+offset, dataarray[i].size, dataarray[i].data, dataarray[i].size);
		offset += dataarray[i].size;
	}
}

void rowToColData(char* row, coldatanode* dataarray, int arraynum) {
	int i;
	int offset = 0;		/*�ֽ�����ƫ����*/
	for (i = 0; i < arraynum; i++) {
		setDataInColData(dataarray + i, row + offset);
		offset += dataarray[i].size;
	}
}

bool isExistDB(char* dbname) {
	bool isExist;
	dbNodeList* list = selectDB(dbname);
	
	if (list->num == 0) 
		isExist = false;
	else 
		isExist = true;

	deleteDBNodeList(list);
	return isExist;
}

void createDB(char* dbname) {}

void dropDB(char* dbname) {}

void useDB(char* dbname) {
	if (!isExistDB(dbname)) {
		printf("%s is not Exist", dbname);
		return;
	}

	setUseDB(dbname);
	printf("use %s", dbname);
	return;
}

void showDB() {
	dbNodeList* dbnodelist = selectDB(NULL);
	/* ������ݿ����� */
	printf("dbname��\n");

	dbNode* dbnode = dbnodelist->head;
	for (int i = 0; i < dbnodelist->num; i++) {
		printf("%s\n", dbnode->dbname);
		dbnode = dbnode->next;
	}
	printf("total %d databases", dbnodelist->num);
	return;
}

void showTable() {
	tableNodeList* tablelist = selectDBTable(NULL, usedatabase);

	/* ������� */
	printf("tablename\tcolnum\trowlength\n");

	tableNode* tablenode = tablelist->head;
	for (int i = 0; i < tablelist->num; i++) {
		printf("%s\t%d\t%d\n", tablenode->tablename, tablenode->colnum, tablenode->rowlength);
		tablenode = tablenode->next;
	}
	printf("total %d tables", tablelist->num);
	return;
}

bool isExistTable(char* tablename) {
	bool isExist;
	tableNodeList* list = selectDBTable(tablename,usedatabase);

	if (list->num == 0) 
		isExist = false;
	else 
		isExist = true;

	deleteTableNodeList(list);

	return isExist;
}

void createTable(struct createTablesql* createTablesql) {}

void dropTable(char* tablename) {}

void insert(struct insertsql* insertsql) {}

void tablejoin(tableNode* tablenode, char* row, int index, storageNode* sp) {
	//sp������temp��ʱ����Ϣ�Ľṹ��
	//tablenode����һ����ı�Ԫ��Ϣ�ڵ�


	tableNode* firstnode = tablenode;
	//��һ���û����ݱ�ı������������·����
	char* firstfilename = dbnameADDtablename(usedatabase, firstnode->tablename);
	storageNode* firstsp = createStorageNode();		//�����һ���û����ݱ���Ϣ�Ľṹ��
	open(firstsp, firstfilename, firstnode->rowlength);
	rnd_init(firstsp);


	//�Ե�һ���û����ݱ��е�ÿһ��Ԫ�飬���򿪵ڶ������ȡ����Ԫ�鲢ƴ�ӣ������д��temp��ʱ��
	while (!isEOF(firstsp)) {
		char* first_row = rnd_next(firstsp);		//��ȡ��һ�����һ��Ԫ��
		if (first_row == NULL) //��ȡ����ɾ�����ݣ����ؿ�ֵ
			continue;

		//����һ�ű�һ�����ݷ���row������
		memcpy_s(row+index, firstnode->rowlength, first_row, firstnode->rowlength); 
		
		if (firstnode->next != NULL) {
			tablejoin(firstnode->next, row, index+firstnode->rowlength, sp);
		}
		else {
/*
			//�ڶ�����ı�Ԫ��Ϣ�ڵ�
			tableNode* secondnode = firstnode->next;
			char* secondfilename = dbnameADDtablename(usedatabase, secondnode->tablename);
			storageNode* secondsp = createStorageNode();
			open(secondsp, secondfilename, secondnode->rowlength);
			rnd_init(secondsp);
			//�����ڶ��������е�Ԫ�飬������һ������ѡ�е�Ԫ��ƴ��
			while (!isEOF(secondsp)) {
				char* second_row = rnd_next(secondsp);
				if (second_row == NULL)
					continue;
				memcpy_s(row + firstnode->rowlength, secondnode->rowlength, second_row, secondnode->rowlength);
				//���ڶ��ű��һ��������ӵ�row����ĩβ
*/
				write_row(sp, row);
//			}
//			close(secondsp);
//			deleteStorageNode(secondsp);
		}
	}

	/* ������� */
	close(firstsp);
	deleteStorageNode(firstsp);
}

tableNode* generateTempTable(tableNodeList* tablelist) {
	/* ������ʱ�� */
	char tablename[] = "temp";
	char* filename = dbnameADDtablename(usedatabase, tablename);
	if (!create(filename)) {
		printf("create temp error");
		return NULL;
	}

	/* ��ʼ����ʱ��tablenode�����������г��� */
	tableNode* tablenode = createTableNode();		/*������ʱ��ڵ�*/
	setTableNode(tablenode, tablename, 0, 0);		
	tableNode* node = tablelist->head;
	for (int i = 0; i < tablelist->num; i++) {		/*������ʱ����������г���*/
		tablenode->colnum += node->colnum;
		tablenode->rowlength += node->rowlength;
		node = node->next;
	}

	/* �������ڼ�¼�ѿ�������Ԫ����ֽ�����row,������ʱ�� */
	char* row = new char[tablenode->rowlength];
	storageNode* sp = createStorageNode();
	open(sp, filename, tablenode->rowlength);

	/* ���õѿ��������� */
	tablejoin(tablelist->head, row, 0, sp);

	/* ������� */
	close(sp);
	deleteStorageNode(sp);


	return tablenode;
}

bool deleteTempTable() {
	char tablename[] = "temp";
	char* filename = dbnameADDtablename(usedatabase, tablename);
	if (!drop(filename)) {
		printf("drop temp error");
		return false;
	}
	return true;
}

int selectColname(char* tablename, char* colname, coldatanode* datanodearray, int arraynum) {
	int i;			/*datanodearray������±�*/
	int num = 0;	/*���е�datanodearray����Ԫ�صĸ���*/
	int index;		/*������Ӧ��datanodearray����Ԫ�ص��±�*/
	for (i = 0; i < arraynum; i++) {
		if (tablename == NULL || strcmp(tablename,datanodearray[i].tablename)==0) {
			if (strcmp(colname, datanodearray[i].colname) == 0) {
				num++;
				index = i;
			}
		}
	}

	switch (num) {
		case 0: printf("can't find col"); return -1;
		case 1: return index;
		default: printf("have more cols"); return -1;
	}
}

bool conditionLinkData(struct condition* conditions, coldatanode* datanodearray, int arraynum) {return false;}

bool checkconditions(struct condition* conditions) { return false; }

void showcolname(char* tablename, char* colname) {
	if (tablename != NULL) 
		printf("%s.", tablename);
	printf("%s\t", colname);
}


bool dealcalcondition(struct condition* condition) { return false; }

bool dealstringcondition(struct condition* condition) { return false; }

bool dealconditions(struct condition* conditions) { return false; }

void showcoldata(coldatanode* dataarray, int* showorder, int shownum) {
	int i;
	for (i = 0; i < shownum; i++) {
		int j = showorder[i];
		/* ���ֵΪ��ʱ���NULL */
		if (dataarray[j].data[0] == '\0') {
			printf("NULL\t");
			continue;
		}
		switch (dataarray[j].coltype) {
			case 1: printf("%d\t", *(int*)dataarray[j].data); break;
			case 2: printf("%s\t", dataarray[j].data); break;
		}
	}
	printf("\n");
}

void select(struct selectsql* selectsql) {
	/* �ж��Ƿ�use database������bug�������ѯsystem_db������Ҫuse database����ʵ���е��鷳����δ�޸� */
	if (usedatabase == NULL ) {
		printf("error: not use database");
		return;
	}

	/* ��ȡ��ѯ��Ԫ���ݣ����ж����ݱ��Ƿ���� */
	struct tablecol* tables = selectsql->tables;
	struct tableNodeList* tablelist = new struct tableNodeList;		/*��Ԫ��Ϣ����*/

	/*�õ����д���ѯ��ı�Ԫ��Ϣ*/
	while (tables != NULL)
	{
		struct tableNodeList* list;
		
		/*�жϴ���ѯ�ı��Ƿ�Ϊϵͳ��*/
		if (isMateDataTable(tables->tablename))		/* Ԫ���ݱ��Ԫ������Ϣ����Ҫ��usedatabasename */
			list = selectDBTable(tables->tablename, NULL);
		else 
			list = selectDBTable(tables->tablename, usedatabase);
		if (list->num == 0) {
			printf("table not exist");
			return;
		}
		appendTableNodeList(tablelist, list);	/*����Ԫ��Ϣ������tablelist������*/
		tables = tables->next;
		delete list;
	}
	
	/* �ж����ݱ�����������һ�ű�ʱ�Զ��ű���еѿ����� */
	tableNode* tablenode;		/*��ѯ�������õ��ı�*/
	if (tablelist->num > 1) {
//		if (tablelist->num > 2) {
//			printf("error: the number of tables is not more than 2");
//			return;
//		}
		tablenode = generateTempTable(tablelist);
	}
	else 
		tablenode = tablelist->head;
	
	/* ��ȡ��Ԫ���� */
	struct colNodeList* collist = new struct colNodeList;	/*collist������Ԫ���ݹ��������ص���Ԫ��Ϣ*/
	struct tableNode* node = tablelist->head;
	for (int i = 0; i < tablelist->num; i++) {
		struct colNodeList* list;
		/* Ԫ���ݱ��Ԫ������Ϣ����Ҫ��usedatabasename */
		if (isMateDataTable(node->tablename)) 
			list = selectTableCol(node->tablename, NULL);
		else 
			list = selectTableCol(node->tablename, usedatabase);
		appendColNodeList(collist, list);		/*����ѯ������Ԫ��Ϣ���浽������*/
		delete list;
		node = node->next;
	}
	if (collist->num != tablenode->colnum) {
		printf("get metadata error");
		return;
	}

	/* �������������飬������Ԫ���ݽṹ */
	coldatanode* dataarray = new coldatanode[collist->num];	/*dataarray������������*/
	colListToDataArray(collist, dataarray);

	/*������ѯ*/
	if (selectsql->whereconf != NULL) {
		/* ����where����ʱ����where��tablecol��coldatanode�󶨣�ͬʱ�ж�tablecol�Ƿ񲻴��ڻ����ظ� */
		if (!conditionLinkData(selectsql->whereconf, dataarray, collist->num)) 
			return;
		/* �ж�where�����ڱȽ������Ƿ���ͬ */
		if (!checkconditions(selectsql->whereconf))
			return;
	}

	/* �жϲ�ѯ������������Ʋ����ڻ������ظ����������¼��˳�� */

	/*�ڵ�һ�������������ͨ������������showorder����*/
	int* showorder = new int[collist->num * 2];  /*showorder,��¼ָ��������м���˳�򣬴�СĬ��Ϊcoldatanode������2��*/
	int shownum = 0;
	if (selectsql->tablecolconf->isALL == 0) {	/*ѡ��ȫ���У�����˳�����ȫ����*/
		for (int i = 0; i < collist->num; i++) {
			if (tablelist->num == 1)	/*�����ѯ*/
				showcolname(NULL, dataarray[i].colname);	
			else						/*����ѯ*/
				showcolname(dataarray[i].tablename, dataarray[i].colname);	/*�������ʱҪ�������ݿ�����*/
			showorder[i] = i;
			shownum++;
		}
	}
	else {	/*ѡ�񲿷��У���������ѯ*/
		struct tablecol* cols = selectsql->tablecolconf->tablecols;		/*cols��select����Ҫ���������*/
		int index;		/*��������dataarray�����������е��±�*/
		while(cols != NULL) {
			index = selectColname(cols->tablename, cols->colname, dataarray, collist->num);
			if (index == -1) 
				return;
			showcolname(cols->tablename, cols->colname);	/*�������*/
			showorder[shownum] = index;			/*���е��±����showorder����*/
			shownum++;
			cols = cols->next;
		}
	}

	printf("\n");

	
	char* filename;
	/* ���ݿ�Ԫ���ݱ��ڸ�Ŀ¼�£�����Ҫ�ڱ���ǰ��usedatabase���� */
	if (strcmp("system_db", tablenode->tablename) == 0) 
		filename = tablenode->tablename;
	else 
		filename = dbnameADDtablename(usedatabase, tablenode->tablename);
	
	/* �򿪱� */
	storageNode* sp = createStorageNode();
	if (!open(sp, filename, tablenode->rowlength)) {
		printf("open table error");
		return;
	}
	rnd_init(sp);
	int num = 0;

	/*�������ݱ�*/
	while (!isEOF(sp)) {
		/* ��ȡһ�����ݣ�������dataarray������ */
		char* row = rnd_next(sp);
		if (row == NULL) 
			continue;
		rowToColData(row, dataarray,collist->num);

	    /* ִ��where�����жϣ�whereΪ��ʱ����ָ������� */
		if (selectsql->whereconf == NULL || dealconditions(selectsql->whereconf)) {
			showcoldata(dataarray, showorder, shownum);
			num++;
		}
	}
	printf("Total row: %d", num);

	/* �رձ� */
	close(sp);
	deleteStorageNode(sp);

	/* ��ʱ����ɾ���� */
	if (tablelist->num > 1) deleteTempTable();

	/* ������� */
	delete[] dataarray;
	delete[] showorder;
	deleteColNodeList(collist);
	deleteTableNodeList(tablelist);

	return;
}


void updatesetconf(struct setconf* setconfs) {}

void update(struct updatesql* updatesql) {}

void deletetable(struct deletesql* deletesql) {}