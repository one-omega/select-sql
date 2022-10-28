#include "StorageClass.h"
//using namespace std;

std::string filePrefix = "..\\SQLFile\\";	//����·��ǰ׺��ʹ�����·�������ݿ�ϵͳ�������ļ�������SQLFileĿ¼�� 


StorageClass::StorageClass(char* name, long rowLength)
{
	std::string filename = filePrefix + name;

	//�ȴ����ļ�(ʹ��app���ٹص���-----��ؼ�
	file.open(filename, std::ios::app);
	file.close();

	//���ļ�
	file.open(filename, std::ios::in | std::ios::out|std::ios::binary);		//��дʱ��������Ϊapp�������ļ�ָ���޷��ƶ�
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
	bool flag = CreateDirectory(filename.c_str(), NULL);		//ʹ��c_str()�����õ���Ӧ��C��׼���ַ���
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
	file.open(filename,std::ios::in|std::ios::out|std::ios::app);			//�����ļ�
	if (!file.is_open())		
		return false;		//�ļ���ʧ��
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
	file.seekg(0,std::ios::beg);			//�ļ���ָ�����ڿ�ͷ
	this->currentpos = -1 * this->rowLength;
}

char* StorageClass::rnd_next() {
	currentpos += rowLength;
	//char* buffer = new char[rowLength];
	file.read(currentRow,rowLength);				//���ļ��ж�һ�����ݵ�currentrow��

	if (currentRow[0] == true)
		return NULL;

	return currentRow+1;		//�����ļ���ÿһ�е�һ���ֽ�Ϊ��־λ
}

void StorageClass::write_row(char* row) {
	file.seekp(0,std::ios::end);		//��дָ���ƶ����ļ�ĩβ
	file.put(false);		//�ñ�־λΪ��Ч
	file.write(row, rowLength - 1);		//д������
}

void StorageClass::update_row(char* row) {
	//ע�⣺C++�Ķ�дָ����ͬһ��
	//int position = file.tellg();		//��ȡ��ָ���λ��
	file.seekp(-1*rowLength , std::ios::cur);		//��дָ���ƶ���Ҫ�����еĿ�ͷ

	//ʹ�ø���ԭ�����еķ������޸�
	file.put(false);
	file.write(row, rowLength - 1);					//���Ը���

}

void StorageClass::delete_row() {
	//int position = file.tellg();		//��ǰ�ļ���ָ���λ��
	file.seekp(-1*rowLength, std::ios::cur);			//���ļ�дָ���ƶ���Ҫɾ���еĿ�ͷ
	file.put(true);						//��־λ����Ϊ��Ч
	file.seekg(rowLength - 1, std::ios::cur);		//��ָ���ƶ���ԭλ��

}

bool StorageClass::isEOF() {
	//ע�⣺ֻ���ڶ�дָ���ƶ���EOF��֮��Ż��ж������ļ�ĩβ
				
	//if (file.peek()==EOF)		//���Ԥ��ȡһ���ֽ�
	//	return true;
	//else {
	//	//file.seekg(-1, std::ios::cur);		//����дָ����ǰ�ƻ���
	//	return false;
	//}


	//fstream����eof����ʹ�ã����������ж��ļ�ָ��λ�õ�
	//ʹ���ж��ļ��ֽ����ķ�������
	int cur = file.tellg();

	return cur == bytenum;

}


void StorageClass::getbytenum() {
	file.seekg(0, std::ios::end);
	bytenum = file.tellg();
}

