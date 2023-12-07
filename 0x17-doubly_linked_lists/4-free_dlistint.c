#include "lists.h"

/**
 * free_dlistint - This frees a list
 * @head: This is the list.
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}
