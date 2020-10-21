#include "sort.h"
/**
* quick_sort - main function for quick sort algo
* @array: the array to sort
* @size: the array size
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	qst(array, 0, size - 1, size);
}
/**
* qst - quick sorting algo
* @array: the array to sort
* @low: the lower index
* @high: the higher index
* @size: the array size
* Return: void
*/
void qst(int array[], int low, int high, size_t size)
{
	int pp;

	if (low < high)
	{
		pp = partition(array, low, high, size);
		qst(array, low, pp - 1, size);
		qst(array, pp + 1, high, size);
	}
}

/**
* partition - implement of lomuta partition between 2 indexes
* @array: the array to sort
* @l: the lower index
* @h: the higher index
* @size: the array size
* Return: the next index after partition index
*/
int partition(int *array, int l, int h, size_t size)
{
	int pivot = array[h];
	int i = l - 1, j;

	for (j = l; j < h; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_func(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != h)
	{
		swap_func(&array[i + 1], &array[h]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
* swap_func - swap 2 given indexes
* @x: the ptr to index
* @y: the ptr to index
* Return: void
*/
void swap_func(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
