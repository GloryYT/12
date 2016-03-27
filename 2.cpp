#include<iostream>
using namespace std;
#define N 100
int main()
{
	int p, num, value, max, count = 0;
	int val[N];                                      //原始数组
	int Array[N];                                      //存放新生成的数组
	int ArrayMax[N];                                   //存放每个数组最大值
	int ArrayFisrtLast[N][N];                          //存放最大子数组的每个元素
	int ArrayNum[N][N];                               //存放最大子数组元素的个数
	cout << "输入数的个数：";
	cin >> num;
	for (int i = 0; i<num; i++)                             //输入元素
	{
		cin >> val[i];
	}
	for (int i = 0; i<num; i++)
	{
		int firstNum = 0, lastNum = 0, q = 0;                   //最大子数组开始位置（firstNum）,结束的位置（lastNum）
		value = 0;
		p = i;
		for (int k = 0; k<num; k++)                           //重新开辟一个新数组Array，存放以原始数组的每个元素开头的数组
		{
			p = p%num;
			Array[k] = val[p];
			p++;
		}
		max = 0;
		for (int j = 0; j<num; j++)                              //找出最大子数组
		{
			value = value + Array[j];
			if (value>max)                                      //累加和大于max，累加和赋值给max              
			{
				max = value;
				lastNum = j;
			}
			if (value<0)                                // 当前和小于0，重置为0  
			{
				value = 0;
				firstNum = j + 1;
			}
		}
		if (max<0)                                 // 最大和依然为0，说明数组中所有元素都为负值
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
	cout << "最大子数组是：";
	for (int i = 0; i<ArrayNum[n][0]; i++)
	{
		cout << ArrayFisrtLast[n][i] << " ";
	}

	cout << endl;
	cout << "最大子数组的和为：";
	cout << max << endl;
	return 0;
}