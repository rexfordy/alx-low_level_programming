#include "lists.h"

/**
 * dlistint_len - This return the length of a double list
 * @h: This is the double linked list
 * Return: Return the len of the lists
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *actual = h;
	size_t len = 0;

	while (actual)
	{
		actual = actual->next;
		len++;
	}
	return (len);
}
