#include <stdio.h>
#include <string.h>
#include "cs50_utils.h"

int main(void)
{
	//char c1 = 'H'; // 单引号是单个字符，不是字符串
	//char c2 = 'I';
	//char c3 = '!';
	//char C[4] = "HI!";
	//printf("%c %c %c", c1, c2, c3);
	//printf("%i %i %i", c1, c2, c3); //视他们为数字 例如 string s = "HI!"创建了大小为4，前三位分别为H，I,!而最后一位是\0，这个标识符存在的目的是为了让计算机识别到结束。
	////printf("%i ", C[3]); //若是这里只分配了3 C[3]空间，就无法打印出0，因为被截断了
	//printf("%i", C[3]);
	//char names[][10] = { "Alice", "Bob", "Charlie" }; //任意个字符串，每个串包含少于等于10个字符 C语言原生方法
	//printf("%c%c%c", names[0][0], names[0][1], names[0][2]);
	string words[2];
	words[0] = "HI";
	words[1] = "BYE";
	printf("%c\n", words[0][0]);
	printf("%s", words[0]);

	return 0;

}