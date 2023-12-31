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
 * partition_hoare - a function that partitions an array
 *  using the hoare partitioning scheme
 *
 * @array: array to be partitioned
 * @low: index of the first element in the partition
 * @high: index of the last element in the partition
 * @size: is the total size
 * Return: index of the pivot
 */

int partition_hoare(int array[], int low, int high, size_t size)
{
	int pivot = array[high], l = low - 1, r = high + 1;

	for (; l < r;)
	{
		do {
			l++;
		} while (array[l] < pivot);
		do {
			r--;
		} while (array[r] > pivot);

		if (l < r)
		{
			swap(array + l, array + r);
			print_array(array, size);
		}
	}

	return (l);
}

/**
 * quick - a function that sorts an array using
 * the Quick sort algorithm with the hoare partitioning scheme
 *
 * @array: array to be sorted
 * @low: index of the first element in the partition
 * @high: index of the last element in the partition
 *
 * @size: is the total size
 */

void quick(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, size);
		quick(array, low, pivot - 1, size);
		quick(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: is an array of numbers
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick(array, 0, (int)size - 1, size);
}
