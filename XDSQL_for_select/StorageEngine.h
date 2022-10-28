#pragma once
/*
�洢����ͷ�ļ�

����洢����ĸ������ӿںͶ�Ӧ�ṹ��

storageNode�ṹ��
���ܣ��洢����ʵ�����ṹ�壬��¼�ļ�ָ�롢��ǰ�����ݡ�position������¼������λ��


createNode�ӿڣ�����storageNode�ṹ�岢��ʼ��
deleteNode�ӿڣ�ɾ��storageNode�ṹ�壬�ͷ��ڴ�

create�ӿڣ������ݿ�·���´��������ļ�

drop�ӿڣ�ɾ��ָ�������ļ�

open�ӿڣ����ݴ����ļ����򿪶�Ӧ�ļ�

close�ӿڣ��ر��ļ�

rnd_init�ӿڣ���ʼ����ȡָ��

rnd_next�ӿڣ���ȡ��һ������

write_row�ӿڣ����βд������

position�ӿڣ���¼��ǰָ��λ��

rnd_pos�ӿڣ���ָ���ƶ�������λ��

update_row�ӿ��Ǹ���һ������

delete_row�ӿ���ɾ��һ������

*/


#ifndef STORAGEENGINE_H
#define STORAGEENGINE_H


#include<stdio.h>





	
/*storageNode�ṹ�壺���������ļ��Լ���صĶ�д��Ϣ*/
typedef struct storageNode {
	FILE* fp;				/*�ļ�ָ�룬ָ��򿪵������ļ�*/

	char* currentRow;		/*��ǰ�е����ݣ����ַ�������*/

	long currentpos;		/*��ȡָ���λ�ã���������һ����д���еĿ�ͷ*/

	long rowLength;			/* �ڵ���currentRow�ַ����ĳ��ȣ����ֽ�Ϊ��λ�� */
	
	long position;			/**/
}storageNode;	


/*********************************************************************************************************************
	������stringcat
	���ܣ������µ��ַ���������first��second����ƴ�ӵ����µ��ַ����� 
	input���ַ���first���ַ���second
	output����first�ַ�����second�ַ�������ƴ�ӳɵ����ַ���
***********************************************************************************************************************/
char* stringcat(char* first, char* second);



/**********************************************************************************************************************
	������createStorageNode
	���ܣ�����һ��StorageNode�ṹ�壬�������ڲ��ĳ�Ա��ʼ��
	input��void
	output��ָ�򴴽��Ľṹ���ָ��
**********************************************************************************************************************/
storageNode* createStorageNode();



/*********************************************************************************************************************
	������deleteStorageNode
	���ܣ�ɾ��һ��StorageNode�ڵ�
	input��ָ��StorageNode�ڵ��ָ��
	output��void
**********************************************************************************************************************/
void deleteStorageNode(storageNode* sp);

/*********************************************************************************************************************
	������createDBDir
	���ܣ�Ϊ�ļ����ڲ���ϵͳ�д���Ŀ¼
	input���ļ��������ַ�������
	output��Ŀ¼�����ɹ�����true�����򷵻�false
*********************************************************************************************************************/
bool createDBDir(char* name);


/*********************************************************************************************************************
	������deleteDBDir
	���ܣ����ļ��дӲ���ϵͳ��ɾ��
	input���ļ��������ַ�������
	output��ɾ���ɹ�����true�����򷵻�false
*********************************************************************************************************************/
bool deleteDBDir(char* name);

/*********************************************************************************************************************
	������create
	���ܣ����ݸ������ļ����������ݿ�ϵͳĿ¼�´����ļ�
	input���ļ������ַ�������
	output���ļ������ɹ�����true�����򷵻�false
*********************************************************************************************************************/
bool create(char* name);

/*********************************************************************************************************************
	������drop
	���ܣ������ļ���������Ӧ���ļ��Ӳ���ϵͳ��ɾ��
	input���ļ������ַ�������
	output��ɾ���ɹ�����true������Ϊfalse
*********************************************************************************************************************/
bool drop(char* name);

/*************************************************************************************************************
	������open
	���ܣ����ļ�����Ӧ���ļ������ļ������ڻ��Զ����������������ļ���storageNode�ڵ��еĳ�Ա��ֵ��ʹstorageNode�ڵ㴢����ļ�����Ϣ
	input��ָ��storageNode�ڵ��ָ�롢�ļ������ַ������ͣ����ļ���Ԫ��ĳ��ȣ����ֽ�Ϊ��λ��
	output���ڵ㸳ֵ�ɹ�����true�����򷵻�false
*************************************************************************************************************/
bool open(storageNode* sp,char* name,long rowLength);

/*************************************************************************************************************
	������close
	���ܣ��ر�sp�ṹ���Ӧ���ļ�������sp�ṹ���е�currentRow�ַ���ɾ��
	input��ָ��storageNode�ڵ��ָ��
	output��void
*************************************************************************************************************/
void close(storageNode* sp);

/************************************************************************************************************
	������rnd_init
	���ܣ���ʼ����дָ�룬ʹstreamλ��λ���ļ���ͷ
	input��ָ��storageNode�ڵ��ָ��
	output��void
*************************************************************************************************************/
void rnd_init(storageNode* sp);

/************************************************************************************************************
	������rnd_next
	���ܣ��Ƚ�ָ���ƶ���Ҫ��ȡ�еĿ�ͷ��Ȼ���ȡһ�����ݣ���������ѱ�ɾ�����򷵻�NULL
	input��ָ��storageNode�ڵ��ָ��
	output����ȡ����һ������
**************************************************************************************************************/
char* rnd_next(storageNode* sp);

/************************************************************************************************************
	������write_row
	���ܣ����ַ���row�е�����д���ļ���ĩβ
	input��ָ��storageNode�ڵ��ָ�룬Ҫд���ļ����ַ���row
	output������д��ɹ��򷵻�true�����򷵻�false
*************************************************************************************************************/
bool write_row(storageNode* sp,char* row);

/***********************************************************************************************************
	������position
	���ܣ���sp�ڵ���currentpos��Ա��ֵ����position��Ա�������ڶ���д�ļ�����ת��ʱ����֮ǰ���ļ���ָ��λ�ã����������ԭ��ȡָ��λ��
	input��ָ��storageNode�ڵ��ָ��sp
	output��void
*************************************************************************************************************/
void position(storageNode* sp);

/***********************************************************************************************************
	������rnd_pos
	���ܣ�����ȡָ���ƶ���
	input��
	output��
*************************************************************************************************************/
char* rnd_pos(storageNode* sp);

/***********************************************************************************************************
	������update_row
	���ܣ��������ļ��У���ָ�����и���
	input��ָ��storageNode�ڵ��ָ�룬���º����row���ַ������ͣ�
	output�����³ɹ��򷵻�true�����򷵻�false
*************************************************************************************************************/
bool update_row(storageNode* sp,char* row);

/***********************************************************************************************************
	������delete_row
	���ܣ�ɾ��ָ������
	input��ָ��storageNode�ڵ��ָ��
	output��ɾ���ɹ�������true�����򷵻�false
*************************************************************************************************************/
bool delete_row(storageNode* sp);


/***********************************************************************************************************
	������isEOF
	���ܣ��жϵ�ǰ��ȡָ���Ƿ����ļ�ĩβ
	input��ָ��storageNode�ڵ��ָ��
	output������ȡָ�����ļ�ĩβ������true�����򷵻�false
*************************************************************************************************************/
bool isEOF(storageNode* sp);

#endif // !STORAGEENGINE_H