#include "sort.h"

/**
* merge - Merges the splits from merge_sorty
* @array: Array
*
*/

void merge(int *array, int low, int middle, int high)
{
	int *templeft, *tempright, sizeleft, sizeright, i, j, k;

	templeft = malloc(sizeof(int) * (middle - low + 1));
	tempright = malloc(sizeof(int) * (high - middle));
	printf("NEWMERGE\n");
	if (templeft == NULL || tempright == NULL)
		return;
	sizeleft = (middle - low + 1);
	sizeright = (high - middle);
	for (i = 0; i < sizeleft; i++)
		templeft[i] = array[low + i], printf("tleft: %d\n", templeft[i]);
	for (i = 0; i < sizeright; i++)
		tempright[i] = array[middle + 1 + i], printf("tright: %d\n", tempright[i]);
	i = j = 0, k = low;
	while (i < sizeleft && j < sizeright)
	{
		if (templeft[i] <= tempright[j])
			array[k] = templeft[i], i++;
		else
			array[k] = tempright[j], j++;
		k++;
	}
	while (i < sizeleft)
		array[k] = templeft[i], i++, k++;
	while (j < sizeright)
		array[k] = tempright[j], j++, k++;
}

/**
* merge_sorty - recurrsive function utilizing merge sort algo
* @array: Array
* @low: Lowest index of split
* @high: highest index of split
*/

void merge_sorty(int *array, int low, int high)
{
	int middle;

	if (low < high)
	{
		middle = low + ((high - low) / 2);
		merge_sorty(array, low, middle);
		merge_sorty(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

/**
* merge_sort - Sorts array with merge sort algo
* @array: array to sort
* @size: Size of array to sort
*/

void merge_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	merge_sorty(array, 0, size - 1);	
}
