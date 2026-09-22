#include"cs50_utils.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int number;
	struct node* next; //编译器还不知道node，只认识struct node，故而加struct,这里加上一个node next是为了能够继续进一步指向下一个结构体。从而循环往复，生生不息
} node;

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
		n->next = list;

		list = n;
	}

	//time pass

	node *ptr = list;
	while (ptr != NULL)
	{
		printf("%i", ptr->number);

		ptr = ptr->next;
	}
} 
//上述代码理解难度 王者

///int main(void)
//{
	//int* list = malloc(3 * sizeof(int));

	//if (list == NULL)
	//{
	//	return 1;
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	list[i] = i + 1;
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%i\n", list[i]);
	//}
 //   //with time pass...

	//int* tmp = realloc(list, 4 * sizeof(int)); //细节1 realloc是在原有的list内存上加上一个格子，容纳四个格子 但若是后面的内存格被占了，就会另外再找一个四个格子的内存再吧tmp按到那里去并释放list的地址
	//if (tmp == NULL)
	//{
	//	free(list); //细节2 避免list被一直占用

	//	return 1;
	//}

	//tmp[3] = 4;

	////free(list);已经被释放了 产生悬垂指针

	//list = tmp; //产生了两个指针，指向同一位置，实战不太推荐 补一个tmp = NULL把tmp挂起来，不指向任何地方

	//for (int i = 0; i < 4; i++)
	//{
	//	printf("%i\n", list[i]);
	//}
	//return 0;
	//这么做并不灵活，我们需要引入一个叫链表的结构体

//}