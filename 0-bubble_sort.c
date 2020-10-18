#include "sort.h"
/**
*bubble_sort - sort a linked list of int using bubble alg
*@array: the array to sort
*@size: the array size
*Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t  i;
	int flag = 0;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (!flag)
	{
		flag = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				flag = 0;
				swap_num(array, i);
				print_array(array, size);
			}
		}
	}
}
/**
*swap_num - recursive function to swap int numbers
*@array: the array
*@i: the position
*Return: void
*/
void swap_num(int *array, int i)
{
	int tmp = array[i];

	array[i] = array[i + 1];
	array[i + 1] = tmp;
}
