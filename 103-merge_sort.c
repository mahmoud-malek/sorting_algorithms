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
 */

void merge(int l, int r, int mid, int *array)
{
	int leftSize = mid - l + 1;
	int rightSize = r - mid;

	int *tmp1 = (int *)malloc(leftSize * sizeof(int));
	int *tmp2 = (int *)malloc(rightSize * sizeof(int));

	int i, j, k;

	for (i = 0; i < leftSize; i++)
		tmp1[i] = array[i + l];

	for (i = 0; i < rightSize; i++)
		tmp2[i] = array[i + mid + 1];

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < leftSize; i++)
		printf("%d%s", tmp1[i], (i < leftSize - 1) ? ", " : "\n");
	printf("[right]: ");
	for (i = 0; i < rightSize; i++)
		printf("%d%s", tmp2[i], (i < rightSize - 1) ? ", " : "\n");

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		/*Check if tmp1 is less than tmp2 or tmp2 is not exist*/
		if (i < leftSize && (j >= rightSize || tmp1[i] <= tmp2[j]))
			array[k] = tmp1[i], i++;

		else
			array[k] = tmp2[j], j++;
	}
	print_msg(array, l, r);
	free(tmp1);
	free(tmp2);
}

/**
 * mergeSortHelper - Recursively divides the array
 * into subarrays, then merges them in sorted order.
 *
 * @l: Left index of the subarray to be sorted.
 * @r: Right index of the subarray to be sorted.
 * @array: The array to be sorted.
 */

void mergeSortHelper(int l, int r, int *array)
{
	int mid;

	if (l >= r)
		return;

	mid = l + (r - l) / 2;

	mergeSortHelper(l, mid, array);
	mergeSortHelper(mid + 1, r, array);
	merge(l, r, mid, array);
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

	if (size < 2 || !array)
		return;

	mergeSortHelper(0, (int)size - 1, array);
}
