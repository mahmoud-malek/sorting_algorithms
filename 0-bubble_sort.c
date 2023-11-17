#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: array of integers to sort
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, sorted, tmp;

	if (size < 2)
		return;

	for (; i < size; i++)
	{
		sorted = 1;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				sorted = 0;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}

		if (sorted)
			break;
	}
}
