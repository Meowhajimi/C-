#include "cs50_utils.h"
#include<ctype.h>
#include<stdio.h>
#include<string.h>


int main(void)
{
	string name = get_string("Input :");

	for (int i = 0, n = strlen(name); i < n; i++)
	{
		printf("%c", name[i]); //遍历字符串的每一个字母，预防函数strlen反复调用
	}
	printf("\n");
	//下面做一个小写转大写的程序

	for (int i = 0, j = strlen(name); i < j; i++)
	{
		printf("%c", toupper(name[i])); //方法二 直接包含函数比较
		//if (name[i] >= 'a' && name[i] <= 'z') //比较ASCII码的大小
		//{
		//	
		//	printf("%c", name[i] - ('a' - 'A')); //方法1：大小写的ASCII差32 ,a比A大32
		//}
		//else
		//{
		//	printf("%c", name[i]);
		//}

	}
	printf("\n");
}    