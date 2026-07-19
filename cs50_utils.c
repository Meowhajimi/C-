#include "cs50_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

// ------------------------ get_string (核心) ------------------------
char* get_string(const char* prompt) {
    if (prompt != NULL) {
        printf("%s", prompt);
        fflush(stdout);
    }

    size_t capacity = 128;
    char* buffer = malloc(capacity);
    if (buffer == NULL) return NULL;

    size_t len = 0;
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
        if (len + 1 >= capacity) {
            size_t new_cap = capacity * 2;
            char* new_buf = realloc(buffer, new_cap);
            if (new_buf == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = new_buf;
            capacity = new_cap;
        }
        buffer[len++] = (char)ch;
    }

    if (len == 0 && ch == EOF) {
        free(buffer);
        return NULL;   // 表示 EOF
    }

    buffer[len] = '\0';

    // 缩小内存（可选）
    char* shrunk = realloc(buffer, len + 1);
    return shrunk ? shrunk : buffer;
}

// ------------------------ 内部辅助：处理 EOF 退出 ------------------------
static void handle_eof(void) {
    printf("\n");          // 换行使界面整洁
    exit(EXIT_SUCCESS);    // CS50 遇到 Ctrl+D/Z 直接退出
}

// ------------------------ get_int ------------------------
int get_int(const char* prompt) {
    while (1) {
        char* line = get_string(prompt);
        if (line == NULL) handle_eof();

        char* endptr;
        errno = 0;
        long val = strtol(line, &endptr, 10);

        // 检查：无字符被转换、存在多余字符、溢出、超出 int 范围
        if (errno == 0 && endptr != line && *endptr == '\0' &&
            val >= INT_MIN && val <= INT_MAX) {
            free(line);
            return (int)val;
        }

        free(line);
        prompt = "Retry: ";   // 后续重试使用固定提示
    }
}

// ------------------------ get_long ------------------------
long get_long(const char* prompt) {
    while (1) {
        char* line = get_string(prompt);
        if (line == NULL) handle_eof();

        char* endptr;
        errno = 0;
        long val = strtol(line, &endptr, 10);

        if (errno == 0 && endptr != line && *endptr == '\0') {
            free(line);
            return val;
        }

        free(line);
        prompt = "Retry: ";
    }
}

// ------------------------ get_double ------------------------
double get_double(const char* prompt) {
    while (1) {
        char* line = get_string(prompt);
        if (line == NULL) handle_eof();

        char* endptr;
        errno = 0;
        double val = strtod(line, &endptr);

        if (errno == 0 && endptr != line && *endptr == '\0') {
            free(line);
            return val;
        }

        free(line);
        prompt = "Retry: ";
    }
}

// ------------------------ get_char ------------------------
char get_char(const char* prompt) {
    while (1) {
        char* line = get_string(prompt);
        if (line == NULL) handle_eof();

        // 跳过前导空白字符（空格、制表符等）
        char* p = line;
        while (*p && isspace((unsigned char)*p)) p++;

        if (*p != '\0') {
            char result = *p;
            free(line);
            return result;
        }

        free(line);
        prompt = "Retry: ";
    }
}
