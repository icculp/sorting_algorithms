#include "sort.h"

/**
* swapem - Swaps tha nodes
* @l: left or lower node
* @r: right or later node
* @h: Head of dlist
*/

void swapem(listint_t *l, listint_t *r, listint_t **h)
{
	listint_t *temp;

	temp = l->prev;
	if (temp)
		temp->next = r;
	r->prev = temp;
	l->prev = r;
	l->next = r->next;
	r->next = l;
	if (l->next != NULL)
		l->next->prev = l;
	if (r->prev == NULL)
		*h = r;
	print_list(*h);
}

/**
* cocktail_sort_list - sorts dlist using cocktail sort
* @list: Head to dlist
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int isS = 1;
	int start = 0, end = 0, c;

	if (list == NULL)
		return;
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next, end++;
	temp = *list;
	while (isS == 1)
	{
		c = start;
		while (c < end)
		{
			if (temp->n > temp->next->n)
			{
				swapem(temp, temp->next, list);
				isS = 1;
			}
			else
				temp = temp->next;
			c++;
		}
		c = end, isS = 0;
		while (c > start)
		{
			if (temp->n < temp->prev->n)
			{
				swapem(temp->prev, temp, list);
				isS = 1;
			}
			else
				temp = temp->prev;
			c--;
		}
		start++;
	}
}
