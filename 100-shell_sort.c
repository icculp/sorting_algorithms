#include "sort.h"

/**
* shell_sort - Sorts array using Knuth Sequence of Shell sort
* @array: Array to be sorted
* @size: Size of array to sort
*/

void shell_sort(int *array, size_t size)
{
	size_t i, gap = 1, k, n;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (k = i; (k > 0) && (array[k] < array[k - gap]); k -= gap)
			{
				n = array[k];
				array[k] = array[k - gap];
				array[k - gap] = n;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
