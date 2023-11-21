#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Fixes a heap where only the root node is invalid.
 * @array: The heap to fix.
 * @n: The size of the heap.
 * @i: The index of the root node.
 * @size: The size of the array (used for printing).
 *
 * This function is used during heapify to build the initial heap, and during
 * the sort phase to fix the heap after swapping the root node with the last
 * node.
 */

void sift_down(int *array, size_t n, size_t i, size_t size)
{
	size_t root = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[root])
		root = left;
	if (right < n && array[right] > array[root])
		root = right;

	if (root != i)
	{
		swap(&array[i], &array[root]);
		print_array(array, size);
		sift_down(array, n, root, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap
 * sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * This function first transforms the array into a max heap, and then sorts it
 * by repeatedly swapping the first and last elements, and "sifting down" the
 * new first element.
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;
	/*Heapify*/
	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
