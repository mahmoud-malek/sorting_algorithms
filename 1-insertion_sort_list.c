#include "sort.h"

/**
 * swapNodes - is a function to swap two nodes
 * @head: head node
 * @node1: is a node to swap
 * @node2: another node to swap
 */

void swapNodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (*head == node1)
		*head = node2;

	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	if (node1->prev != NULL)
		node1->prev->next = node2;

	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list -  function that sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 *
 * @list: is a linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !*list)
		return;

	current = *list;

	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			swapNodes(list, current->prev, current);
			print_list((const listint_t *)*list);
		}
		current = current->next;
	}
}
