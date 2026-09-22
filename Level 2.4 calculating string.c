#include<stdio.h>
#include"cs50_utils.h"
#include<string.h>

//int length_string(string n);

int main(void)
{
	//尝试计算字符串长度 自己做函数计算
	string name = get_string("Name:");
	//printf("%i",length_string(name));
	int length = strlen(name); //调用函数计算长度
	printf("%i", length);
	return 0;
}



//int length_string(string n) 
//{
//	int s = 0;
//	while (n[s] != '\0')
//	{
//		s++;
//	}
//	return s;
//}