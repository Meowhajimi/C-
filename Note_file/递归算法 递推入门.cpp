#include <iostream>
using namespace std;

int f(int n) //递归函数要求计算一个等差数列的前n项和，首项为1
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int rst = f(n - 1) + 3;
	}
}
int g(int n) //计算一个等比数列的前n项和
{
	if (n == 1)
	{
		return 2;
	}
	else
	{
		int tmp = g(n - 1)*2; //be like {{{{{end function。。。}}}}}
		return tmp;
	}
}
int h(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		int tmp = n*h(n - 1);
		return tmp;
	}
}
//总结 遇见自己调用自己的函数就像想把它横向从左至右展开，然后再从最右边退回左边返回最左值  一定要明白括号里的n对应的是执行次数
//但是 递归的局限性是无法忽视的，就比如计算斐波那契数列f(n) = f(n-1) + f(n-2)
//每一个p都会分叉出两个p函数，导致复杂度指数级提示
int p(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
	    int tmp = p(n - 1) + p(n - 2);
	    return tmp;
	}
}

int main()
{
	cout << f(5) << endl;
	cout << g(6) << endl;
	cout << h(5) << endl;

	for (int i = 3; i <= 40; i++)
	{
		cout << i << ":" << p(i) << endl; //极其吃复杂度
	}
	//递推：f(n) = f(n-1) + f(n-2)
    long long array[55] = { 0 }; //初始化为0,怕溢出
	array[1] = 1;
	array[2] = 2;
	for (int i = 3; i <= 50; i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
	for (int i = 0; i < 51; i++)
	{
		cout << array[i] << endl;
	}
	
	
}