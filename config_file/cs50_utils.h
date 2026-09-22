#pragma once
#ifndef CS50_UTILS_H
#define CS50_UTILS_H

typedef char* string;
string get_string(const char* prompt);

/**
 * 提示用户输入，返回动态分配的字符串（不含换行符）。
 * 遇到 EOF 返回 NULL，调用者需 free。
 */

/**
 * 提示用户输入，返回 int 整型。
 * 若输入无效（非数字或超出范围）会循环提示 "Retry: "。
 * 遇到 EOF 则程序退出（仿 CS50 行为）。
 */
int get_int(const char* prompt);

/**
 * 提示用户输入，返回 long 整型。
 */
long get_long(const char* prompt);

/**
 * 提示用户输入，返回 double 浮点数。
 */
double get_double(const char* prompt);

/**
 * 提示用户输入，返回第一个非空白字符（char）。
 * 若用户直接按回车或空行，会循环提示 "Retry: "。
 */
char get_char(const char* prompt);

#endif