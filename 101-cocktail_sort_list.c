#include "sort.h"
#include <stdio.h>

/**
	* swap_nodes - Swaps two nodes in a doubly linked list
	* @list: Double pointer to the head of the list
	* @first: Pointer to the first node
	* @second: Pointer to the second node
	*/
void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
	if (first->prev)
	first->prev->next = second;
	else
	*list = second;

	if (second->next)
	second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;

	first->prev = second;
	second->next = first;

	print_list(*list);
}

/**
	* forward_pass - Moves through the list forward, swapping nodes if needed
	* @list: Double pointer to the head of the list
	* @swapped: Pointer to the swapped flag
	*/
void forward_pass(listint_t **list, int *swapped)
{
	listint_t *current = *list;

	while (current && current->next)
	{
	if (current->n > current->next->n)
	{
	swap_nodes(list, current, current->next);
	*swapped = 1;
	current = current->prev;
	}
	current = current->next;
	}
}

/**
	* backward_pass - Moves through the list backward, swapping nodes if needed
	* @list: Double pointer to the head of the list
	* @swapped: Pointer to the swapped flag
	*/
void backward_pass(listint_t **list, int *swapped)
{
	listint_t *current = *list;

	while (current && current->next)
	current = current->next;

	while (current && current->prev)
	{
	if (current->n < current->prev->n)
	{
	swap_nodes(list, current->prev, current);
	*swapped = 1;
	current = current->next;
	}
	current = current->prev;
	}
}

/**
	* cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
	* @list: Double pointer to the head of the list
	*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;

	if (!list || !*list || !(*list)->next)
	return;

	swapped = 1;
	while (swapped)
	{
	swapped = 0;
	forward_pass(list, &swapped);
	if (!swapped)
	break;
	swapped = 0;
	backward_pass(list, &swapped);
	}
}
