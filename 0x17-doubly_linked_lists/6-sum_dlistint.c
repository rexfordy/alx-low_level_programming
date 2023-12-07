#include "lists.h"

/**
 * sum_dlistint - This is the sum of a list
 * @head: this is the list
 * Return: the sum
 */
int sum_dlistint(dlistint_t *head)
{
		int result = 0;
		dlistint_t *actual;

		actual = head;

		while (actual)
		{
			result += actual->n;
			actual = actual->next;
		}
		return (result);
}
