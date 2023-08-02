#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * @head: This points to the first node in the list
 * @n: data to be inserted in new node
 *
 * Return: Its points to the new node and its NULL if fails
 * 
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *New;

	New = malloc(sizeof(listint_t));
	if (!New)
		return (NULL);

	New->n = n;
	New->next = *head;
	*head = New;

	return (New);
}
