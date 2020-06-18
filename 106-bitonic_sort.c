#include "sort.h"

void swapint(int *l, int *r);
void b_sort(int *array, int low, int count, int dir, size_t size);
void b_merge(int *array, int low, int count, int dir, size_t size);

/**
* swapint - swaps index's of array
* @array: Array to sort
* @size: size of array
*/

void swapint(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
*
*/

void b_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, n;

	if (count > 1)
	{
		n = count / 2;
		for (i = low; i < low + n; i++)
		{
			if (((array[i] > array[i + n]) && dir == 1) ||
			(dir == 0 && (array[i] < array[i + n])))
			{
				swapint(&array[i], &array[i + n]);
				printf("Result [%d/%d]", n, (int)size);
				if (dir == 1)
					printf("(UP):\n");
				else
					printf("(DOWN):\n");
				printf("%d, %d\n", array[i], array[i + n]);
			/**	printf("merging\n");
				print_array(array, n);*/
			}
		}
		b_merge(array, low, n, dir, size);
		b_merge(array, low + n, n, dir, size);
	}
}


void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int n;

	if (count > 1)
	{
		n = count / 2;
				if (dir == 1)
					printf("(UP):\n");
				else
					printf("(DOWN):\n");
				print_array(array, n);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		b_merge(array, low, count, dir, size);
	}
}

/**
* bitonic_sort - Sorts array using bitonic algo
* @array: Array to sort
* @size: Size of array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
/**	print_array(array, size);*/
/**	swapint(&array[0], &array[1]);*/
/**	print_array(array, size);*/
	b_sort(array, 0, size, 1, size);
}
