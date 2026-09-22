#include"cs50_utils.h"
#include<stdio.h>
#include<string.h>

int main(void)
{
	FILE* file = fopen("phoneBook.csv", "w"); //w代表写入模式
	if (file == NULL)
	{
		perror("failure opening"); //错误检查
		return 1;
	}
	char* name = get_string("Name: ");
	char* numbers = get_string("Numbers: ");

	fprintf(file, "%s,%s\n", name, numbers); //打到文件里

	printf("Success!");
	fclose(file); //详细请见CS50 week 4

}