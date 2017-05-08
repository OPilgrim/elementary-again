#include<fstream>
#include<sstream>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;


int number[4],Number,score=0;  //随机数，总题数，正确题数
string sign[5];
int sign_1, sign_2, sign_3;  //决定符号,取值在1到4
int bracket;//取值在1到6
string language[10];


void language_(string *Resource, int language);
int readFile(char* filepath);
int scan();
void Menu();
int randomNumber();
int randOperation();
int randombracket();
string gengerateExpression();
void writeFile_1(char* filepath, string x);
void writeFile_2(char* filepath,int x);
int calculatResult();
void print();
float calculate(float a, int b, float c);

int main(int argc, char *argv[])
{
	sign[1] = '+'; sign[2] = '-'; sign[3] = '*'; sign[4] = '/';
	srand((unsigned)time(NULL));
	Menu();
	int language_1;
	cin>> language_1;
	language_(language, language_1);
	do
	{
		cout << language[0]<<endl;  //提示用户输入想要的题目数量
		cout << language[5] << endl;
		score = 0;
		Number = readFile(argv[1]);
		writeFile_2(argv[2], Number);  //把题目数写入文件
		for (int i = 0; i < Number; i++)
		{
			string str;
			number[0] = randomNumber(); number[1] = randomNumber(); number[2] = randomNumber(); number[3] = randomNumber();
			sign_1 = randOperation(); sign_2 = randOperation(); sign_3 = randOperation();
			bracket = randombracket();
			str=gengerateExpression();   //str 存储运算式
			int result = calculatResult();
			int answer = scan();
			if (answer == result)   //此处应有友情提示
			{
				cout << language[1]<<endl;  //提示用户答对了
				score++;
			}
			else
			{
				cout << language[2]<<endl;  //提示用户答错了
				cout << language[3] << result<<endl;  //正确答案应该是:
			}
			writeFile_1(argv[2], str);   //把运算式写入文件
			writeFile_2(argv[2], result);//把正确答案写入文件
			writeFile_2(argv[2], answer);//把用户答案写入文件
		}
		print();
		cout << language[4]; //提示用户按任意键继续还是按“e”结束
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

void language_(string *Resource, int language_1)    //读取语言
{
	fstream File;
	stringstream ss;
	char filepath[100] = " ";
	ss << "C:\\Users\\lenovo\\Desktop\\AGAIN\\Language\\" << language_1 << ".txt"; //生成文件地址 这里我应该把语言文件夹命名为Language，文件分别是1.txt 2.txt ....
	ss >> filepath;
	ss.str(" ");
	File.open(filepath, ios::in);
	string Line;
	for (int i = 0; getline(File, Line); i++)
	{
		swap(Line,language[i]);   //把语句一条一条的复制到language数组里去
	}
	File.close();
}



int readFile(char *filepath)
{
	fstream file;
	file.open(filepath, ios::in);
	file >> Number;
	file.close();
	return Number;
}

int scan()
{
	int answer;
	cin >> answer;
	return answer;
}

string gengerateExpression()
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
	return str;
}

int calculatResult()
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
	if(result<0)

	if ((result - (int)result) >= 0.5)
		result = result + 1;
	return result;
}
float calculate(float a, int b, float c)//简单四则运算
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
}

int randomNumber()
{
	srand((unsigned)time(NULL));
	return rand() % 11;
}
int randOperation()
{
	srand((unsigned)time(NULL));
	return rand() % 4+1;
}
int randombracket()
{
	srand((unsigned)time(NULL));
	return rand() % 6+1;
}

void print()
{
	cout << language[6] << score << language[7] << Number - score <<language[8]<< endl;
		//"您一共答对了" << score << "道题，" << "有" <<  << "道题答错,要再接再厉哦！！" << endl;
	return;
}
void writeFile_1(char* filepath,string x)
{
	fstream fout;
	fout.open(filepath,ios::app);
	fout << x;
	fout.close();
	return;
}
void writeFile_2(char* filepath, int x)
{
	fstream fout;
	fout.open(filepath, ios::app);
	fout << x;
	fout.close();
	return;
}