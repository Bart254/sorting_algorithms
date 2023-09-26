#include "sort.h"

/**
 * insertion_sort_list - sorts a list of integers using the sort method
 * @list: list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr_a, *ptr_b, *temp;
	int swaps;

	if (!list)
		return;
	ptr_a = *list;
	while (ptr_a)
	{
		swaps = 0;
		for (ptr_b = ptr_a; ptr_b && ptr_b->prev; ptr_b = ptr_b->prev)
		{
			if (ptr_b->n < (ptr_b->prev)->n)
			{
				if (swaps == 0)
					ptr_a = ptr_a->next;
				temp = ptr_b->prev;
				temp->next = ptr_b->next;
				ptr_b->next = temp;
				ptr_b->prev = temp->prev;
				temp->prev = ptr_b;
				if (ptr_b->prev)
					(ptr_b->prev)->next = ptr_b;
				if (temp->next)
					(temp->next)->prev = temp;
				swaps++;
				print_list(*list);
			}
			else
				ptr_a = ptr_a->next;
		}
	}
}
