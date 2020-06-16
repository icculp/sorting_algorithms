#include "sort.h"

/**
* findmax - Finds the maximum value in an array
* @array: array to find max value of
* @size: Size of array
* Return: Largest value
*/

int findmax(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
* count - Counts number of occurences of value in an array
* @array: Array to count values of
* @size: Size of array
* @val: Value to count in the array
* Return: Count of va
*/

int count(int *array, size_t size, int val)
{
	int c = 0, i;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] == val)
			c++;
	}
	return (c);
}

/**
* counting_sort - sorts array using counting algorithm
* @array: Array to sort
* @size: Size of array
*/

void counting_sort(int *array, size_t size)
{
	int max, *ca, i, *out, j;

	if (array == NULL || size < 2)
		return;
	max = findmax(array, size);
	out = malloc(sizeof(int) * (int)size);
	ca = malloc(sizeof(int) * (max + 1));
	if (ca == NULL || out == NULL)
		return;
	for (i = j = 0; i < max + 1; i++)
	{
		j += count(array, size, i);
		ca[i] = j;
	}
	print_array(ca, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		out[ca[array[i] - 1]] = array[i];
		ca[array[i] - 1] += 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];

	free(out);
	free(ca);
}
