#include<stdio.h>

char my_get_char(const char* prompt)
{
	char c;
	int ch;
	while (1) {
		printf("%s", prompt);
		// 读取第一个非空白字符
		while ((ch = getchar()) != EOF && ch == ' ');  // 跳过空格
		if (ch == EOF) return 0;
		c = ch;
		// 清空剩余的输入行（包括换行符）
		while ((ch = getchar()) != EOF && ch != '\n');
		// 检查是否只输入了一个字符（即下一个字符是换行符，或已到结尾）
		// 这里我们简单地返回第一个字符，但为了严格校验需要检查后面是否还有字符
		// 简化版：直接返回
		return c;
	}
}
int main()
{
	printf("agree?");
	
	char c = my_get_char("enter your name");
	
	if (c == 'y' || c == 'Y')
	{
		printf("ok\n");
	}
	else if (c == 'n' || c == 'N')
	{
		printf("forgive\n");
	}
	else if (c == '1' && c == '2');
	{ 
		printf("thanks\n");
	}

	return 0;
}