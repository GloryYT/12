//�����������������ʽ �Ⱥ ���� 2016.3.12
#include<iostream>
#include<string>
#include<time.h>
#include <stdio.h>
#include<fstream>
#include<cmath>
#include<sstream>
#include<strstream>
#include<math.h>
#include<iomanip>
#define MAX 100
#define False 0
#define True 1
using namespace std;
typedef string SelemType;
using namespace std;
string str1[4] = { "+","-","*","/" };                        //��������飬�洢+ - * /
int n, m;
int num[6];                                                //������ɵĲ�����
char str2[25];                                             //����ת��Ϊ���ַ�����
char str3[25];                                             //����ת��Ϊ���ַ�����
string str4[100];
int OperatorNum[1000];                                    //��������飬ÿ����һ��������������
typedef struct {
	SelemType *base;
	SelemType *top;
	int stacksize;
}Sqstack;
void InitStack(Sqstack &s)                 //ջ�ĳ�ʼ��
{
	s.base = new SelemType[MAX];
	if (!s.base)exit(1);
	s.top = s.base;
	s.stacksize = MAX;
}
void Push(Sqstack &s, SelemType e)          //ѹ��
{
	if (s.top - s.base == s.stacksize)
		exit(1);
	*s.top++ = e;
}
void Pop(Sqstack &s, SelemType &e)          //����
{
	if (s.top == s.base)
		exit(1);
	e = *--s.top;
}
SelemType GetTop(Sqstack &s)          //ȡ��
{
	if (s.top == s.base)
		exit(1);
	return *(s.top - 1);
}
int In(SelemType ch)                        //�ж��Ƿ�Ϊ�����
{
	if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "(" || ch == ")" || ch == "#")
		return True;
	else
		return False;
}
SelemType Operate(SelemType a1, SelemType theta, SelemType b1)                          //����
{
	stringstream ss;
	SelemType c1;
	double m1, m2;
	double m3, m4;
	m1 = atof(a1.c_str());
	m2 = atof(b1.c_str());
	if (theta == "+")
		m3 = m1 + m2;
	else if (theta == "-")
		m3 = m1 - m2;
	else if (theta == "*")
		m3 = m1*m2;
	else if (theta == "/")
		m3 = m1 / m2;
	m4 = double((int)(m3 * 100)) / 100.0;
	ss << m4;
	ss >> c1;
	return c1;
}
char Precede(string theta1, string theta2)                     //������ļ���˳���ж�
{
	char chx;
	if (theta1 == "+")
	{
		if (theta2 == "*" || theta2 == "/" || theta2 == "(")
			chx = '<';
		else
			chx = '>';
	}
	else if (theta1 == "-")
	{
		if (theta2 == "*" || theta2 == "/" || theta2 == "(")
			chx = '<';
		else
			chx = '>';
	}
	else if (theta1 == "*")
	{
		if (theta2 == "(")
			chx = '<';
		else
			chx = '>';
	}
	else if (theta1 == "/")
	{
		if (theta2 == "(")
			chx = '<';
		else
			chx = '>';
	}
	else if (theta1 == "(")
	{
		if (theta2 == ")")
			chx = '=';
		else if (theta2 == "#")
			chx = '$';
		else
			chx = '<';
	}
	else if (theta1 == ")")
	{
		if (theta2 == "(")
			chx = '$';
		else
			chx = '>';
	}
	else if (theta1 == "#")
	{
		if (theta2 == "#")
			chx = '=';
		else if (theta2 == ")")
			chx = '$';
		else
			chx = '<';
	}
	return chx;
}
string TiQuString(string str, int &i)
{
	string ch;
	char *q;
	string p;
	p = str;
	q = &p[i];
	ch = ch + *q;
	if ((*q >= '0') && (*q <= '9'))
	{
		i++;
		int j = 1;
		while ((*(q + j) >= '0') && (*(q + j) <= '9'))
		{
			ch = ch + *(q + j);
			j++;
		}
		i = i + j - 1;
	}
	else
	{
		ch = *q;
		i++;
	}
	return ch;
}
string OPeration(string str)
{

	string str1;
	str1 = str + "#";
	int i = 0;
	string ch;
	ch = TiQuString(str1, i);
	SelemType theta, x1, a1, b1;
	Sqstack OPND, OPTR;
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, "#");
	while (ch != "#" || GetTop(OPTR) != "#")
	{
		int f;
		f = In(ch);
		if (f != True)
		{
			Push(OPND, ch);
			ch = TiQuString(str1, i);
		}
		else
		{
			switch (Precede(GetTop(OPTR), ch))
			{
			case '<':
			{
				Push(OPTR, ch);
				ch = TiQuString(str1, i);
				break;
			}
			case '>':
			{
				Pop(OPTR, theta);
				Pop(OPND, b1); Pop(OPND, a1);
				Push(OPND, Operate(a1, theta, b1));
				break;
			}
			case '=':
			{
				Pop(OPTR, x1);
				ch = TiQuString(str1, i);
				break;
			}
			case '$':
			{
				cout << "�ñ��ʽ�д�";
				break;
			}
			default:break;
			}
		}
	}
	return GetTop(OPND);

}
void Input(int n, int p, int min, int max, int &j, int &q)
{
	int num1, num2, num3, num4, num5;                        //�����
	int c = 0;                                             //ָ���һ�������������±�
	int s = 0;                                             //���ŵĸ���
	string str;
	ofstream outfile;
	outfile.open("a.txt", ios::app);
	if (!outfile)
	{
		cerr << "OPEN ERROR!" << endl;
		exit(0);
	}
	num1 = rand() % (max - min + 1) + min;
	num2 = rand() % (max - min + 1) + min;
	num3 = rand() % 4;                                       //�����ָ�������������±�
	itoa(num1, str2, 10);                                  //����ת��Ϊ�ַ�����
	itoa(num2, str3, 10);                                   //����ת��Ϊ�ַ�����
	str = str2 + str1[num3] + str3;                             //���ɱ��ʽ
	OperatorNum[c] = num3;                                  //��ǰ���ɵķ��Ŵ���OperatorNum������
	c++;
	n = n - 2;                       //����������������
	while (n != 0)                 //��n������0ʱ��ѭ������str�������ʽ+����+���ʽ����ʽ
	{
		num4 = rand() % 2;
		if (num4 == 0)             //��һ��str���ڷ��ŵ����
		{
			num5 = rand() % 2;
			if (s <= 3)
			{
				if (num5 == 0)            //��һ��str��������
				{
					num3 = rand() % 4;
					OperatorNum[c] = num3;
					c++;
					num1 = rand() % (max - min + 1) + min;
					itoa(num1, str2, 10);
					if ((num3 == 3) && (OperatorNum[c - 2] == 3))            //��������6/3/2����ʽ
						str = "(" + str + ")" + str1[num3] + str2;
					else
						str = str + str1[num3] + str2;
				}
				else                           //��һ��str������
				{
					num3 = rand() % 4;
					num1 = rand() % (max - min + 1) + min;
					itoa(num1, str2, 10);
					str = "(" + str + ")" + str1[num3] + str2;
					s++;
				}
			}
			else
			{
				num3 = rand() % 4;
				OperatorNum[c] = num3;
				c++;
				num1 = rand() % (max - min + 1) + min;
				itoa(num1, str2, 10);
				if ((num3 == 3) && (OperatorNum[c - 2] == 3))            //��������6/3/2����ʽ
					str = "(" + str + ")" + str1[num3] + str2;
				else
					str = str + str1[num3] + str2;
			}
		}
		else                              //��һ��str���ڷ��ŵ��ұ�
		{
			num5 = rand() % 2;
			if (s <= 3)
			{
				if (num5 == 0)                    // ��һ��str������
				{
					num3 = rand() % 4;
					OperatorNum[c] = num3;
					c++;
					num1 = rand() % (max - min + 1) + min;
					itoa(num1, str2, 10);
					if ((num3 == 3) && (OperatorNum[c - 2] == 3))
						str = str2 + str1[num3] + "(" + str + ")";
					else
						str = str2 + str1[num3] + str;
				}
				else                         //��һ��str������
				{
					num3 = rand() % 4;
					num1 = rand() % (max - min + 1) + min;
					itoa(num1, str2, 10);
					str = str2 + str1[num3] + "(" + str + ")";
					s++;
				}
			}
			else
			{
				num3 = rand() % 4;
				OperatorNum[c] = num3;
				c++;
				num1 = rand() % (max - min + 1) + min;
				itoa(num1, str2, 10);
				if ((num3 == 3) && (OperatorNum[c - 2] == 3))
					str = str2 + str1[num3] + "(" + str + ")";
				else
					str = str2 + str1[num3] + str;
			}
		}
		n--;                                //����һ��������
	}
	string result1, result2;               //result1��ʾ�û�����Ĵ𰸣�result2��ʾ�������Ľ��
	str4[p] = str;                         //��str�����ַ�������str4��
	for (int i = 0; i<p; i++)                 //��ѯ��������ʽ�Ƿ����ظ�
		if (str4[i] == str4[p])
			Input(m, p, min, max, j, q);
	cout << str4[p] << "=";
	result2 = OPeration(str);                  //����������ʽ
	cin >> result1;
	if (result1 == result2)                        //�жϽ���Ƿ���ȷ
	{
		cout << "������ȷ";
		j++;
	}
	else
	{
		cout << "�������,����" << setprecision(2) << fixed << result2;
		q++;
	}
	outfile << str4[p] << endl;
	cout << endl;
}
void Input1(int n, int p, int min, int max, int &j, int &q)
{
	int num1, num2, num3, num4;
	int c = 0;
	int s = 0;
	string str;
	ofstream outfile;
	outfile.open("a.txt", ios::app);
	if (!outfile)
	{
		cerr << "OPEN ERROR!" << endl;
		exit(0);
	}
	num1 = rand() % (max - min + 1) + min;
	num2 = rand() % (max - min + 1) + min;
	num3 = rand() % 4;
	itoa(num1, str2, 10);
	itoa(num2, str3, 10);
	str = str2 + str1[num3] + str3;
	OperatorNum[c] = num3;
	c++;
	n = n - 2;
	while (n != 0)                 //��n������0ʱ��ѭ������str�������ʽ+����+���ʽ����ʽ
	{
		num4 = rand() % 2;
		if (num4 == 0)             //��һ��str���ڷ��ŵ����
		{
			num3 = rand() % 4;
			OperatorNum[c] = num3;
			c++;
			num1 = rand() % (max - min + 1) + min;
			itoa(num1, str2, 10);
			if ((num3 == 3) && (OperatorNum[c - 2] == 3))            //��������6/3/2����ʽ
				str = "(" + str + ")" + str1[num3] + str2;
			else
				str = str + str1[num3] + str2;
		}
		else                              //��һ��str���ڷ��ŵ��ұ�
		{
			num3 = rand() % 4;
			OperatorNum[c] = num3;
			c++;
			num1 = rand() % (max - min + 1) + min;
			itoa(num1, str2, 10);
			if ((num3 == 3) && (OperatorNum[c - 2] == 3))
				str = str2 + str1[num3] + "(" + str + ")";
			else
				str = str2 + str1[num3] + str;
		}
		n--;
	}
	string result1, result2;
	str4[p] = str;                         //��str�����ַ�������str4��
	for (int i = 0; i<p; i++)                 //��ѯ��������ʽ�Ƿ����ظ�
		if (str4[i] == str4[p])
			Input(m, p, min, max, j, q);
	cout << str4[p] << "=";
	result2 = OPeration(str);
	cin >> result1;
	if (result1 == result2)
	{
		cout << "������ȷ";
		j++;
	}
	else
	{
		cout << "�������,����" << setprecision(2) << fixed << result2;
		q++;
	}
	outfile << str4[p] << endl;
	cout << endl;
}
void sort(int min, int max) {                      //�����ĸ������������
	num[0] = rand() % (max - min + 1) + min;
	num[1] = rand() % (max - min + 1) + min;
	num[2] = rand() % (max - min + 1) + min;
	num[3] = rand() % (max - min + 1) + min;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<i; j++) {
			if (num[i]>num[j])
			{
				int temp = 0;
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}
void sort1(int min, int max)                                    //���������������������
{
	num[4] = rand() % (max - min + 1) + min;
	num[5] = rand() % (max - min + 1) + min;
	for (int i = 4; i<6; i++) {
		for (int j = 4; j<i; j++) {
			if (num[i]>num[j])
			{
				int temp = 0;
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}
void Simplification(int &m, int &n)                                    //���������
{
	int x, y, i, p;                                                     //��Լ��p
	if (m >= n)
	{
		x = n;
		y = m;
	}
	if (m<n)
	{
		x = m;
		y = n;
	}
	for (i = x; i>0; i--)
	{
		if (x%i == 0 && y%i == 0)
		{
			p = i;
			break;
		}
	}
	m = m / p;
	n = n / p;
}
void Input2(int n, int p, int min, int max, int &j, int &q)
{
	int num3, num4, s = 0;
	string str, strr2, strr3, str5, str6, str7, str8, str9;
	stringstream ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8;
	ofstream outfile;
	outfile.open("a.txt", ios::app);
	if (!outfile)
	{
		cerr << "OPEN ERROR!" << endl;
		exit(0);
	}
	num3 = rand() % 4;
	sort(min, max);
	Simplification(num[0], num[3]);
	Simplification(num[1], num[2]);
	ss1 << num[0];
	ss1 >> strr2;
	ss2 << num[1];
	ss2 >> strr3;
	ss3 << num[2];
	ss3 >> str5;
	ss4 << num[3];
	ss4 >> str6;
	if ((str5 != strr3) && (str6 != strr2))                                             //�������ɷ��ӷ�ĸ��ȵı��ʽ
		str = "(" + str5 + "/" + strr3 + ")" + str1[num3] + "(" + str6 + "/" + strr2 + ")";
	else if (str5 == strr3)
		str = str5 + str1[num3] + "(" + str6 + "/" + strr2 + ")";
	else if (str6 == strr2)
		str = "(" + str5 + "/" + strr3 + ")" + str1[num3] + str6;
	n = n - 4;
	while (n != 0)                 //��n������0ʱ��ѭ������str�������ʽ+����+���ʽ����ʽ
	{
		num4 = rand() % 2;
		if (num4 == 0)             //��һ��str���ڷ��ŵ����
		{
			sort1(min, max);
			Simplification(num[4], num[5]);
			num3 = rand() % 4;
			ss5 << num[4];
			ss5 >> str7;
			ss6 << num[5];
			ss6 >> str8;
			if (str7 != str8)                                                //�������ɷ��ӷ�ĸ��ȵı��ʽ
				str9 = "(" + str8 + "/" + str7 + ")";
			else
				str9 = str8;
			str = str + str1[num3] + str9;
		}
		else                              //��һ��str���ڷ��ŵ��ұ�
		{
			sort1(min, max);
			Simplification(num[4], num[5]);
			num3 = rand() % 4;
			ss7 << num[4];
			ss7 >> str7;
			ss8 << num[5];
			ss8 >> str8;
			if (str7 != str8)                                                         //�������ɷ��ӷ�ĸ��ȵı��ʽ
				str9 = "(" + str8 + "/" + str7 + ")";
			else
				str9 = str8;
			str = str9 + str1[num3] + str;
		}
		n = n - 2;
	}
	string result1, result2;
	str4[p] = str;                         //��str�����ַ�������str4��
	for (int i = 0; i<p; i++)                 //��ѯ��������ʽ�Ƿ����ظ�
		if (str4[i] == str4[p])
			Input2(m, p, min, max, j, q);
	cout << str4[p] << "=";
	result2 = OPeration(str);
	cin >> result1;
	if (result1 == result2)
	{
		cout << "������ȷ";
		j++;
	}
	else
	{
		cout << "�������,����" << setprecision(2) << fixed << result2;
		q++;
	}
	outfile << str4[p] << endl;
	cout << endl;
}
void changeNum(int n, int y, int min, int max)
{
	int j = 0, q = 0, num6;
	if (y == 1)
	{
		for (int i = 0; i<n; i++)
		{
			num6 = rand() % 9 + 2;
			switch (num6)
			{
			case 2:Input(2, i, min, max, j, q); break;
			case 3:Input(3, i, min, max, j, q); break;
			case 4:Input(4, i, min, max, j, q); break;
			case 5:Input(5, i, min, max, j, q); break;
			case 6:Input(6, i, min, max, j, q); break;
			case 7:Input(7, i, min, max, j, q); break;
			case 8:Input(8, i, min, max, j, q); break;
			case 9:Input(9, i, min, max, j, q); break;
			case 10:Input(10, i, min, max, j, q); break;
			}
		}
		cout << "���β��Խ���" << endl;
		cout << "��ȷ----" << j << "����,����----" << q << "����" << endl;
		cout << "***************************************" << endl;
	}
	else
	{
		for (int i = 0; i<n; i++)
		{
			num6 = rand() % 9 + 2;
			switch (num6)
			{
			case 2:Input1(2, i, min, max, j, q); break;
			case 3:Input1(3, i, min, max, j, q); break;
			case 4:Input1(4, i, min, max, j, q); break;
			case 5:Input1(5, i, min, max, j, q); break;
			case 6:Input1(6, i, min, max, j, q); break;
			case 7:Input1(7, i, min, max, j, q); break;
			case 8:Input1(8, i, min, max, j, q); break;
			case 9:Input1(9, i, min, max, j, q); break;
			case 10:Input1(10, i, min, max, j, q); break;
			}
		}
		cout << "���β��Խ���" << endl;
		cout << "��ȷ----" << j << "����,����----" << q << "����" << endl;
		cout << "***************************************" << endl;

	}
}
void changeNum1(int n, int min, int max)
{
	int j = 0, q = 0, p, num6;
	for (int i = 0; i<n; i++)
	{
		num6 = rand() % 4;
		p = 4 + 2 * i;                               //��ʾ���ɵĲ������ĸ���
		switch (p)
		{
		case 4:Input2(4, i, min, max, j, q); break;
		case 6:Input2(6, i, min, max, j, q); break;
		case 8:Input2(8, i, min, max, j, q); break;
		case 10:Input2(10, i, min, max, j, q); break;
		}
	}
	cout << "���β��Խ���" << endl;
	cout << "��ȷ----" << j << "����,����----" << q << "����" << endl;
	cout << "***************************************" << endl;
}
int main()
{
	int x, y, max, min;
	srand((unsigned)time(NULL));
	ofstream outfile1;
	outfile1.open("a.txt");
	if (!outfile1)
	{
		cerr << "OPEN ERROR!" << endl;
		exit(0);
	}
	cout << "------------�Զ���������ϵͳ---------------" << endl;
	cout << "         1.��������������                  " << endl;
	cout << "         2.���������������                " << endl;
	cout << "         3.�˳�                            " << endl;
	for (;;)
	{
		cout << "��ѡ��";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			cout << "ȡֵ��Χ��Сֵ�����ڵ���1����";
			cin >> min;
			cout << "ȡֵ��Χ���ֵ��";
			cin >> max;
			cout << "��(��)��������(ע�ͣ��������������ţ��Է��γ�6/3/2����ʽ)---�У�1�����ޣ�0����";
			cin >> y;
			cout << "��Ŀ������";
			cin >> n;
			cout << "       ���Կ�ʼ          " << endl;
			changeNum(n, y, min, max);
			break;
		}
		case 2:
		{
			cout << "ȡֵ���ӷ�ĸ��Χ��Сֵ�����ڵ���1����";
			cin >> min;
			cout << "ȡֵ���ӷ�ĸ��Χ���ֵ�����ڵ���1����";
			cin >> max;
			cout << "��Ŀ������";
			cin >> n;
			cout << "       ���Կ�ʼ          " << endl;
			changeNum1(n, min, max);
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		}
	}
	return 0;
}