#include "cs50_utils.h"
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	//char* s = get_string("s:");
	//char* t = get_string("t:");

	//if (strcmp(s, t) == 0) //如果是 s == t,比较的是指针地址而不是字符串本身
	//{
	//	printf("Same");
	//}
	//else
	//{
	//	printf("Different");
	//}
	
	//char* s = get_string("s: ");
	//char* t = s;

	//t[0] = toupper(t[0]); //在这里，st均指向唯一的字符串，当这个唯一的字符串被修改时st的内容均会发生修改
	//printf("%s%s", s, t); 

	char* s = get_string("s: ");
	char* t = malloc(strlen(s) + 1); //为t创建一个新的内存，用于存放内容以及\0,返回值为内存的第一个格子如0x123 0x124，返回0x123

	if (t == NULL) //没有内存了，返回一手NULL
	{
		return 1;
	}
	//for (int i = 0, n = strlen(s); i <= n; i++) //小于等于n是为了复制空字符
	//{
	//	t[i] = s[i]; //此时编译器将其翻译为从从地址t+I取出字节并进行赋值 
	//}
	strcpy(t, s); //当然，复制可以直接掉用一个函数
	if (strlen(t) > 0)
	{
		t[0] = toupper(t[0]);
		printf("%s%s", s, t);
	}
	else
	{
		printf("SB"); //一定要错误检查，不然内存就出问题了
	}
	
	free(t); //避免这个内存一直被占用在不用t之后

	return 0;
}

