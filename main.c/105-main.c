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
    int array[] = {6, 8, 3};
/**    int array[] = {48, 99, 71, 13, 52, 96, 73, 86, 7, 8, 22, 25, 82, 63, 44, 57};*/
/**    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};*/
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
