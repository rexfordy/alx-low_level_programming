#include "lists.h"

/**
 * add_node_end - this adds a new node at the end
 * of a list_t list.
 * @head: this is the head of the linked list.
 * @str: this is the string to store in the list.
 * Return: this returns address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current_node;
	size_t t;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	for (t = 0; str[t]; t++)
		;

	new_node->len = t;
	new_node->next = NULL;
	current_node = *head;

	if (current_node == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}

	return (*head);
}
