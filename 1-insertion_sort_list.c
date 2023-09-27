#include "sort.h"

/**
 * insertion_sort_list - sorts a list of integers using the sort method
 * @list: list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *a, *b;
	int swaps;

	if (!list)
		return;
	ptr = *list;
	while (ptr)
	{
		swaps = 0;
		for (a = ptr, b = a->prev; b;)
		{
			if (a->n < b->n)
			{
				if (swaps == 0)
					ptr = ptr->next;
				swap(list, a, b);
				swaps++;
				print_list(*list);
				b = a->prev;
			}
			else
				break;
		}
		if (swaps == 0)
			ptr = ptr->next;
	}
}

/**
 * swap - swaps the nodes of a list
 * @list: head node
 * @a: node to be inserted
 * @b: second node
 */
void swap(listint_t **list, listint_t *a, listint_t *b)
{
	b->next = a->next;
	a->prev = b->prev;
	a->next = b;
	b->prev = a;
	if (b->next != NULL)
		(b->next)->prev = b;
	if (a->prev != NULL)
		(a->prev)->next = a;
	else
		*list = a;
}

