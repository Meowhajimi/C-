//预处理（导入各个文件） 编译（为汇编语言） 然后转化为一堆0和一（好几份文件的0与1） 链接所有文件的0，1让计算机看得懂
#include <stdlib.h>   // strtol, errno
#include <ctype.h>    // isspace
#include <errno.h>    // errno
#include <limits.h>   // INT_MAX, INT_MIN
#include<stdio.h>

void print_column(int height);
int get_int(const char* prompt);

int main()
{
	//for (int i = 0; i <= 3; i++)
	//{
	//	printf("i is %i\n", i); //使用printf调试，用完删掉
	//	printf("#\n");
	//}
    int h = get_int("number:"); //左边的红点可以锚定调试过程,启动时开始进行调试，可以选择一步步语句跳过去调试➡可以保证一行行读过去，⬇可以跳到对应的函数内部
    print_column(h);
	
}
void print_column(int height) 
{
    for (int i = 0; i < height; i++)
    {
        printf("#\n");

    }

}



int get_int(const char* prompt)
{
    char buffer[1024];  // 足够容纳绝大多数输入
    char* endptr;
    long val;
    int result;

    while (1) {
        // 1. 输出提示
        fputs(prompt, stdout);
        fflush(stdout);   // 确保立即显示

        // 2. 读取整行输入
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // 如果遇到 EOF (Ctrl+D/Z)，可以选择退出或返回默认值
            // 这里简单返回 0，实际可改为更合适的错误处理
            return 0;
        }

        // 3. 跳过前导空白字符（空格、制表符等）
        char* p = buffer;
        while (isspace((unsigned char)*p)) {
            p++;
        }

        // 4. 检查是否为空输入或明显不是数字
        if (*p == '\0') {
            printf("Retry: ");
            continue;
        }

        // 5. 使用 strtol 尝试转换（自动跳过前导空格，但我们已经手动跳过了）
        errno = 0;
        val = strtol(p, &endptr, 10);

        // 6. 检查是否转换了任何字符（即 p 和 endptr 是否相同）
        if (endptr == p) {
            // 第一个非空白字符不是数字或正负号
            printf("Retry: ");
            continue;
        }

        // 7. 检查是否溢出 int 范围
        if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
            printf("Retry: ");
            continue;
        }

        // 8. 检查转换后是否还有多余的“非空白”字符
        //    跳过剩余的空白字符（如换行、空格等）
        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }
        if (*endptr != '\0') {
            // 还有非空白字符（如 "123abc"）
            printf("Retry: ");
            continue;
        }

        // 9. 所有检查通过，返回整数值
        result = (int)val;
        return result;
    }
}