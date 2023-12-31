#ifndef LISTS_H
#define LISTS_H

/**
 * struct list_s - This means Singly linked list
 * @str: string - (malloc'ed str)
 * @len: It means length of the str
 * @next: It Points to next node
 *
 * This is a Singly linked list node structure for Holberton project
 *
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
void free_list(list_t *head);

#endif
