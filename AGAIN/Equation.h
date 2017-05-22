#ifndef EQUATION_H
#define EQUATION_H

#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<ctime>
using namespace std;
//srand((unsigned)time(NULL));

class Equation
{
private:
	char sign[5];
	int sign_1, sign_2, sign_3;
	int number[4];
	int bracket;
	//float calculate(float a, int b, float c);
	void calculate();
	int compare(char x);
	string S;
	int Result;
	char *argv;  //argv[2]µÄµØÖ·
	void creat();
	void calculatResult();
public:
	
	void gengerateExpression();
	
	void set(char* address)
	{
		argv=address;
	}
	string get_()
	{
		return S;
	}
	int get()
	{
		return Result;
	}

};
#endif // !EQUATION_H

