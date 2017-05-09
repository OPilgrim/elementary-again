#include"Language.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void LANGUAGE::language_1()
{
	fstream File;
	stringstream ss;
	char filepath[100] = " ";
	ss << "C:\\Users\\lenovo\\Desktop\\AGAIN\\Language\\" << language_ << ".txt"; //生成文件地址 这里我应该把语言文件夹命名为Language，文件分别是1.txt 2.txt ....
	ss >> filepath;
	ss.str(" ");
	File.open(filepath, ios::in);
	string Line;
	for (int i = 0; getline(File, Line); i++)
	{
		swap(Line, Resource[i]);   //把语句一条一条的复制到language数组里去
	}
	File.close();
}