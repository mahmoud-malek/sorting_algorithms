#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * enum kind_e - An enum to represent the
 * different suits of a playing card.
 *@SPADE: is a kind
 *@HEART: is a kind
 *@CLUB: is a kind
 *@DIAMOND: is a kind
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
void print_deck(const deck_node_t *deck);

#endif /*Deck of cards header*/
