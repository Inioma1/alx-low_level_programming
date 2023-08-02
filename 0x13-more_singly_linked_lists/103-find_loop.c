#include "lists.h"


/**
 * #include "lists.h": its includes all prototype.
 * @head: linked list you want to look for,
 *
 * Return: it returns address of the node where the loop will starts.
 */


listint_t *find_listint_loop(listint_t *head)
{
	listint_t *Slow = head;
	listint_t *Fast = head;

	if (!head)
		return (NULL);

	while (Slow && Fast && Fast->next)
	{
		Fast = Fast->next->next;
		Slow = Slow->next;
		if (Fast == Slow)
		{
			Slow = head;
			while (Slow != Fast)
			{
				Slow = Slow->next;
				Fast = Fast->next;
			}
			return (Fast);
		}
	}
	return (NULL);
}
