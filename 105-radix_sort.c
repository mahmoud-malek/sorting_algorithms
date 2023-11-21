#include "sort.h"

/**
 * get_max - get the maximum number in the array
 * @array: array of integers
 * @size: size of the array
 * Return: the maximum number in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * counting_sort_radix - counting sort of the array depending on significant
 * digits.
 * @array: array of integers
 * @size: size of the array
 * @place: digit place
 */
void counting_sort_radix(int *array, size_t size, int place)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/*Count the number of occurrences of each digit at the current place*/
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	/*Calculate the prefix sum of the counts*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Place the elements in the output array in the correct order */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	/*Copy the sorted elements back to the original array*/
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_num;
	int place;

	if (!array || size < 2)
		return;

	max_num = get_max(array, size);
	/* Perform counting sort for every digit */
	for (place = 1; max_num / place > 0; place *= 10)
		counting_sort_radix(array, size, place);
}
