#include "lists.h"

/**
 * #include "lists.h": its includes all prototype.
 * delete_nodeint_at_index - This deletes a node in a linked list to a certain index
 * @head: pointer to the first element in the list.
 * @index: index of the node to delete.
 * Returns -1 for fail and 1 for success.
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);
	return (1);

}
