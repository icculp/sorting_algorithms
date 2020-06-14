#include "sort.h"

/**
* selection_sort - sorts array using selection sort
* @array: array to be sorted
* @size: Size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, t, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		t = array[min];
		array[min] = array[i];
		array[i] = t;
		print_array(array, size);
	}

}
