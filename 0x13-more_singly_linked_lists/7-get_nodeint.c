#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * get_nodeint_at_index - It returns nodes of a particular index
 * @head: The first node in the linked list
 *
 * Return: pointers to the node we're looking for, or NULL
 */


listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}

