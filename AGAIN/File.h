#ifndef FIEL_H
#define FIEL_H
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class File
{
private:
	char * Filepath;//�涨private����Ķ�������ĸ��д����
	string Statement;
	int Value;
	int Number;

public:
	int readFile();   //���ļ�����Ŀ��
	void writeFile_1();  //д��ʽ
	void writeFile_2();  //д��,������ȷ�𰸺��û���
	void set(char* filepath)
	{
		Filepath = filepath;
	}
	void set_1(char* filepath, string statement)
	{
		Filepath = filepath;
		Statement = statement;
	}
	void set_2(char* filepath, int value)
	{
		Filepath = filepath;
		Value = value;
	}

};

#endif
