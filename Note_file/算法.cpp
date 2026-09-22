#include <iostream>
#include <vector>

using namespace std;

bool get_mol(int a)
{
	//int b_first = (int)(a / 2); //a 2均为int 在进行运算时精度已经丢失
	//float b = (float)(a / 2);
	//if ((float)(b - b_first) < 0 || (b - b_first) > 0)
	//{
	//	
	//	return false;
	//}
	//else
	//{
	//	return true;
	//}

	return (a % 2 == 0);
}

int main(void)

{
	//我得对拼出来的数字找到最大值
	//我得尽可能的优先拼出大的数字
	//使用map还是普通的数组？
	//输入较大的num时会产生多种拆解方案
	//n = 1时啥都木有 
	//range 2~7
	//先处理没有余数的数字
	//如 1
	//理论上，对于任何一个数，>1，扣掉以后是可以找到合适的数的
	//计算range：有几位？
	vector <int> Store_num(50, 0);//最笨：100兑换了50个2填上去
	//如何处理大于等于8的火柴？
	int n;
	cin >> n; //n ~ 1 - 100

	//先尝试位数优先

	int Value[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	int Key[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//将一个数拆拆拆，到最小的不可分单元if n == 0 修改表格 if n == 1 拆解失败
	// 先尝试将一个数 除以二,求模为0
	
	if (get_mol(n) == true)
	{

	}
    
	

	return 0;
}