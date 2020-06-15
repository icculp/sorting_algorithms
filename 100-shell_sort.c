#include "sort.h"

/**
* shell_sort - Sorts array using Knuth Sequence of Shell sort
* @array: Array to be sorted
* @size: Size of array to sort
*/

void shell_sort(int *array, size_t size)
{
	size_t i, gap = 1, k;
	int v;

	if (array == NULL)
		return;
	while (gap < size)
		gap = 3 * gap + 1;
	if (gap >= size)
		gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			v = array[i];
			for (k = i; (k > gap - 1) && (v < array[k - gap]); k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = v;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
