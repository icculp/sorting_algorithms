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
* radix_sort - Sorts an array using radix sort algo
* @array: Array to sort
* @size: size of array
*/

void radix_sort(int *array, size_t size)
{
	int m, pos;

	if (array == NULL || size < 2)
		return;
	m = findmax(array, size);
	for (pos = 1; m / pos > 0; pos *= 10)
		counting_sort_r(array, size, pos), print_array(array, size);
}

/**
* counting_sort_r - sorts array using counting algorithm
* @array: Array to sort
* @size: Size of array
* @pos: Digit position value
*/

void counting_sort_r(int *array, size_t size, int pos)
{
	int *ca, i, *out;

	if (array == NULL || size < 2)
		return;
	out = malloc(sizeof(int) * (int)size);
	ca = malloc(sizeof(int) * (10));
	if (ca == NULL || out == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		ca[(array[i] / pos) % 10] += 1;
	for (i = 0; i < (int)size; i++)
		ca[i] += ca[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		out[ca[((array[i] / pos) % 10)] - 1] = array[i];
		ca[((array[i] / pos) % 10)] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
}
