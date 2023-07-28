#include <stdlib.h>
#include "lists.h"

/**
 * Returns number of elements in a linked list
 * @h: this points to  Pointer to the list_t list
 *
 * Return:This returns number of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}

