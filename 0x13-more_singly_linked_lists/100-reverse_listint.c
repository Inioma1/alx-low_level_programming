#include "lists.h"

/**
 * #include "lists.h": its includes all prototype
 * @head: points to the first node in the list
 * reverse_listint - reverses a linked list
 * Return: points to the first node
 */


listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevs = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prevs;
		prevs = *head;
		*head = next;
	}

	*head = prevs;

	return (*head);
}

