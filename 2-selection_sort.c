#include "sort.h"

/**
 * selection_sort -  a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: is an array of numbers
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int mini;

	for (i = 0; i < size; i++)
	{
		mini = array[i];
		idx = i;
		for (j = i; j < size - 1; j++)
		{
			if (array[j + 1] < mini)
				mini = array[j + 1], idx = j + 1;
		}

		if (mini != array[i])
		{
			array[idx] = array[i];
			array[i] = mini;
			print_array(array, size);
		}
	}
}
