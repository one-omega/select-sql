#include "StorageEngine.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>


/* ����·��ǰ׺��ʹ�����·�������ݿ�ϵͳ�������ļ�������SQLFileĿ¼�� */
char filePrefix[] = "..\\SQLFile\\";


char* stringcat(char* first, char* second) {
	int length;
	length = strlen(first) + strlen(second) + 1;
	char* newString = new char[length];
	strcpy_s(newString, length, first);
	//newString[strlen(first)] = '\0';
	strcat_s(newString, length, second);
	newString[length] = '\0';
	return newString;
}

storageNode* createStorageNode() {
	storageNode* sp = new storageNode;

	sp->fp = NULL;
	sp->currentRow = NULL;
	sp->currentpos = 0;
	sp->rowLength = 0;
	sp->position = 0;

	return sp;
}

void deleteStorageNode(storageNode* sp) {
//	if (sp->currentRow != NULL) delete[] sp->currentRow;  //�����⣬�ɲ���
	delete sp;
}


bool createDBDir(char* name) {
	bool success;
	char* filename = stringcat(filePrefix, name);		/* �����ļ�·�� */

	success = CreateDirectory(filename, NULL);			/* ����WIN API����Ŀ¼ */
	if (success) 
		return true;
	else 
		return false;
}

bool deleteDBDir(char* name) {
	bool success;
	char* filename = stringcat(filePrefix, name);

	success = RemoveDirectory(filename);		/*����WIN API ɾ����Ŀ¼*/
	if (success) 
		return true;
	else 
		return false;
}

bool create(char* name) {
	FILE* fp;
	char* filename = stringcat(filePrefix, name);
	fopen_s(&fp, filename, "wb");
	if (fp == NULL) {
		printf("FILE CREATE ERROR");
		return false;
	}
	fclose(fp);
	return true;
}

bool drop(char* name) {
	char* filename = stringcat(filePrefix, name);
	int i = remove(filename);
	if (i == 0)
		return true;
	else
		return false;
}


bool open(storageNode* sp,char* name,long rowLength) {
	char* filename = stringcat(filePrefix, name);
	FILE* fp;

	fopen_s(&fp,filename, "rb+");
	if (fp == NULL) 
		return false;

	sp->fp = fp;
	sp->rowLength = rowLength+1;
	sp->currentpos = -1 * sp->rowLength;
	sp->currentRow = new char[sp->rowLength];
	sp->currentRow[0] = '\0';
	return true;
}

void close(storageNode* sp) {
	fclose(sp->fp);
	delete[] sp->currentRow;
}

void rnd_init(storageNode* sp) {
	fseek(sp->fp, 0, SEEK_SET);			/* ���þ��ļ��Ŀ�ͷƫ��Ϊ0�ֽڴ�Ϊstream��λ�� */
	sp->currentpos = -1 * sp->rowLength;
}


char* rnd_next(storageNode* sp) {
	sp->currentpos += sp->rowLength;		/*�ȸ��¶�ȡָ���λ��*/

	/*��stream�ж�ȡsp->rowLength���ֽڵ����ݵ�sp->currentRow��*/
	int i = fread_s(sp->currentRow, sp->rowLength, sp->rowLength, 1, sp->fp);	
	if (i != 1) {
		printf("read file error");
		return NULL;
	}
	if (sp->currentRow[0] == true) 
		return NULL;

	return sp->currentRow+1;		/* �����ļ���ÿ�е�һ���ַ�Ϊboolֵ���ڱ�ʶ�����Ƿ�ɾ�� */
}

bool write_row(storageNode* sp, char* row) {
	fseek(sp->fp, 0, SEEK_END);
	int i = fputc(false, sp->fp);
	if (i == -1) 
		return false;

	/*��row�е�����д���ļ�ĩβ*/
	i = fwrite(row, sp->rowLength - 1, 1, sp->fp);
	if (i != 1) 
		return false;
	return true;
}

void position(storageNode* sp) {
	sp->position = sp->currentpos;
}

char* rnd_pos(storageNode* sp) {
	/**/
	sp->currentpos = sp->position;
	fseek(sp->fp, 0, SEEK_SET);
	int i = fread_s(sp->currentRow, sp->rowLength, sp->rowLength, 1, sp->fp);
	if (i != sp->rowLength) {
		printf("read file error");
		return NULL;
	}
	return sp->currentRow + 1;
}

bool update_row(storageNode* sp, char* row) {
	/*����дָ����ǰ�ƶ������뵱ǰλ��ƫ����ΪrowLength�ĵط�*/
	fseek(sp->fp, -1*sp->rowLength, SEEK_CUR);

	/*ʹ�ø���ԭ�����з���������*/
	int i = fputc(false, sp->fp);
	if (i == -1) 
		return false;
	i = fwrite(row, sp->rowLength - 1, 1, sp->fp);
	if (i != 1) 
		return false;
	return true;
}

bool delete_row(storageNode* sp) {
	fseek(sp->fp, -1*sp->rowLength, SEEK_CUR);

	/*�����λ����fputc���true�Ļ�����ֱ�Ӹ��ǵ�ԭλ�õ�false��־λ���Ӷ�ʵ��ɾ������*/
	int i = fputc(true, sp->fp);
	
	/*ʹ��дָ��ص�ԭ����λ��*/
	fseek(sp->fp, sp->rowLength - 1, SEEK_CUR);
	if (i == -1) 
		return false;
	return true;
}

bool isEOF(storageNode* sp) {
	getc(sp->fp);
	int i = feof(sp->fp);
	if (i == 1)			/*���ļ�ĩβ*/
		return true;		
	else
	{
		/*getc�����Ὣ��ȡָ�������һ���ַ�������Ҫ��fseek�ƻ���*/
		fseek(sp->fp, -1, SEEK_CUR);
		return false;
	}
	
}