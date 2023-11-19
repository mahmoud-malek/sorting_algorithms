#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count, *output;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count = calloc(max + 1, sizeof(int));
	if (!count)
		return;

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
