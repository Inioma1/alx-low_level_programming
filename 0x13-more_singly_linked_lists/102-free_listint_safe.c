#include "lists.h"

/**
 * 
 * #include "lists.h": its includes all prototypes
 * @h: points to the first node in the list
 * free_listint_safe - frees a list
 * Returns: number of elements in the feed list
 * 
 */


size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}