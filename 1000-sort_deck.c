#include "deck.h"

/**
 * getValue - Returns the total value of a card.
 * @c: A pointer to the card to get the value of.
 *
 * Return: The total value of the card.
 */

int getValue(deck_node_t *c)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
					  "Jack", "Queen", "King"};
	int total = 0, i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(c->card->value, values[i]) == 0)
		{
			total = i;
			break;
		}
	}
	switch (c->card->kind)
	{
	case SPADE:
		total += 0;
		break;
	case HEART:
		total += 13;
		break;
	case CLUB:
		total += 26;
		break;
	case DIAMOND:
		total += 39;
		break;
	}

	return (total);
}

/**
 * compare_decks - Compares two deck_node_t structs based on their values.
 * @a: A pointer to the first deck_node_t struct to compare.
 * @b: A pointer to the second deck_node_t struct to compare.
 *
 * Return: -1 if the first card has a lower value, 1 if the first card has a
 * higher value, and 0 if the values are equal.
 */

int compare_decks(const void *a, const void *b)
{
	deck_node_t *n1 = *(deck_node_t **)a;
	deck_node_t *n2 = *(deck_node_t **)b;

	int val1 = getValue(n1);
	int val2 = getValue(n2);

	if (val1 < val2)
		return (-1);
	else if (val1 > val2)
		return (1);
	else
		return (0);
}

/**
 * sort_deck - Sorts a deck of cards based on their values.
 * @deck: A pointer to the head of the deck to sort.
 *
 * This function sorts a deck of cards based on their values using the
 * compare_decks function as the comparison function.
 * It first counts the number of cards in the deck,
 * creates an array of deck_node_t pointers to hold the
 * deck, and then copies the deck into the array. It then sorts the array using
 * the qsort function with the compare_decks
 * function as the comparison function.
 * Finally, it links the sorted deck back together and frees the memory used by
 * the array.
 */

void sort_deck(deck_node_t **deck)
{
	size_t nitems = 0, i;
	deck_node_t *tmp = *deck, **deck_array;

	if (!deck || !*deck || !(*deck)->next)
		return;

	while (tmp)
	{
		tmp = tmp->next;
		nitems++;
	}

	deck_array = malloc(nitems * sizeof(deck_node_t *));
	tmp = *deck;

	for (i = 0; i < nitems; i++)
	{
		deck_array[i] = tmp;
		tmp = tmp->next;
	}

	qsort(deck_array, nitems, sizeof(deck_node_t *), compare_decks);

	for (i = 0; i < nitems - 1; i++)
		deck_array[i]->next = deck_array[i + 1];

	deck_array[nitems - 1]->next = NULL;
	*deck = deck_array[0];
	free(deck_array);
}
