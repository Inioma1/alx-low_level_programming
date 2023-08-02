#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * 
 * free_listint: This frees a linked list
 * 
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
