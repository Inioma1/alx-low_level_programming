#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * @head:  This points to the listint_t list
 */


void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
