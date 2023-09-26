#include "sort.h"
#include <unistd.h>
#include <stddef.h>

/**
 * bubble_sort - function rearranges integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t prev, next, times;
	int temp, swap;

	if (!array)
		return;
	for (times = 0; times < size; times++)
	{
		for (prev = 0, next = 1, swap = 0; next < size; next++, prev++)
		{
			if (array[next] < array[prev])
			{
				temp = array[next];
				array[next] = array[prev];
				array[prev] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
