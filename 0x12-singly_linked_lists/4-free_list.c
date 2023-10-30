#include "lists.h"

/**
 * free_list - this frees a list
 * @head: this is the head of the linked list.
 * Return: this has no return.
 */

void free_list(list_t *head)
{
	list_t *current_node;

	while ((current_node = head) != NULL)
	{
		head = head->next;
		free(current_node->str);
		free(current_node);
	}
}
