#include "StorageEngine.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>


/* 定义路径前缀，使用相对路径。数据库系统的物理文件储存在SQLFile目录下 */
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
//	if (sp->currentRow != NULL) delete[] sp->currentRow;  //有问题，可不改
	delete sp;
}


bool createDBDir(char* name) {
	bool success;
	char* filename = stringcat(filePrefix, name);		/* 构造文件路径 */

	success = CreateDirectory(filename, NULL);			/* 调用WIN API创建目录 */
	if (success) 
		return true;
	else 
		return false;
}

bool deleteDBDir(char* name) {
	bool success;
	char* filename = stringcat(filePrefix, name);

	success = RemoveDirectory(filename);		/*调用WIN API 删除空目录*/
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
	fseek(sp->fp, 0, SEEK_SET);			/* 设置距文件的开头偏移为0字节处为stream的位置 */
	sp->currentpos = -1 * sp->rowLength;
}


char* rnd_next(storageNode* sp) {
	sp->currentpos += sp->rowLength;		/*先更新读取指针的位置*/

	/*从stream中读取sp->rowLength个字节的数据到sp->currentRow中*/
	int i = fread_s(sp->currentRow, sp->rowLength, sp->rowLength, 1, sp->fp);	
	if (i != 1) {
		printf("read file error");
		return NULL;
	}
	if (sp->currentRow[0] == true) 
		return NULL;

	return sp->currentRow+1;		/* 物理文件中每行第一个字符为bool值用于标识该行是否被删除 */
}

bool write_row(storageNode* sp, char* row) {
	fseek(sp->fp, 0, SEEK_END);
	int i = fputc(false, sp->fp);
	if (i == -1) 
		return false;

	/*将row中的内容写到文件末尾*/
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
	/*将读写指针向前移动到距离当前位置偏移量为rowLength的地方*/
	fseek(sp->fp, -1*sp->rowLength, SEEK_CUR);

	/*使用覆盖原来的行方法来更新*/
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

	/*在这个位置用fputc输出true的话，会直接覆盖掉原位置的false标志位，从而实现删除功能*/
	int i = fputc(true, sp->fp);
	
	/*使读写指针回到原来的位置*/
	fseek(sp->fp, sp->rowLength - 1, SEEK_CUR);
	if (i == -1) 
		return false;
	return true;
}

bool isEOF(storageNode* sp) {
	getc(sp->fp);
	int i = feof(sp->fp);
	if (i == 1)			/*是文件末尾*/
		return true;		
	else
	{
		/*getc函数会将读取指针向后移一个字符，所以要用fseek移回来*/
		fseek(sp->fp, -1, SEEK_CUR);
		return false;
	}
	
}