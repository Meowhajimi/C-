#include<stdio.h>

void main_loop(void);
void show_pan(void);
int judge_down_side();

int main(void)
{
	main_loop();
}

void show_pan(void)
{

}

int judge_down_side()
{
	return 0;
}

void main_loop()
{
	show_pan();
	judge_down_side();
	if (judge_down_side)
	{
		
	}
	else
	{

	}
}
//主循环:
//展示->判断落子->提示落子->改变棋盘->判断正误平局->若出现了正误->退出游戏...->再进行主循环
