#include<iostream>
using namespace std;
#define N 100
int main()
{
	int p, num, value, max, count = 0;
	int val[N];                                      //ԭʼ����
	int Array[N];                                      //��������ɵ�����
	int ArrayMax[N];                                   //���ÿ���������ֵ
	int ArrayFisrtLast[N][N];                          //�������������ÿ��Ԫ��
	int ArrayNum[N][N];                               //������������Ԫ�صĸ���
	cout << "�������ĸ�����";
	cin >> num;
	for (int i = 0; i<num; i++)                             //����Ԫ��
	{
		cin >> val[i];
	}
	for (int i = 0; i<num; i++)
	{
		int firstNum = 0, lastNum = 0, q = 0;                   //��������鿪ʼλ�ã�firstNum��,������λ�ã�lastNum��
		value = 0;
		p = i;
		for (int k = 0; k<num; k++)                           //���¿���һ��������Array�������ԭʼ�����ÿ��Ԫ�ؿ�ͷ������
		{
			p = p%num;
			Array[k] = val[p];
			p++;
		}
		max = 0;
		for (int j = 0; j<num; j++)                              //�ҳ����������
		{
			value = value + Array[j];
			if (value>max)                                      //�ۼӺʹ���max���ۼӺ͸�ֵ��max              
			{
				max = value;
				lastNum = j;
			}
			if (value<0)                                // ��ǰ��С��0������Ϊ0  
			{
				value = 0;
				firstNum = j + 1;
			}
		}
		if (max<0)                                 // ������ȻΪ0��˵������������Ԫ�ض�Ϊ��ֵ
		{
			max = val[0];
			firstNum = 0;
			lastNum = 0;
			for (int j = 0; j<num; j++)
			{
				if (max<Array[j])
				{
					max = val[j];
					firstNum = j;
					lastNum = j;
				}
			}
		}
		ArrayMax[count] = max;
		for (int m = firstNum; m <= lastNum; m++)
		{
			ArrayFisrtLast[count][q] = Array[m];
			q++;
		}
		ArrayNum[count][0] = lastNum - firstNum + 1;
		count++;
	}
	max = ArrayMax[0];
	int n = 0;
	for (int i = 0; i<count; i++)
	{
		if (max<ArrayMax[i])
		{
			max = ArrayMax[i];
			n = i;
		}
	}
	cout << "����������ǣ�";
	for (int i = 0; i<ArrayNum[n][0]; i++)
	{
		cout << ArrayFisrtLast[n][i] << " ";
	}

	cout << endl;
	cout << "���������ĺ�Ϊ��";
	cout << max << endl;
	return 0;
}