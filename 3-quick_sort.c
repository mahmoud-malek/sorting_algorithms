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
 * partition_lomuto - a function that partitions an array
 *  using the Lomuto partitioning scheme
 *
 * @array: array to be partitioned
 * @low: index of the first element in the partition
 * @high: index of the last element in the partition
 * @size: is the total size
 * Return: index of the pivot
 */

int partition_lomuto(int array[], int low, int high, size_t size)
{
	int pivot = array[high], pivot_idx, i;

	for (pivot_idx = i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (pivot_idx != i)
			{
				swap(&array[pivot_idx], &array[i]);
				print_array(array, size);
			}
			pivot_idx++;
		}
	}

	if (array[pivot_idx] > pivot)
	{
		swap(&array[pivot_idx], &array[high]);
		print_array(array, size);
	}

	return (pivot_idx);
}

/**
 * quick_lomuto - a function that sorts an array using
 * the Quick sort algorithm with the Lomuto partitioning scheme
 *
 * @array: array to be sorted
 * @low: index of the first element in the partition
 * @high: index of the last element in the partition
 *
 * @size: is the total size
 */

void quick_lomuto(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_lomuto(array, low, high, size);
		quick_lomuto(array, low, pivot - 1, size);
		quick_lomuto(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: is an array of numbers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_lomuto(array, 0, (int)size - 1, size);
}
