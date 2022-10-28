#pragma once

#ifndef STORAGECLASS_H_
#define STORAGECLASS_H_


#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>

//using namespace ;				//--����ʹ�ã�����������ռ����Ⱦ

//��������C++д�洢���棬��ʵ�֡��ѵ��ԣ�API�Ƚ��Ѳ顣


class StorageClass
{
public:
	//FILE* fp;				//�ļ�ָ�룬ָ��򿪵������ļ�
	std::fstream file;			//�ļ���
	StorageClass( char* name, long rowLength );			//���캯�����򿪶�Ӧ���ļ�
	StorageClass();							//Ĭ�Ϲ��캯��
	bool createDBDir(char* name);			//�����ļ���
	bool deleteDBDir(char* name);			//ɾ���ļ���
	bool create(char* name);				//�����ļ�
	bool drop(char* name);					//ɾ���ļ�
	void close();							//�ر��ļ�
	void rnd_init();						//���¶�λ�ļ���ָ�����ļ���ͷ
	char* rnd_next();						//���벢����һ������
	void write_row(char* row);				//���ļ�ĩβд������
	void update_row(char* row);				//ʹ�ø��ǵķ������޸��е�����
	void delete_row();						//ɾ����
	bool isEOF();							//�жϵ�ǰ�Ƿ��ѵ����ļ�ĩβ
	int bytenum;
	void getbytenum();
	

private:
	char* currentRow;		//��ǰ�е����ݣ����ֽ����鴢��.�����ļ���ÿһ�е�һ���ֽ�Ϊ��־λ
	long currentpos;		//��ָ���λ�ã���������һ����д���еĿ�ͷ
	long rowLength;			//currentRow�ַ����ĳ��ȣ����ֽ�Ϊ��λ�� 
	//long position;			//д�ļ�ǰ��ָ��λ��
	
	 
};




#endif // !STORAGE_H
