#ifndef FIEL_H
#define FIEL_H
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class File
{
private:
	char * Filepath;//规定private里面的都是首字母大写好了
	string Statement;
	int Value;
	int Number;

public:
	int readFile();   //从文件读题目数
	void writeFile_1();  //写算式
	void writeFile_2();  //写答案,包括正确答案和用户答案
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
