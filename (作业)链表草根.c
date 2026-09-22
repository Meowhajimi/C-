#include"cs50_utils.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct node //定义node结构体
{
	int number;
	struct node* next; //递归思维
}node;

int main(void)
{
	node* head = NULL; //初始化链表头部

	for (int i = 0; i < 3; i++) //获取三个链表输入
	{
		node* tail = malloc(sizeof(node)); //分配链表内存（独立的内存）
		if (tail == NULL)
		{
			return 1; //防止内存泄露
		}
		tail->number = get_int("Number:"); //CS_50
		tail->next = NULL; //初始化链表尾部
		if (head == NULL)
		{
			head = tail;//让链表的头部由指向NULL转为指向初始链表，即初始化链表入口
		}
		else //链表已经被初始化，上文tail已经指向下一个游离的内存快，这一步是为了用ptr拼接两个内存快
		{
			for (node* ptr = head; ptr != NULL; ptr = ptr->next) //定义寻位指针，并找到链表尾部
			{
				if (ptr->next == NULL)
				{
					ptr->next = tail; //让上一个数据的next链接到下一个数据，这里ptr仅作为中间的连线焊接工
					break; //焊接结束
				}
			}
		}
	}

	for (node* ptr = head; ptr != NULL; ptr = ptr->next) //使用ptr指针遍历链表
	{
		printf("%i", ptr->number);
	}

	for (node* ptr = head; ptr != NULL; ) //遍历并释放链表内存
	{
		node* tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}
//下面的操作并不合理，会导致ptr连挑两步导致内存泄露
//	for (node* ptr = head; ptr != NULL; ptr = ptr->next) //运用ptr遍历，并一个个释放内存
//	{
//		node* tmp = ptr->next; //创建中间变量，保证ptr能够接触到下一个内存
//		if (tmp == NULL)
//		{
//			break;
//		}
//		free(ptr);
//		ptr = tmp; //向后移动ptr
//	}
//	return 0;
//}