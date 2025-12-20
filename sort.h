#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
	* struct listint_s - Doubly linked list node
	* @n: Integer stored in the node
	* @prev: Pointer to the previous node
	* @next: Pointer to the next node
	*
	* Description: Doubly linked list node structure for sorting algorithms.
	*/
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);

#endif
