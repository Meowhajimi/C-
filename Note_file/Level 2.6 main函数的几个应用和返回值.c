#include "cs50_utils.h"
#include <stdio.h>
//main函数的参数，返回值与的应用 echo %ERRORLEVEL%可以显示退出码（Cmd）echo $LASTEXITCODE 本编译器 echo $?MACos or Linux         
int main(int argc, string argv[])
{
	if (argc == 2)
	{
		printf("hello, %s \n", argv[1]);
		return 0;

	}
	else
	{
		printf("hello, world");
		return 1;
	}
	for (int i = 0; i < argc; i++)
	{
		printf("%s", argv[i]);
	}
	
}