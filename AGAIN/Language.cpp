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
	ss << "C:\\Users\\lenovo\\Desktop\\AGAIN\\Language\\" << language_ << ".txt"; //�����ļ���ַ ������Ӧ�ð������ļ�������ΪLanguage���ļ��ֱ���1.txt 2.txt ....
	ss >> filepath;
	ss.str(" ");
	File.open(filepath, ios::in);
	string Line;
	for (int i = 0; getline(File, Line); i++)
	{
		swap(Line, Resource[i]);   //�����һ��һ���ĸ��Ƶ�language������ȥ
	}
	File.close();
}