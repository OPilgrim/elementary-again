#include<iostream>
#include"Random.h"
using namespace std;

int Rand::randomNumber()
{
	return rand() % 10 + 1;
}
int Rand::randOperation()
{
	return rand() % 4 + 1;
}
int Rand::randombracket()
{
	return rand() % 6 + 1;
}