#include"cs50_utils.h"
#include<stdio.h>
#include<stdlib.h>

//反向链表的核心 寻找NULL，找到后替换这个null并在此后进一步创建null，退出循环
typedef struct node
{
	int number;
	struct node* next;
}node;

int main(void)
{
	node* list = NULL;

	for (int i = 0; i < 3; i++)
	{
		node* n = malloc(sizeof(node));

		if (n == NULL)
		{
			return 1;
		}
		n->number = get_int("Number:"); //(*n).number ~ n->number
        //if list is empty
		if (list == NULL)
		{
			list = n;
		}

		//if list has number already
		else
		{
			for (node *ptr = list; ptr != NULL; ptr = ptr->next)
			{
				//if at the end of list
				if (ptr->next == NULL)
				{
					ptr->next = n;

					break;
				}
			}
		}
	}

	//time pass

	for (node* ptr = list; ptr != NULL; ptr = ptr->next)
	{
		printf("%i\n", ptr->number);
	}

	//time passsssss 
	node* ptr = list;
	while (ptr != NULL)
	{
		node* next = ptr->next;
		free(ptr);
		ptr = next;
	}
	
	return 0;
}


