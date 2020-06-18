#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** provided functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/** 0 */
void bubble_sort(int *array, size_t size);

/** 1 */
void insertion_sort_list(listint_t **list);
void swapem(listint_t *l, listint_t *r, listint_t **h);

/** 2 */
void selection_sort(int *array, size_t size);

/** 3 */
void quick_sort(int *array, size_t size);
int partition(int *a, int l, int h);
void qs(int *a, int l, int h);

/** advanced */

/** 4 */
void shell_sort(int *array, size_t size);

/** 5 */
void cocktail_sort_list(listint_t **list);

/** 6 */
void counting_sort(int *array, size_t size);
int findmax(int *array, size_t size);
int count(int *array, size_t size, int val);

/** 7 */
void merge_sort(int *array, size_t size);
void merge(int *array, int low, int middle, int high, int *temp);
void merge_sorty(int *array, int low, int high, int *temp);

/** 8 */
void heap_sort(int *array, size_t size);

/** 9 */
void radix_sort(int *array, size_t size);
void counting_sort_r(int *array, size_t size, int pos, int *out, int *ca);

/** 10 */
void bitonic_sort(int *array, size_t size);
void swapint(int *l, int *r);
void b_sort(int *array, int low, int count, int dir, size_t size);
void b_merge(int *array, int low, int count, int dir, size_t size);

/** 11 */
void quick_sort_hoare(int *array, size_t size);
int partition_hoare(int *a, int l, int h);

#endif
