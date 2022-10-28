#include "StorageClass.h"
//using namespace std;

std::string filePrefix = "..\\SQLFile\\";	//定义路径前缀，使用相对路径。数据库系统的物理文件储存在SQLFile目录下 


StorageClass::StorageClass(char* name, long rowLength)
{
	std::string filename = filePrefix + name;

	//先创建文件(使用app打开再关掉）-----最关键
	file.open(filename, std::ios::app);
	file.close();

	//打开文件
	file.open(filename, std::ios::in | std::ios::out|std::ios::binary);		//读写时不能设置为app，否则文件指针无法移动
	if (!file.is_open()) {
		std::cout << "no file" << std::endl;
		return;
	}


	this->rowLength = rowLength + 1;
	this->currentpos = -1 * this->rowLength;
	this->currentRow = new char[this->rowLength];
	this->currentRow[0] = '\0';

	getbytenum();
}

StorageClass::StorageClass(){}

bool StorageClass::createDBDir(char* name) {
	std::string filename = filePrefix + name;
	bool flag = CreateDirectory(filename.c_str(), NULL);		//使用c_str()方法得到对应的C标准的字符串
	return flag;

}

bool StorageClass::deleteDBDir(char* name) {
	std::string filename = filePrefix + name;
	bool flag = RemoveDirectory(filename.c_str());
	return flag;
}

bool StorageClass::create(char* name) {
	std::string filename = filePrefix + name;
	//fstream file;
	file.open(filename,std::ios::in|std::ios::out|std::ios::app);			//创建文件
	if (!file.is_open())		
		return false;		//文件打开失败
	file.close();
	return true;
}

bool StorageClass::drop(char* name) {
	std::string filename = filePrefix + name;
	if (remove(filename.c_str()) == 0)
		return true;
	else
		return false;
}

void StorageClass::close() {
	file.close();
}

void StorageClass::rnd_init() {
	file.seekg(0,std::ios::beg);			//文件读指针置于开头
	this->currentpos = -1 * this->rowLength;
}

char* StorageClass::rnd_next() {
	currentpos += rowLength;
	//char* buffer = new char[rowLength];
	file.read(currentRow,rowLength);				//从文件中读一行数据到currentrow中

	if (currentRow[0] == true)
		return NULL;

	return currentRow+1;		//物理文件中每一行第一个字节为标志位
}

void StorageClass::write_row(char* row) {
	file.seekp(0,std::ios::end);		//将写指针移动到文件末尾
	file.put(false);		//置标志位为有效
	file.write(row, rowLength - 1);		//写入数据
}

void StorageClass::update_row(char* row) {
	//注意：C++的读写指针是同一个
	//int position = file.tellg();		//获取读指针的位置
	file.seekp(-1*rowLength , std::ios::cur);		//将写指针移动到要更新行的开头

	//使用覆盖原数据行的方法来修改
	file.put(false);
	file.write(row, rowLength - 1);					//可以覆盖

}

void StorageClass::delete_row() {
	//int position = file.tellg();		//当前文件读指针的位置
	file.seekp(-1*rowLength, std::ios::cur);			//将文件写指针移动到要删除行的开头
	file.put(true);						//标志位设置为无效
	file.seekg(rowLength - 1, std::ios::cur);		//将指针移动回原位置

}

bool StorageClass::isEOF() {
	//注意：只有在读写指针移动到EOF符之后才会判定到达文件末尾
				
	//if (file.peek()==EOF)		//向后预读取一个字节
	//	return true;
	//else {
	//	//file.seekg(-1, std::ios::cur);		//将读写指针向前移回来
	//	return false;
	//}


	//fstream流的eof很难使用，不是用来判断文件指针位置的
	//使用判断文件字节数的方法来做
	int cur = file.tellg();

	return cur == bytenum;

}


void StorageClass::getbytenum() {
	file.seekg(0, std::ios::end);
	bytenum = file.tellg();
}

