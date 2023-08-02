#include "lists.h"

/**
 * #include "lists.h": its includes all prototypes 
 * @head: pointer to the first element in the linked list
 * 
 * pop_listint - It deletes the head node of a linked list
 * Return: This returns the data inside the elements that was deleted,
 * 
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int Num;

	if (!head || !*head)
		return (0);

	Num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (Num);
}
