//There is notes 1.ctrl+` can open final commend window/ctrl + L can clean commemd-line
//               2.ctrl+F5 can run your program 3 ctrl + c 退出命令行
#include<stdio.h> //头文件可以按首字母来排序
#include <stdlib.h>
#include <string.h>

int main(void)
{
	printf("hello world\n\n\nyou\n"); // /n is in order to shift the line from one to two or other line
	
	printf("hello \"world\"\n");     // if computer wouldn't want to recognize the ""，you can add / inside and outside
	
	printf("\\");                     // print \ need two \,if words are swallowed, enter ins.

	char answer[100]; //开辟大小为100的内存空间，可以存入99个字符
	

	printf("what are your actual name ");

	fgets(answer, sizeof(answer), stdin); //字面意思：调用安全读取函数 fgets，把读取到的内容放进 answer 里，最多读取 sizeof(answer) 个字节，从哪里读？从标准输入设备（stdin，即键盘）读。

	printf("hello,%s\n", answer); //把answer装到s%的位置,%i是整数，是同理的

	return 0;
    
}         