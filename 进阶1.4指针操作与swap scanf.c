#define _CRT_SECURE_NO_WARNINGS //防止微软抽风scanf报错（这个一定要写在头顶）
#include<stdio.h>

void swap(int* a, int* b);

int main(void)
{   //指针的一堆操作（前置）
	int Var = 10; 
	int* p1 = (int *) & Var;// 若打印，则*p1 = 10  漏掉&则认为p1就是10这个地址00000000000A
	int* p2 = p1;
	printf("%p\n", p1); //这里的操作就是：p1本身装的是var的地址，打印的是var的地址所在地
	//printf("%p\n", *p1);//这里的报错是因为%p要解析一个8位的地址（拉出八位数据），而*p1为10,转义为0000000000A无法打印相应的内容
	printf("%p\n", &p1);//这里打印的是指针p1的内存地址，是指针的指针
	//开始实现swap
	int x = 10;
	int y = 20;

	printf("%i%i\n", x, y);

	swap(&x, &y);

	printf("%i%i", x, y);
	//get int的实现
	int n;
	printf("n:");
	scanf("%i", &n); //这下懂了为什么是&n了吧
	printf("%i", n);

	
}

void swap(int* a, int* b) //若是传入参数不是指针，物理地址无法修改，只是把xy拷贝了一份起不到交换的作用
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}