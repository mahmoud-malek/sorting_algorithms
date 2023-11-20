#include "sort.h"

/**
 * print_msg - the merged portion of the array.
 *
 * @array: The array containing the merged elements.
 * @l: The starting index of the merged portion.
 * @r: The ending index of the merged portion.
 */

void print_msg(int *array, int l, int r)
{
	int i;

	if (!array)
		return;

	printf("[Done]: ");
	for (i = l; i <= r; i++)
		printf("%d%s", array[i], (i < r) ? ", " : "\n");
}

/**
 * merge - two subarrays of array[].
 * First subarray is array[l..mid]
 * Second subarray is array[mid+1..r]
 *
 * @l: Left index of the first subarray.
 * @r: Right index of the second subarray.
 * @mid: Middle index to divide the subarrays.
 * @array: The array to be merged.
 * @temp: is a temproary
 */

void merge(int *array, int *temp, int l, int r, int mid)
{
	int leftSize = mid - l + 1;
	int rightSize = r - mid;

	int i, j, k;

	for (i = 0; i < leftSize; i++)
		temp[i] = array[l + i];
	for (i = 0; i < rightSize; i++)
		temp[i + leftSize] = array[i + mid + 1];

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < leftSize; i++)
		printf("%d%s", temp[i], (i < leftSize - 1) ? ", " : "\n");
	printf("[right]: ");
	for (i = 0; i < rightSize; i++)
		printf("%d%s", temp[i + leftSize], (i < rightSize - 1) ? ", " : "\n");

	i = 0, j = leftSize, k = l;
	while (i < leftSize && j < leftSize + rightSize)
	{
		if (temp[i] <= temp[j])
			array[k++] = temp[i++];
		else
			array[k++] = temp[j++];
	}

	while (i < leftSize)
		array[k++] = temp[i++];

	while (j < leftSize + rightSize)
		array[k++] = temp[j++];

	print_msg(array, l, r);
}

/**
 * mergeSortHelper - Recursively divides the array
 * into subarrays, then merges them in sorted order.
 *
 * @l: Left index of the subarray to be sorted.
 * @r: Right index of the subarray to be sorted.
 * @array: The array to be sorted.
 * @temp: is a temproary
 */

void mergeSortHelper(int *array, int *temp, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;

		mergeSortHelper(array, temp, l, mid);
		mergeSortHelper(array, temp, mid + 1, r);
		merge(array, temp, l, r, mid);
	}
}

/**
 * merge_sort - a function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *temp = (int *)malloc(size * sizeof(int));

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	if (size < 2 || !array)
		return;

	mergeSortHelper(array, temp, 0, size - 1);
	free(temp);
}
