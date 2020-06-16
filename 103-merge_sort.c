#include "sort.h"

/**
* merge - Merges the splits from merge_sorty
* @array: Array split to merge
* @low: lowest index of split
* @middle: middle index of split
* @high: high index of split
*/

void merge(int *array, int low, int middle, int high)
{
	int *temp, i, j, k, l = 0, r = 0, n, left[4096], right[4096];

	temp = malloc(sizeof(int) * (high - low + 1));
	if (temp == NULL)
		return;
	printf("Merging...\n");
	i = low, j = middle + 1, k = l = 0;
	while (i <= middle && j <= high)
	{
		if (array[i] <= array[j])
			temp[k] = left[l] = array[i], k++, i++, l++;
		else
			temp[k] = right[r] = array[j], k++, j++, r++;
	}
	while (i <= middle)
		temp[k] = left[l] = array[i], k++, i++, l++;
	while (j <= high)
		temp[k] = right[r] = array[j], k++, j++, r++;
	printf("[left]: ");
	for (n = 0; n < l; n++)
		(n == 0) ? printf("%d", left[n]) : printf(", %d", left[n]);
	printf("\n[right]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", right[n]) : printf(", %d", right[n]);
	printf("\n[Done]: ");
	for (i = low; i <= high; i++)
	{
		array[i] = temp[i - low], printf("%d", array[i]);
		if (i != high)
			printf(", ");
		else
			printf("\n");
	}
	free(temp);
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
		middle = ((high + low - 1) / 2);
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
