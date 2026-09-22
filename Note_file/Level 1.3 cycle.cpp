#include <stdio.h>
#include <stdlib.h>   // strtol, errno
#include <ctype.h>    // isspace
#include <errno.h>    // errno
#include <limits.h>   // INT_MAX, INT_MIN
int get_positive_int(void);
int get_int(const char* prompt);

void meow_for(int n);  //申明函数。让编译器知道它的存在
void meow_while(int n);

int main(void)
{
    //int times;
    //do
    //    times = get_int("times:"); //不要在这里面定义times，作用范围跑不到。
    //while (times < 1);
    //
    //meow_for(times);

    int times = get_positive_int();

    meow_for(times);

}


















/**
 * 功能：提示用户输入一个整数，若输入无效则不断重试。
 * 参数：prompt - 显示给用户的提示字符串
 * 返回：成功读取的 int 值（如果遇到 EOF 则返回 0，可根据需要调整）
 */
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
int get_positive_int(void)
{
    int n;
    do
        n = get_int("Enter correct repeating number:");
    while (n < 1);
    return n;
}
void meow_for(int n) //定义函数时，按照首字母排序放在后面更符合习惯
{
	for (int i = 0; i < n; i++)
	{
		printf("meow\n");
	}
	
}
void meow_while(int n)
{
	int i = 0;
	while (i < n)
	{
		printf("meow\n");
		i++;
	}
}
