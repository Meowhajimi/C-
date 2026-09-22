#include<stdio.h>

void print_row_column(int rows, int columns);

int main()
{
	const int C = 0; //设置常量，永不被更改
	print_row_column(3, 3);
	
	
}

void print_row_column(int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("#");
		}
		printf("\n");
	}
}
