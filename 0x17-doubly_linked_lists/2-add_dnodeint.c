#include "lists.h"

/**
 * add_dnodeint - This adds a new node in a double list
 * @head: This is the list
 * @n: This is the value to store in the node
 * Return: the node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *tmp;

	tmp = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	if (tmp == NULL)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}
	new->next = tmp;
	tmp->prev = new;
	*head = new;
	return (new);
}
