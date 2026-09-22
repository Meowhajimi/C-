#include <stdio.h>

int main()
{
	int rank_array[] = { 6, 4, 4, 2, 9, 1 };

	int numbers = sizeof(rank_array) / sizeof(rank_array[0]);
	

	int min_store = 0;
	int max_store = 0;

	//冒泡排序
	for (int i = 0; i < numbers; i++)
	{
		for (int j = 0; j < numbers - 1 - i; j++)
		{
			if (rank_array[j] > rank_array[j + 1]) // 内部循环，若前者大于后者，进行一次交换
			{
				max_store = rank_array[j];
				min_store = rank_array[j + 1]; //建立变量缓存，避免数据丢失
				rank_array[j + 1] = max_store;
				rank_array[j] = min_store; //完成一次交换
			}
		}
	}
	//遍历数组
	for (int i = 0; i < numbers; i++)
	{
		printf("%i", rank_array[i]);
	}
}