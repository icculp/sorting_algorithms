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
* insertion_sort_list - sorts a doubly linked list of integers
* @list: Head of dlist
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *prev, *prev2;

	if (list == NULL)
		return;

	curr = next = *list;
	while (curr != NULL)
	{
		while (curr->prev != NULL)
		{
			prev = curr->prev;
			prev2 = prev;
			if (prev->n > curr->n)
				swapem(prev, curr, list);
			curr = prev2;
		}
		curr = next->next;
		next = curr;
	}

}
