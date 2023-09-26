#include "sort.h"
#include <stdio.h>

/**
 * selction_sort - uses selection algorithm to sort a list in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Prints the the array everytime a number is sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, sub_idx, idx_min;
	int min, temp;

	if (array == NULL)
		return;
	for (idx = 0; idx < size; idx++)
	{
		min = array[idx];
		idx_min = idx;
		for (sub_idx = idx + 1; sub_idx < size; sub_idx++)
		{
			if (array[sub_idx] < min)
			{
				min = array[sub_idx];
				idx_min = sub_idx;
			}
		}
		if (idx_min != idx)
		{
			temp = array[idx];
			array[idx] = min;
			array[idx_min] = temp;
			print_array(array, size);
		}
	}
}
