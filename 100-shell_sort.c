#include "sort.h"

/**
 * swap - a function that swaps two numbers
 *
 * @a: first num
 * @b: second num
 */

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to be partitioned
 * @size: is the total size
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, i, j, tmp;

	if (!array || size < 2)
		return;

	/*Find the maximum gap size using the Knuth sequence*/
	while (gap <= (int)size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* Start with the largest gap and reduce the gap */
	while (gap > 0)
	{

		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				/* Shift the larger element to the right*/
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
