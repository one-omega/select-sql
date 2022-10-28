#pragma once

#ifndef STORAGECLASS_H_
#define STORAGECLASS_H_


#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>

//using namespace ;				//--不能使用，会造成命名空间的污染

//不建议用C++写存储引擎，难实现、难调试，API比较难查。


class StorageClass
{
public:
	//FILE* fp;				//文件指针，指向打开的物理文件
	std::fstream file;			//文件流
	StorageClass( char* name, long rowLength );			//构造函数，打开对应的文件
	StorageClass();							//默认构造函数
	bool createDBDir(char* name);			//创建文件夹
	bool deleteDBDir(char* name);			//删除文件夹
	bool create(char* name);				//创建文件
	bool drop(char* name);					//删除文件
	void close();							//关闭文件
	void rnd_init();						//重新定位文件读指针于文件开头
	char* rnd_next();						//读入并返回一行数据
	void write_row(char* row);				//向文件末尾写入数据
	void update_row(char* row);				//使用覆盖的方法来修改行的数据
	void delete_row();						//删除行
	bool isEOF();							//判断当前是否已到达文件末尾
	int bytenum;
	void getbytenum();
	

private:
	char* currentRow;		//当前行的内容，用字节数组储存.物理文件中每一行第一个字节为标志位
	long currentpos;		//读指针的位置，总是在上一个读写的行的开头
	long rowLength;			//currentRow字符串的长度（以字节为单位） 
	//long position;			//写文件前的指针位置
	
	 
};




#endif // !STORAGE_H
