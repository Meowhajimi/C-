#include <iostream>
using namespace std;

//递推只关心变化而不关心数目
int main()
{
	//正方体堆积递推:
	//构建递推表达式 f(n) = f(n-1) + n 
	int start = 1;

	int end;
	cin >> end;

	for (int n = 2; n <= end; n++)
	{
		int tmp = start;
		start = tmp + n;
	}

	cout << start;
	//key 表达递推式 f(n) = f(n-1) + n需要一个for循环的i助力以及自己加自己的行为
	//猴子摘桃问题
	//f(n) = f(n-1)/2 - 1
	//f(10)

}