#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
	* shell_sort - sorts an array of integers in ascending order
	* @array: pointer to the array to sort
	* @size: number of elements in the array
	*
	* Description: Prints the array each time the interval decreases
	*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
	return;

	while (gap < size / 3)
	gap = gap * 3 + 1;

	while (gap > 0)
	{
	for (i = gap; i < size; i++)
	{
	temp = array[i];
	j = i;
	while (j >= gap && array[j - gap] > temp)
	{
	array[j] = array[j - gap];
	j -= gap;
	}
	array[j] = temp;
	}

	print_array(array, size);

	gap = (gap - 1) / 3;
	}
}
