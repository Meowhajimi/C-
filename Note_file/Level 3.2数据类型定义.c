#include "cs50_utils.h"
#include<string.h>
#include <stdio.h>

typedef struct
{
	string name;
	string number;
} person ;

int main() //这样的代码并不是最优解，我们需要创建属于自己的数据类。（元组）
{     
	//string names[] = { "Alice", "David", "John" };
	//string numbers[] = { "134", "135", "`136" };

	//string name = get_string("What does your name ");

	//for (int i = 0; i < 3; i++)
	//{
	//	if (strcmp(names[i],name) == 0)
	//	{
	//		printf("Found %s %s", names[i], numbers[i]);

	//		return 0;
	//	}
	//}
	//printf("Not found");
	 
	//return 1;
	
	person people[3];

	people[0].name = "David";
	people[0].number = "1145";

	string inputs = get_string("E:");

	for (int i = 0; i < 1; i++)
	{
		if (strcmp(people[i].name, inputs) == 0)
		{
			printf("Found, %s", people[i].number);

			return 0;
		}
	}
	printf("Not found");

	return 1;
} 