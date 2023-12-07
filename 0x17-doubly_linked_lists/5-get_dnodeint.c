#include "lists.h"

/**
 * get_dnodeint_at_index - This gets a specific index
 * @head: Here is the list.
 * @index: Here is the node to found
 * Return: the node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *actual;

	actual	= head;
	while (actual  != NULL && index != 0)
	{
		index--;
		actual = actual->next;
	}
	if (actual != NULL)
		return (actual);
	return (NULL);
}
