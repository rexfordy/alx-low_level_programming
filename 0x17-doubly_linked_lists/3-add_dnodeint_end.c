#include "lists.h"

/**
 * add_dnodeint_end - This adds a node in the tail of a double linked list
 * @head: This is the list
 * @n: This is the value to store in the node
 * Return: the node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *actual;

	actual = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->n = n;

	if (actual == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (actual->next)
	{
		actual = actual->next;
	}
	actual->next = new;
	new->prev = actual;
	return (new);
}
