#include "lists.h"

/**
 * print_dlistint - This prints a double linked list
 * @h: This is the double linked list
 * Return: This return the len of the double linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *actual = h;
	size_t len = 0;

	while (actual)
	{
		printf("%i\n", actual->n);
		actual = actual->next;
		len++;
	}
	return (len);
}
