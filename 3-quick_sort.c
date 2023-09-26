#include "sort.h"

/**
 * quick_sort - uses Lomuto Technique to sort an array
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * The function sorts the integer array
 * and prints the array every time indices are swapped
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	sort(array, 0, size);
}

/**
 * sort - sorts the array
 * @array: subarray to be sorted
 * @low: lowest index to sort
 * @high: highest index to sort
 */
void sort(int *array, int low, int high)
{
	int a = low -1, b, pivot = array[high], temp;

	if (low >= high)
		return;
	for (b = low; b < high; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			temp = array[b];
			array[b] = array[a];
			array[a] = temp;
			print_array(array, high + 1);
		}
	}
	temp = array[high];
	array[high] = array[a + 1];
	array[a + 1] = temp;
	sort(array, low, a - 1);
	sort(array, a + 1, high);
}

