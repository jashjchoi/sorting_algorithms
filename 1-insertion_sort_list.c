#include "sort.h"
/**
* insertion_sort_list - sorts dll of int in ascending order
* @list: list to sort
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *cur;

	if (list == NULL || (*list) == NULL)
		return;

	tmp = (*list)->next;

	while (tmp)
	{
		cur = tmp;
		while (cur->prev)
		{
			if (cur->n < cur->prev->n)
			{
				swap_int(cur->prev, cur);
				while ((*list)->prev)
				{
					*list = (*list)->prev;
				}
				print_list(*list);
				continue;
			}
			cur = cur->prev;
		}
		tmp = tmp->next;
	}
}

/**
* swap_int - recursive function to swap 2 given nodes
* @l: ptr to left node
* @r: ptr to right node
* Return: void
*/
void swap_int(listint_t *l, listint_t *r)
{
	listint_t *tmp, *right = r, *left = l;

	tmp = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	right->prev = tmp;
	if (left->next)
	{
		left->next->prev = left;
	}
	if (right->prev)
	{
		right->prev->next = right;
	}
}
