//int number[4];  number[0]=rand()%11; number[2]....
//int sign[3]; sign[0]=rand()%4+1;  rand()%4= 1 -> '+'; 2 -> '-'  ;3 -> '*'; 4 -> '/';
//int bracket=rand()%6+1
//1:(a b)c d;  2:a (b c) d; 3:a b (c d); 4:(a b c) d ; 5:a (b c d); 6:(a b)(c d);

int calculateResult()  //��������ʽ���������ŵ�λ�þ�������˳��
{
	float result;
	if (bracket == 1)
	{
		if (sign[2] == 3 || sign[2] == 4)
			result = calculate(calculate(number[0], sign[0], number[1]), sign[1], calculate(number[2], sign[2], number[3]));
		else
			result = calculate(calculate(calculate(number[0], sign[0], number[1]), sign[1], number[2]), sign[2], number[3]);
	}
	if (bracket == 2)
	{
		if (sign[2] == 3 || sign[2] == 4)
			result = calculate(number[0],sign[0],calculate(calculate( number[1],sign[1], number[2]), sign[2], number[3]));
		else
			result = calculate(calculate(number[0], sign[0], calculate(number[1], sign[1], number[2])), sign[2], number[3]);
	}
	if (bracket == 3)
	{
		if (sign[1] == 3 || sign[1] == 4)
			result = calculate(number[0], sign[0],calculate( number[1], sign[1], calculate(number[2], sign[2], number[3])));
		else
			result = calculate(calculate(number[0], sign[0], number[1]), sign[1], calaulate(number[2], sign[2], number[3]));
	}
	if (bracket == 4)
	{
		if (sign[1] == 3 || sign[1] == 4)
			result = calculate(calculate(number[0], sign[0],calculate( number[1], sign[1],number[2])), sign[2], number[3]);
		else
			result = calculate(calculate(calculate(number[0], sign[0], number[1]), sign[1], number[2]), sign[2], number[3]);
	}
	if (bracket == 5)
	{
		if (sign[2] == 3 || sign[2] == 4)
			result = calculate(number[0], sign[0], calculate(number[1], sign[1], calculate(number[2], sign[2], number[3])));
		else
			result = calculate(number[0], sign[0],calculate( calculate(number[1], sign[1], number[2]), sign[2], number[3]));
	}
	if(bracket==6)
		result =calculate( calculate(number[0], sign[0], number[1]), sign[1], calculate(number[2], sign[2], number[3]));

	if ((result - (int)result) >= 0.5)
		result = result + 1;

	return restult;
}
float calculate(float a, float b, float c)//����������
{
	float sum;
	switch (b)
	{
	case 1:sum= a + c; break;
	case 2:sum= a - c; break;
	case 3:sum= a*c; break;
	case 4:sum = a / c; break;
	}
	return sum;
}


//print()������Ҫ��scan������ȡ�û�����Ĵ�
//����һ��ȫ�ֱ���score������¼�ܷ֣�Number��¼�û����������
int score = 0;
void print()
{
/*	int result = calculateResult();
	if (answer == result)
	{
		cout << "�����" << endl;     //����ط�Ҫ֧�ֶ�����
		score++;
	}
	else
		cout << "���ź�������ˡ���ȷ���ǣ�" << result << endl;
*/
	//�Ҿ�����Щ��Ҫ����scan���棬�����е���Ŀ�����֮���ٵ���print����
	cout << "��һ�������" << score << "���⣬" << "��" << Number - score << "������,Ҫ�ٽ�����Ŷ����" << endl;

}