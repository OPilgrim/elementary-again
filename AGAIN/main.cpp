#include<fstream>
#include<sstream>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
#include<math.h>
#include"Language.h" //
#include"File.h"
#include"Random.h"
#include"Equation.h"
using namespace std;


int /*number[4],*/Number,score=0;  //�����������������ȷ����
//string sign[5];
//int sign_1, sign_2, sign_3;  //��������,ȡֵ��1��4
//int bracket;//ȡֵ��1��6
string language[10];
class LANGUAGE lang;  //����һ��lang����
class File all_file;//����һ��File����
class Equation equa;
//class Rand rand_; //����һ��Random����

//void language_(string *Resource, int language);
//int readFile(char* filepath);
//int randomNumber();
//int randOperation();
//int randombracket();
//string gengerateExpression();
//void writeFile_1(char* filepath, string x);
//void writeFile_2(char* filepath,int x);
//int calculatResult();
//float calculate(float a, int b, float c);
int scan();
void Menu();
void print();

int main(int argc, char *argv[])
{
	//sign[1] = '+'; sign[2] = '-'; sign[3] = '*'; sign[4] = '/';
	srand((unsigned)time(NULL));
	Menu();
	int language_3;
	cin>> language_3;
	lang.set(language, language_3); 
	lang.language_1();//д����ʾ��
	do
	{
		//cout << language[0]<<endl;  //��ʾ�û�������Ҫ����Ŀ����
		cout << language[5] << endl;
		score = 0;
		all_file.set(argv[1]);
		Number = all_file.readFile();
		all_file.set_2(argv[2], Number);
		all_file.writeFile_2();  //����Ŀ��д���ļ�
		for (int i = 0; i < Number; i++)
		{
			string strp;
			//number[0] = rand_.randomNumber(); number[1] = rand_.randomNumber(); number[2] = rand_.randomNumber(); number[3] = rand_.randomNumber();
			//sign_1 =rand_.randOperation(); sign_2 = rand_.randOperation(); sign_3 = rand_.randOperation();
			//bracket = rand_.randombracket();
			//ֻҪ�������creat()
			equa.set(argv[2]);
			//equa.creat();//�������֡�����
			equa.gengerateExpression();//������ʽ
			strp = equa.get_();//gengerateExpression();   //strp �洢����ʽ
			cout << strp;
			int result = equa.get();
			int answer = scan();
			all_file.set_2(argv[2], answer);
			all_file.writeFile_2();//���û���д���ļ�
			if (answer == result)   //�˴�Ӧ��������ʾ
			{
				cout << language[1]<<endl;  //��ʾ�û������
				score++;
			}
			else
			{
				cout << language[2]<<endl;  //��ʾ�û������
				cout << language[3] << result<<endl;  //��ȷ��Ӧ����:
			}
			
		}
		print();
		cout << language[4]; //��ʾ�û���������������ǰ���e������
		char judge;
		cin >> judge;
		if (judge == 'e')
			break;
	} while (1);
	return 0;
}

void Menu()
{
	cout << "---------------------------------------------------------------------------------\n" << endl;
	cout << "*****************Please enter number to chioce your language:****************\n" << endl;
	cout << "*******      1:Chinese  2:English  3:Japanese  4:Franch  5:German       **********\n" << endl;
	cout << "---------------------------------------------------------------------------------\n\n" << endl;
}

/*void language_(string *Resource, int language_1)    //��ȡ����
{
	fstream File;
	stringstream ss;
	char filepath[100] = " ";
	ss << "C:\\Users\\lenovo\\Desktop\\AGAIN\\Language\\" << language_1 << ".txt"; //�����ļ���ַ ������Ӧ�ð������ļ�������ΪLanguage���ļ��ֱ���1.txt 2.txt ....
	ss >> filepath;
	ss.str(" ");
	File.open(filepath, ios::in);
	string Line;
	for (int i = 0; getline(File, Line); i++)
	{
		swap(Line,language[i]);   //�����һ��һ���ĸ��Ƶ�language������ȥ
	}
	File.close();
}*/



/*int readFile(char *filepath)
{
	fstream file;
	file.open(filepath, ios::in);
	file >> Number;
	file.close();
	return Number;
}*/

int scan()
{
	int answer;
	cin >> answer;
	return answer;
}

/*string gengerateExpression()
{
	stringstream ss;
	if (bracket == 1)
		ss << "(" << number[0] << sign[sign_1] << number[1] << ")" << sign[sign_2] << number[2] << sign[sign_3] << number[3] << "=";
	if (bracket == 2)
		ss << number[0] << sign[sign_1] << "("<< number[1] << sign[sign_2] << number[2] << ")"<< sign[sign_3] << number[3] << "=";
	if (bracket == 3)
		ss << number[0] << sign[sign_1]<< number[1] << sign[sign_2] << "(" << number[2] << sign[sign_3] << number[3] << ")" << "=";
	if (bracket == 4)
		ss << "("<< number[0] << sign[sign_1]  << number[1] << sign[sign_2] << number[2] << ")" << sign[sign_3] << number[3] << "=";
	if (bracket == 5)
	    ss << number[0] << sign[sign_1] << "(" << number[1] << sign[sign_2] << number[2]<< sign[sign_3] << number[3] << ")"  << "=";
	if (bracket == 6)
		ss << "("<< number[0] << sign[sign_1]  << number[1] <<")"<< sign[sign_2] <<"("<< number[2] << sign[sign_3] << number[3]<< ")"  << "=";
	string str = ss.str();
	ss.str(" ");
	cout << str;
	all_file.set_1(argv[2], str);   //��ߵ�ʱ��Ҫ��argv[2]��ָ�봫��generate
	all_file.writeFile_1();   //������ʽд���ļ�writeFile_1(argv[2], str);   //������ʽд���ļ�
	return str;
}*/

/*int calculatResult()
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
			result = calculate(number[0], sign_1, calculate(calculate(number[1], sign_2, number[2]),sign_3, number[3]));
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
			result = calculate(calculate(calculate(number[0], sign_1, number[1]), sign_2, number[2]),sign_3, number[3]);
	}
	else if (bracket == 5)
	{
		if (sign_3 == 3 || sign_3 == 4)
			result = calculate(number[0], sign_1, calculate(number[1], sign_2, calculate(number[2],sign_3, number[3])));
		else
			result = calculate(number[0],sign_1, calculate(calculate(number[1], sign_2, number[2]), sign_3, number[3]));
	}
	else if (bracket == 6)
		result = calculate(calculate(number[0], sign_1, number[1]),sign_2, calculate(number[2], sign_3, number[3]));
	if ((result - (int)result) >= 0.5)
		result = result + 1;
	all_file.set_2(argv[2], result); //��ʱ��Ҫ���θ���
	all_file.writeFile_2();//����ȷ��д���ļ�
	return result;
}*/
/*float calculate(float a, int b, float c)//����������
{
	float sum;
	if(b==1)
		sum = a + c;
	if(b==2)
		sum = a - c;
	if(b==3)
		sum = a*c;
	if (b == 4)
	{
		if (c == 0)
			return 0;
		sum = a / c;
	}
	return sum;
}*/

/*int randomNumber()
{
	//srand((unsigned)time(NULL));
	return rand() % 10+1;
}
int randOperation()
{
//	srand((unsigned)time(NULL));
	return rand() % 4+1;
}
int randombracket()
{
//	srand((unsigned)time(NULL));
	return rand() % 6+1;
}*/

void print()
{
	cout << language[6] << score << language[7] << Number - score <<language[8]<< endl;
		//"��һ�������" << score << "���⣬" << "��" <<  << "������,Ҫ�ٽ�����Ŷ����" << endl;
	return;
}
/*void writeFile_1(char* filepath,string x)
{
	fstream fout;
	fout.open(filepath,ios::app);
	fout << x;
	fout << '\n';
	fout.close();
	return;
}*/
/*void writeFile_2(char* filepath, int x)
{
	fstream fout;
	fout.open(filepath, ios::app);
	fout << x;
	fout << '\n';
	fout.close();
	return;
}*/