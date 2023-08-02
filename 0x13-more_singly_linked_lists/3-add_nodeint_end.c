#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * @head: This points to the first element in the list
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *New;
	listint_t *temp = *head;

	New = malloc(sizeof(listint_t));
	if (!New)
		return (NULL);

	New->n = n;
	New->next = NULL;

	if (*head == NULL)
	{
		*head = New;
		return (New);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = New;

	return (New);
}
