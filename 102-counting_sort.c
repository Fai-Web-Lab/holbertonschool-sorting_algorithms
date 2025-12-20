#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* find_max - Finds the maximum value in an array
	* @array: The array to search
	* @size: Number of elements in array
	*
	* Return: The maximum integer in array
	*/
int find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	if (array[i] > max)
	max = array[i];
	return (max);
}

/**
	* counting_sort - Sorts an array of integers using Counting sort
	* @array: The array to sort
	* @size: Number of elements in array
	*/
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max;
	size_t i;

	if (!array || size < 2)
	return;

	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
	{
	free(count);
	free(output);
	return;
	}

	for (i = 0; i <= (size_t)max; i++)
	count[i] = 0;

	for (i = 0; i < size; i++)
	count[array[i]]++;

	print_array(count, max + 1);

	for (i = 1; i <= (size_t)max; i++)
	count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
	output[count[array[i - 1]] - 1] = array[i - 1];
	count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
	array[i] = output[i];

	free(count);
	free(output);
}
