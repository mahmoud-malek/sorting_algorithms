# 0x1B. C - Sorting Algorithms & Big O

This project explores various sorting algorithms in C and focuses on their time complexity using Big O notation. It is designed for groups of two students to collaborate and implement these algorithms.

## Background Context

The project involves implementing at least four different sorting algorithms and understanding Big O notation to evaluate time complexity. The goal is to select the most suitable sorting algorithm for a given input and comprehend the concept of a stable sorting algorithm.

## Resources

Here are some recommended resources for understanding sorting algorithms and Big O notation:

- [Sorting algorithm](https://intranet.alxswe.com/rltoken/-j5MKLBlzZAC2RfJ5DTBIg)
- [Big O notation](https://intranet.alxswe.com/rltoken/WRvrE2BaNVQFssHiUATTrw)
- [Sorting algorithms animations](https://intranet.alxswe.com/rltoken/ol0P7NbYVb5R31iOv4Q40A)
- [15 sorting algorithms in 6 minutes (WARNING: May trigger seizures)](https://intranet.alxswe.com/rltoken/_I0aEvhfJ66Xyob6dd9Utw)
- [CS50 Algorithms explanation in detail by David Malan](https://intranet.alxswe.com/rltoken/Ea93HeEYuNkOL7sGb6zzGg)
- [All about sorting algorithms](https://intranet.alxswe.com/rltoken/21X_eaj5RGcLIL9mZv2sqw)

## Learning Objectives

By the end of this project, you should be able to:

- Implement at least four different sorting algorithms
- Understand and explain Big O notation and how to evaluate time complexity
- Select the most efficient sorting algorithm for a given input
- Comprehend the concept of a stable sorting algorithm

## Requirements

### General

- Allowed editors: vi, vim, emacs
- Code compiled on Ubuntu 20.04 LTS using gcc with specific options
- Mandatory inclusion of a README.md file at the project root
- Code should follow the Betty style
- Avoid using global variables
- Limit functions to no more than 5 per file
- Prohibition on using standard library functions like printf, puts, etc.
- Prototypes of functions included in a header file named `sort.h`
- Use include guards for all header files
- Data structures provided for doubly linked list and specific functions for printing arrays and lists

...

## Tests

To test your sorting algorithms with large sets of random integers, you can use [Random.org](https://www.random.org/integer-sets/).

### Sorting Algorithms and Big O

- **Bubble Sort** (File: 0-O)
  - Function: `void bubble_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n)
    - Average case: O(n^2)
    - Worst case: O(n^2)
  - Description: Sorts an array using the Bubble sort algorithm and prints the array after each swap.

- **Insertion Sort** (File: 1-O)
  - Function: `void insertion_sort_list(listint_t **list)`
  - Time complexity notations:
    - Best case: O(n)
    - Average case: O(n^2)
    - Worst case: O(n^2)
  - Description: Sorts a doubly linked list using the Insertion sort algorithm and prints the list after each swap.

- **Selection Sort** (File: 2-O)
  - Function: `void selection_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n^2)
    - Average case: O(n^2)
    - Worst case: O(n^2)
  - Description: Sorts an array using the Selection sort algorithm and prints the array after each swap.

- **Counting Sort** (File: 102-O)
  - Function: `void counting_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n + k)
    - Average case: O(n + k)
    - Worst case: O(n + k)
  - Description: Sorts an array using the Counting sort algorithm and prints the counting array after setup.

- **Merge Sort** (File: 103-O)
  - Function: `void merge_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n log n)
    - Average case: O(n log n)
    - Worst case: O(n log n)
  - Description: Sorts an array using the Merge sort algorithm and displays the sorted array.

- **Heap Sort** (File: 104-O)
  - Function: `void heap_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n log n)
    - Average case: O(n log n)
    - Worst case: O(n log n)
  - Description: Sorts an array using the Heap sort algorithm and prints the array after each swap.

- **Radix Sort** (File: X-O)
  - Function: `void radix_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(nk)
    - Average case: O(nk)
    - Worst case: O(nk)
  - Description: Sorts an array using the Radix sort algorithm and prints the array at each significant digit increase.

- **Bitonic Sort** (File: 106-O)
  - Function: `void bitonic_sort(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(log^2 n)
    - Average case: O(log^2 n)
    - Worst case: O(log^2 n)
  - Description: Sorts an array using the Bitonic sort algorithm and prints the array after each swap.

- **Quick Sort (Hoare)** (File: 107-O)
  - Function: `void quick_sort_hoare(int *array, size_t size)`
  - Time complexity notations:
    - Best case: O(n log n)
    - Average case: O(n log n)
    - Worst case: O(n^2)
  - Description: Sorts an array using the Quick sort algorithm (Hoare partition scheme) and prints the array after each swap.

- **Sort Deck of Cards** (File: deck.h)
  - Function: `void sort_deck(deck_node_t **deck)`
  - Description: Sorts a deck of cards from Ace to King and Spades to Diamonds using the sorting algorithm of choice.

...

## Conclusion

This project delves into sorting algorithms and their complexities, aiding in a deeper understanding of their functionality and optimal use cases.

Feel free to explore and enjoy the journey of discovering the efficiency of sorting algorithms!
