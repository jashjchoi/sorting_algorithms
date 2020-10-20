#include "sort.h"
/**
*selection_sort - Sort an array of integers in ascending order
*@array: the array to sort
*@size: the array size
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min = 0;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
