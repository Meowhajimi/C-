#include <stdio.h>
#include <stdlib.h>   // strtol, errno
#include <ctype.h>    // isspace
#include <errno.h>    // errno
#include <limits.h>   // INT_MAX, INT_MIN
int get_int(const char* prompt);

int main()
{
	int a = 10;
	int b = 5;
    long dollars = 1; //64位，即可以容纳2的八次方那么大的数0-2的八次方-1，int是32位多了溢出
    while (1 < 2)
    {
        printf("the dollar is %li.would you send second person and double it?", dollars);
        int agreement = get_int("");
        if (agreement == 1)
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
      
    }
	printf("%i\n", a + b);
    printf("%i\n", get_int("x:") + get_int("y:"));

    //下面是小数运算
    int i = get_int("x");
    int j = get_int("y");

    printf("%i",i/j);//错误示范 截断小数部分
    printf("%.5f", (float)i / j);//正确 让计算器视ij为float 保留5位小数，但精度太大也会出现problem
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