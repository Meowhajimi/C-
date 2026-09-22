//时间复杂度 O(n)  O(n/2) O(lgn)
#include "cs50_utils.h"
#include <stdio.h>
#include<string.h>


//int main(void)
//{
//    int numbers[] = {20, 500, 10, 5, 100, 1, 50 };
//    int number = get_int("Number :");
//    for (int i = 0; i < 7; i++)
//    {
//        if (numbers[i] == number)
//        {
//            printf("Found");
//
//            return 0;
//        }
//        //别在for的内部写else不然找一次就跑了
//    }
//    printf("Not found");
//
//    return 1;
//
//
//
//}
int main(void)
{
	string strings[] = { "battles" ,"hats", "soup", "milk" };

	string name = get_string("E:"); //不要把:写为：会导致一堆报错

	for (int i = 0; i < 4; i++)
	{
		if(strcmp(strings[i] , name) == 0)//if (strings[i] == name) 这么比较不会得到想要的结果
		{
			printf("Found\n");

			return 0;
		}
	}

	printf("Not Found");

	return 1;
}