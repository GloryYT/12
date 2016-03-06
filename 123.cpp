//2016 3.6 Lowry  软件工程作业 随机生成30道四则运算 包括整数和真分数
#include <iostream> 
#include <stdlib.h> 
#include <time.h> 

using namespace std;

int main()
{
	int a, b, c, d, i, j;
	srand((unsigned)time(NULL));
	for (j = 30; j > 0; j--)
	{
		char operator_lib[4] = { '+', '*', '/', '-' }; //定义运算符的可选类型
		int rand_oper_idx = rand() % 4;                //然后随机生成，上述数组的下标就可以了。
		char cur_oper = operator_lib[rand_oper_idx];				
		i = rand() % 2;
		switch (i)
		{
		case 0:
			a = rand() % 100; //a取值为0~99
			c = rand() % 100; //c取值为1~99
			if (cur_oper == '/')
			{
				if (c == 0)
				{
					c = rand() % 99+1;					
				}
				cout << a << cur_oper << c << " = " << endl;
			}
			else
			cout << a << cur_oper << c << " = " << endl;
			break;
		case 1:
			a = rand() % 99 + 1; //a取值为1~99
			b = rand() % a;    //保证b小于a		
			c = rand() % 99 + 1; //c取值1~99
			d = rand() % c ;  //保证d小于d 0~c-1
			if (cur_oper == '/')
			{
				if (d == 0)
				{
					d = d + 1;
					c = rand() % 98 + 2;

				}
				cout << b << "/" << a << " " << cur_oper << " " << d << "/" << c << "=" << endl;
			}
			else
				cout << b << "/" << a << " " << cur_oper << " " << d << "/" << c << "=" << endl;			
			break;
		}
	}
	return 0;
}



