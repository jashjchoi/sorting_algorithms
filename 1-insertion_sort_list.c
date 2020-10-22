#include "sort.h"
/**
* insertion_sort_list - sorts dll of int in ascending order
* @list: list to sort
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *ptr = NULL;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;

	ptr = *list;
	tmp = *list;

	while (ptr)
	{
		ptr = ptr->next;
		while (tmp->prev && (tmp->n < tmp->prev->n))
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
			{
				tmp->next->prev = tmp->prev;
			}
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			if (tmp->prev != NULL)
			{
				tmp->prev->next = tmp;
			}
			else
				*list = tmp;
			tmp->next->prev = tmp;
			print_list(*list);
		}
		tmp = ptr;
	}
}
