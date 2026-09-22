#include<stdio.h>
//乘法口诀表
int main()
{
	//int m = 1;
	//for (int i = 1; i <= 9;i++)
	//{
	//	for (int j = m; j <= 9; j++)
	//	{
	//		printf(" %ix", i);
	//		printf("%i", j);
	//		printf("=%i", (int)i * j);
	//	}
	//	printf("\n");
	//	m++;
	//	
	//}
	//优化版
	for (int i = 1; i <= 9; i++)
	{
		for (int j = i; j <= 9; j++)
		{
			printf("%d x %d = %2d", i, j, i * j);
		}
		printf("\n");
	}
}