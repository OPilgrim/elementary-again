#include"Random.h"
#include"Equation.h"
#include<math.h>
#include<iostream>
#include<ctime>
#include<fstream>
#include"File.h"
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;
class Rand rand_; //����һ��Random����
class File all_f;//����һ��File����
//srand((unsigned)time(NULL));

void Equation::creat()
{
number[0] = rand_.randomNumber(); //����
number[1] = rand_.randomNumber(); 
number[2] = rand_.randomNumber(); 
number[3] = rand_.randomNumber();
sign[1] = '+';     
sign[2] = '-'; 
sign[3] = '*'; 
sign[4] = '/';
sign_1 = rand_.randOperation();//����
sign_2 = rand_.randOperation();
sign_3 = rand_.randOperation();
bracket = rand_.randombracket();//����
}

void Equation::gengerateExpression()
{
	stringstream ss;
	if (bracket == 1)
		ss << "(" << number[0] << sign[sign_1] << number[1] << ")" << sign[sign_2] << number[2] << sign[sign_3] << number[3] << "=";
	if (bracket == 2)
		ss << number[0] << sign[sign_1] << "(" << number[1] << sign[sign_2] << number[2] << ")" << sign[sign_3] << number[3] << "=";
	if (bracket == 3)
		ss << number[0] << sign[sign_1] << number[1] << sign[sign_2] << "(" << number[2] << sign[sign_3] << number[3] << ")" << "=";
	if (bracket == 4)
		ss << "(" << number[0] << sign[sign_1] << number[1] << sign[sign_2] << number[2] << ")" << sign[sign_3] << number[3] << "=";
	if (bracket == 5)
		ss << number[0] << sign[sign_1] << "(" << number[1] << sign[sign_2] << number[2] << sign[sign_3] << number[3] << ")" << "=";
	if (bracket == 6)
		ss << "(" << number[0] << sign[sign_1] << number[1] << ")" << sign[sign_2] << "(" << number[2] << sign[sign_3] << number[3] << ")" << "=";
	string str = ss.str();
	ss.str(" ");
	S = str;
	all_f.set_1(argv, str);   //��ߵ�ʱ��Ҫ��argv[2]��ָ�봫��generate
	all_f.writeFile_1();   //������ʽд���ļ�writeFile_1(argv[2], str);   //������ʽд���ļ�
}

void Equation::calculatResult()
{
	float result;
	if (bracket == 1)
	{
		if (sign_3 == 3 || sign_3 == 4)
			result = calculate(calculate(number[0], sign_1, number[1]), sign_2, calculate(number[2], sign_3, number[3]));
		else
			result = calculate(calculate(calculate(number[0], sign_1, number[1]), sign_2, number[2]), sign_3, number[3]);
	}
	else if (bracket == 2)
	{
		if (sign_3 == 3 || sign_3 == 4)
			result = calculate(number[0], sign_1, calculate(calculate(number[1], sign_2, number[2]), sign_3, number[3]));
		else
			result = calculate(calculate(number[0], sign_1, calculate(number[1], sign_2, number[2])), sign_3, number[3]);
	}
	else if (bracket == 3)
	{
		if (sign_2 == 3 || sign_2 == 4)
			result = calculate(number[0], sign_1, calculate(number[1], sign_2, calculate(number[2], sign_3, number[3])));
		else
			result = calculate(calculate(number[0], sign_1, number[1]), sign_2, calculate(number[2], sign_3, number[3]));
	}
	else if (bracket == 4)
	{
		if (sign_2 == 3 || sign_2 == 4)
			result = calculate(calculate(number[0], sign_1, calculate(number[1], sign_2, number[2])), sign_3, number[3]);
		else
			result = calculate(calculate(calculate(number[0], sign_1, number[1]), sign_2, number[2]), sign_3, number[3]);
	}
	else if (bracket == 5)
	{
		if (sign_3 == 3 || sign_3 == 4)
			result = calculate(number[0], sign_1, calculate(number[1], sign_2, calculate(number[2], sign_3, number[3])));
		else
			result = calculate(number[0], sign_1, calculate(calculate(number[1], sign_2, number[2]), sign_3, number[3]));
	}
	else if (bracket == 6)
		result = calculate(calculate(number[0], sign_1, number[1]), sign_2, calculate(number[2], sign_3, number[3]));
	if ((result - (int)result) >= 0.5)
			result = result + 1;
	Result = result;
	all_f.set_2(argv, result); //��ʱ��Ҫ���θ���
	all_f.writeFile_2();//����ȷ��д���ļ�
}

float Equation::calculate(float a, int b, float c)
{
	float sum;
	if (b == 1)
		sum = a + c;
	if (b == 2)
		sum = a - c;
	if (b == 3)
		sum = a*c;
	if (b == 4)
	{
		if (c == 0)
			return 0;
		sum = a / c;
	}
	return sum;
}