#include<stdio.h>
#include <stdlib.h>   // strtol, errno
#include <ctype.h>    // isspace
#include <errno.h>    // errno
#include <limits.h>   // INT_MAX, INT_MIN
#define N 5
//const int N = 3; C++可以这么写

float average(int lengths, int array[]);
int get_int(const char* prompt);


int main(void)
{
	//int score1 = 73; //使用这行代码会产生的缺点是可操作性差，得一个又一个的加变量，太麻烦了
	//int score2 = 72;
	//int score3 = 36;

	////计算平均数
	//printf("the average is %.5f", (score1 + score2 + score3) / 3.0); //此处若是使用3，会误认为是整数从而产生截断情况
	//接下来引入数组的概念
	int scores[N];

    for (int i = 0; i < N; i++)
    {
        printf("enter your int %i :", i + 1);
        scores[i] = get_int("");
        
    }
    printf("The result is : %.1f", average(N,scores));
}

//计算平均数的泛化程序
float average(int lengths, int array[])
{
    float sum = 0.0;
    for (int i = 0; i < lengths; i++)
    {
        sum += (float) array[i];
    }
    return sum / (float)lengths;
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