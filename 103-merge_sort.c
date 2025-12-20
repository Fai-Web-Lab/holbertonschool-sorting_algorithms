#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
	* merge - Merge two sorted subarrays into one
	* @array: Pointer to the original array
	* @tmp: Pointer to the temporary array
	* @left: Left index of subarray
	* @mid: Mid index (end of left subarray)
	* @right: Right index of subarray
	*/
static void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	for (size_t x = left; x < mid; x++)
	printf("%d%s", array[x], (x < mid - 1) ? ", " : "\n");
	printf("[right]: ");
	for (size_t x = mid; x < right; x++)
	printf("%d%s", array[x], (x < right - 1) ? ", " : "\n");

	while (i < mid && j < right)
	tmp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i < mid)
	tmp[k++] = array[i++];
	while (j < right)
	tmp[k++] = array[j++];

	for (size_t x = left; x < right; x++)
	array[x] = tmp[x];

	printf("[Done]: ");
	for (size_t x = left; x < right; x++)
	printf("%d%s", array[x], (x < right - 1) ? ", " : "\n");
}

/**
	* merge_sort_rec - Recursive top-down merge sort helper
	* @array: Pointer to the array to sort
	* @tmp: Pointer to the temporary array
	* @left: Left index
	* @right: Right index
	*/
static void merge_sort_rec(int *array, int *tmp, size_t left, size_t right)
{
	if (right - left > 1)
	{
	size_t mid = left + (right - left) / 2;

	merge_sort_rec(array, tmp, left, mid);
	merge_sort_rec(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
	}
}

/**
	* merge_sort - Sorts an array of integers in ascending order
	* @array: Pointer to the array to sort
	* @size: Number of elements in the array
	*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
	return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
	return;

	merge_sort_rec(array, tmp, 0, size);
	free(tmp);
}
