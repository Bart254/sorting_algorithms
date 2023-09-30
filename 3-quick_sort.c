#include "sort.h"
#include <stdio.h>

/**
 * swap_e - swaps two int
 * @a: int a
 * @b: int b
 */
void swap_e(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lom_part - uses lomunto method
 * @array: the array of int
 * @size: size of array
 * @low: low
 * @high: highest index
 * Return: next index
 */
int lom_part(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_e(&array[i], &array[j]);
		}
	}
	swap_e(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * help - complementary solver
 * @array: array of int
 * @size: size of array
 * @low: lowest idx
 * @high: highest idx
 */
void help(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lom_part(array, size, low, high);

		help(array, size, low, pivot_index - 1);
		help(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - main function
 * @array: arr of int
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	help(array, size, 0, size - 1);
}
