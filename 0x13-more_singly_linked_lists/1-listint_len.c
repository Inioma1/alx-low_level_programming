#include "lists.h"

/**
 * 
 * @h: listint_t to traverse
 * 
 * listint_len - This returns the  number of elements in a linked lists
 * 
 * Return: The  number of nodes
 */


size_t listint_len(const listint_t *h)
{
	size_t  Num = 0;

	while (h)
	{
		 Num++;
		h = h->next;
	}

	return (Num);
}


