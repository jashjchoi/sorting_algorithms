#include "sort.h"
/**
* insertion_sort_list - sorts dll of int in ascending order
* @list: list to sort
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *ptr;

	if ((*list)->next == NULL || list == NULL || (*list) == NULL)
		return;

	ptr = *list;

	while (ptr)
	{
		while (ptr->next && (ptr->n > ptr->next->n))
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			tmp->prev = ptr->prev;

			if (ptr->prev != NULL)
			{
				ptr->prev->next = tmp;
			}
			if (tmp->next != NULL)
			{
				tmp->next->prev = ptr;
			}
			ptr->prev = tmp;
			tmp->next = ptr;

			if (tmp->prev != NULL)
				tmp->prev = ptr;
			else
				*list = tmp;
			print_list(*list);
		}
		ptr = ptr->next;
	}
}
