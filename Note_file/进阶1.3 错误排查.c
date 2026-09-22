#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int* i = malloc(3 * sizeof(int));
	i[0] = 10;
	i[1] = 20;
	i[2] = 30; //存在一个错误：没有释放内存。容易被注意的误区：容易从i[1]开始编码

	free(i);


}