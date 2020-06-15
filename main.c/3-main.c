#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
/** int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
/**	int array[] = {68, 5, 40, 77, 98, 99, 52, 89, 92, 87, 35, 71, 93, 3, 79, 78, 8, 48, 56, 24, 21, 59, 27, 85, 58, 11, 7, 50, 6, 12, 53, 94, 63, 88, 46, 37, 22, 70, 29, 15, 17, 54, 82, 38, 64, 55, 1, 41, 100, 45};*/
/**	int array[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};*/
	int *array = NULL;
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
