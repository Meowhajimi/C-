#include<stdio.h>
#include"cs50_utils.h"

void brick_print(int n); //双重循环打印
void draw(int n); //递归打印

int main()
{
	int heigh = get_int("Heigh: ");

	brick_print(heigh);

	draw(heigh);

}

void brick_print(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	
}

void draw(int n)
{
	if (n <= 0) 
	{
		return;
	}

	draw(n - 1); //理解：当执行draw0时，draw0会被直接退出返回空，然后计算机向上开始执行一开始没有执行的draw1，2，3对应的for循环

	for (int i = 0; i < n; i++) //为什么计算机不会优先执行draw3而是draw1？因为计算机会把函数包在一个叫栈帧的地方，然后把函数像叠纸一样由下到上地叠在栈帧内，谁在上面就执行谁，所以一开始的顺序为3210叠的函数的顺序自然就是0123了。
	{
		printf("#");
	}
	printf("\n");
}