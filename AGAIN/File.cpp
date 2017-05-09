#include"File.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int File::readFile()
{
	fstream file;
	file.open(Filepath, ios::in);
	file >> Number;
	file.close();
	return Number;
}

void File::writeFile_1()
{
	fstream fout;
	fout.open(Filepath, ios::app);
	fout << Statement;
	fout.close();
}

void File::writeFile_2()
{
	fstream fout;
	fout.open(Filepath, ios::app);
	fout << Value;
	fout << '\n';
	fout.close();
}
