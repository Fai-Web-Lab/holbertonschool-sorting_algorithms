#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* insertion_sort_list - sorts a doubly linked list of integers in
	*                       ascending order using Insertion sort
	* @list: pointer to the pointer to the head of the list
	*
	* Description: Swaps nodes themselves; prints list after each swap.
	*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
	return;

	current = (*list)->next;
	while (current)
	{
	tmp = current;
	while (tmp->prev && tmp->n < tmp->prev->n)
	{

	listint_t *prev = tmp->prev;
	listint_t *next = tmp->next;


	if (prev->prev)
	prev->prev->next = tmp;
	tmp->prev = prev->prev;


	tmp->next = prev;
	prev->prev = tmp;


	prev->next = next;
	if (next)
	next->prev = prev;


	if (!tmp->prev)
	*list = tmp;

	print_list(*list);
	}
	current = current->next;
	}
}
