#include "sort.h"

/**
 * merge - Merge two sorted subarrays of array[] into array[]
 *
 * @array: The array to be merged
 * @temp: A temporary array used for merging
 * @left_size: The size of the left subarray
 * @right: The right subarray to be merged
 * @right_size: The size of the right subarray
 */

void merge(int *array, int *temp, size_t left_size, int *right,
		   size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	/* Copy the left subarray into the temp array*/
	for (i = 0; i < left_size; i++)
		temp[i] = array[i];

	i = 0; /* Reset i to start from the beginning of the temp (left) array*/

	printf("Merging...\n[left]: ");
	print_array(temp, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	/*Merge the two subarrays into the original array*/
	while (i < left_size && j < right_size)
	{
		if (temp[i] <= right[j])
			array[k++] = temp[i++];

		else
			array[k++] = right[j++];
	}

	/*Copy any remaining elements from the left subarray*/
	while (i < left_size)
		array[k++] = temp[i++];

	/*Copy any remaining elements from the right subarray*/
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, k);
}

/**
 * merge_sort_recursive - Recursively divide the array
 * into subarrays and merge them back
 *
 * @array: The array to be sorted
 * @temp: A temporary array used for merging
 * @size: The size of the array
 */

void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;
	merge_sort_recursive(array, temp, mid);
	merge_sort_recursive(array + mid, temp + mid, size - mid);

	merge(array, temp, mid, array + mid, size - mid);
}

/**
 * merge_sort - Sort the array using the merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;
	merge_sort_recursive(array, temp, size);
	free(temp);
}
