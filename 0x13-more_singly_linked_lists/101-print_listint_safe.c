#include "lists.h"
#include <stdio.h>

size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

/**
 * #include "lists.h": its includes all prototypes
 * looped_listint_len - Counts the number of unique nodes
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped return - 0.
 * 
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *Tortoise, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	Tortoise = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (Tortoise == hare)
		{
			Tortoise = head;
			while (Tortoise != hare)
			{
				nodes++;
				Tortoise = Tortoise->next;
				hare = hare->next;
			}

			Tortoise = Tortoise->next;
			while (Tortoise != hare)
			{
				nodes++;
				Tortoise = Tortoise->next;
			}

			return (nodes);
		}

		Tortoise = Tortoise->next;
		hare = (hare->next)->next;
	}

	return (0);
}

size_t print_listint_safe(const listint_t *head)
{
	size_t Node, index = 0;

	Node = looped_listint_len(head);

	if (Node == 0)
	{
		for (; head != NULL; Node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < Node; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (Node);
}
