#include<iostream>
using namespace std;
#define N 1000
int main()
{
	int num, value, max = 0;
	int val[N];
	int Array[N];
	int firstNum = 0, lastNum = 0;
	cout << "�������ĸ�����";
	cin >> num;
	for (int i = 0; i<num; i++)
	{
		cin >> val[i];
	}
	value = 0;
	for (int i = 0; i<num; i++)
	{
		value = value + val[i];
		if (value>max)
		{
			max = value;
			lastNum = i;
		}
		if (value<0)
		{
			value = 0;
			firstNum = i + 1;
		}
	}
	if (max == 0)
	{
		max = val[0];
		firstNum = 0;
		lastNum = 0;
		for (int j = 0; j<num; j++)
		{
			if (max<val[j])
			{
				max = val[j];
				firstNum = j;
				lastNum = j;
			}
		}
	}
	cout << "����������ǣ�";
	for (int i = firstNum; i <= lastNum; i++)
	{
		cout << val[i] << " ";
	}
	cout << endl;
	cout << "���������ĺ�Ϊ��";
	cout << max << endl;
}