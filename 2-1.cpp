//2016 3.6 Lowry  软件工程作业 随机生成30道四则运算 包括整数和真分数
#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int numb1, numb3,j,Numb_Title,Num_Max,Mul_Div,Div,fuShu,Bracket;
	cout << "请输入你需要的题目数目:" << endl;
	cin >> Numb_Title;  //添加一个变量，满足第二组作业的条件之一
	cout << "输入你想得到的数值范围中的最大数(不包括这个数):" << endl;
	cin >> Num_Max;
	cout << "是否得到有括号的多部四则运算,有括号输入1,没有的话输入2:(没有完成这个功能，请选择2)" << endl;
	cin >> Bracket;
	if (Bracket == 2)//无括号的多功能运算
	{
		cout << "运算包括乘除法吗？包括的话输入1,不包括输入0:" << endl;
		cin >> Mul_Div;
		if (Mul_Div == 1)
		{
			cout << "整数除法符合整除吗？符合的话输入1,不符合的话输入0:" << endl;
			cin >> Div;
		}
		else
			Div = 0;
		cout << "加减的结果允许出现负数吗，允许输入1,不允许输入0:" << endl;
		cin >> fuShu;
		switch (fuShu)
		{
		case 0://加减不允许出现负数
			switch (Div)//1符合整除，0不符合整除
			{
			case 1://除法符合整除
				switch (Mul_Div)//包括的功能 是否包括乘除法
				{
				case 1://包括乘除法 情况 1 1 0
					for (j = Numb_Title; j > 0; j--)//需要的题目数
					{
						char operator_lib[4] = { '+', '*', '/', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 4;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						//生成整数运算
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为0~Num_Max-1
						if (cur_oper == '/')//除法的情况下
						{
							numb3 = rand() % (numb1 - 1) + 1;//确保numb3小于numb1且排除0	
							while (numb1%numb3 != 0)//确保整除
							{
								numb3 = rand() % (numb1 - 1) + 1; //c取值为0~Num_Max-1;
							}
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						else if (cur_oper == '-')
						{
							numb3 = rand() % numb1;//确保计算结果没有负数
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						cout << numb1 << cur_oper << numb3 << " = " << endl;
					}
					break;
				}
				break;
			case 0://除法不符合整除
				switch (Mul_Div)//包括的功能 是否包括乘除法
				{
				case 1://包括乘除法
					for (j = Numb_Title; j > 0; j--)//需要的题目数
					{
						char operator_lib[4] = { '+', '*', '/', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 4;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为1~Num_Max-1
						if (cur_oper == '/')//除法的情况下
						{
							if (numb3 == 0)
							{
								numb3 = rand() % (Num_Max - 1) + 1;
							}
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						else if (cur_oper == '-')
						{
							numb3 = rand() % numb1;//确保计算结果没有负数
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						else
						{
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}										
					}
					break;

				case 0:  //不包括乘除法
					for (j = Numb_Title; j > 0; j--)
					{
						char operator_lib[2] = { '+', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 2;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为0~Num_Max-1	
						if (cur_oper == '-')
						{
							numb3 = rand() % numb1;//确保计算结果没有负数
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						cout << numb1 << cur_oper << numb3 << " = " << endl;
					}
				}
				break;
			}
			break;
		case 1://加减允许出现负数
			switch (Div)//1符合整除，0不符合整除
			{
			case 1://除法符合整除
				switch (Mul_Div)//包括的功能 是否包括乘除法
				{
				case 1://包括乘除法 情况 1 1 0
					for (j = Numb_Title; j > 0; j--)//需要的题目数
					{
						char operator_lib[4] = { '+', '*', '/', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 4;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						//生成整数运算
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为0~Num_Max-1
						if (cur_oper == '/')//除法的情况下
						{
							numb3 = rand() % (numb1 - 1) + 1;//确保numb3小于numb1且排除0	
							while (numb1%numb3 != 0)//确保整除
							{
								numb3 = rand() % (numb1 - 1) + 1; //c取值为0~Num_Max-1;
							}
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						else
							cout << numb1 << cur_oper << numb3 << " = " << endl;
					}
					break;
				}
				break;
			case 0://除法不符合整除
				switch (Mul_Div)//包括的功能 是否包括乘除法
				{
				case 1://包括乘除法
					for (j = Numb_Title; j > 0; j--)//需要的题目数
					{
						char operator_lib[4] = { '+', '*', '/', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 4;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为1~Num_Max-1
						if (cur_oper == '/')//除法的情况下
						{
							if (numb3 == 0)
							{
								numb3 = rand() % (Num_Max - 1) + 1;
							}
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
						else
						{
							cout << numb1 << cur_oper << numb3 << " = " << endl;
						}
					}
					break;
				case 0:  //不包括乘除法
					for (j = Numb_Title; j > 0; j--)
					{
						char operator_lib[2] = { '+', '-' }; //定义运算符的可选类型
						int rand_oper_idx = rand() % 2;                //然后随机生成，上述数组的下标就可以了。
						char cur_oper = operator_lib[rand_oper_idx];
						numb1 = rand() % Num_Max; //a取值为0~Num_Max-1
						numb3 = rand() % Num_Max; //c取值为0~Num_Max-1	
						cout << numb1 << cur_oper << numb3 << " = " << endl;
					}
				}
				break;
			}
			break;
		}
	}
	else//有括号的多部四则运算实现
	{
//没有实现
	}
	return 0;
}



