#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
	* merge - merges two sorted subarrays
	* @array: array of integers
	* @tmp: temporary array
	* @left: left index of the subarray
	* @mid: middle index, start of right subarray
	* @right: right index of the subarray
	*/
static void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k, x;

	i = left;
	j = mid;
	k = left;

	printf("Merging...\n[left]: ");
	for (x = left; x < mid; x++)
	printf("%d%s", array[x], (x < mid - 1) ? ", " : "\n");

	printf("[right]: ");
	for (x = mid; x < right; x++)
	printf("%d%s", array[x], (x < right - 1) ? ", " : "\n");

	while (i < mid && j < right)
	{
	if (array[i] <= array[j])
	tmp[k++] = array[i++];
	else
	tmp[k++] = array[j++];
	}

	while (i < mid)
	tmp[k++] = array[i++];
	while (j < right)
	tmp[k++] = array[j++];

	for (x = left; x < right; x++)
	array[x] = tmp[x];

	printf("[Done]: ");
	for (x = left; x < right; x++)
	printf("%d%s", array[x], (x < right - 1) ? ", " : "\n");
}

/**
	* merge_sort_recursive - recursively sorts subarrays
	* @array: array of integers
	* @tmp: temporary array
	* @left: left index
	* @right: right index
	*/
static void merge_sort_recursive(int *array, int *tmp,
	size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
	return;

	mid = left + (right - left) / 2;
	merge_sort_recursive(array, tmp, left, mid);
	merge_sort_recursive(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
}

/**
	* merge_sort - sorts an array of integers in ascending order
	*             using the top-down merge sort algorithm
	* @array: array of integers
	* @size: size of the array
	*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
	return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
	return;

	merge_sort_recursive(array, tmp, 0, size);
	free(tmp);
}
