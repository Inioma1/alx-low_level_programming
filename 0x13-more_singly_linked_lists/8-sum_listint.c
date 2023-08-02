#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes
 * sum_listint - This is the sum of all the data in a listint_t list
 * @head: The first node in the linked list
 *
 * Return: returning the sum
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}

