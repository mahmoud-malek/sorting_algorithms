#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @dir: A flag for sorting direction, UP or DOWN.
 * @array: An array of integers.
 * @size: The size of the sub-array.
 * @total_size: the total size of the entire array
 */

void bitonic_merge(int dir, int *array, size_t size, size_t total_size)
{
	size_t i, step;

	if (size > 1)
	{
		step = size / 2;

		for (i = 0; i < step; i++)
			if ((array[i] > array[step + i]) == dir)
				swap(array + i, array + step + i);

		bitonic_merge(dir, array, step, total_size);
		bitonic_merge(dir, array + step, step, total_size);
	}
}

/**
 * bitonic_sort_helper - Sorts a bitonic sequence.
 * @dir: A flag for sorting direction, UP or DOWN.
 * @array: An array of integers.
 * @size: The size of the sub-array.
 * @total_size: the total size of the entire array
 */

void bitonic_sort_helper(int dir, int *array, size_t size, size_t total_size)
{
	size_t step;

	if (size > 1)
	{
		step = size / 2;
		printf("Merging [%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
		print_array(array, size);
		bitonic_sort_helper(1, array, step, total_size);
		bitonic_sort_helper(0, array + step, step, total_size);
		bitonic_merge(dir, array, size, total_size);
		printf("Result [%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_helper(1, array, size, size);
}
