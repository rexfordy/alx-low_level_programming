#include "lists.h"
/**
 * list_len - This returns the number of elements
 * a blank line
 * @h: the list
 * Description: This prints the elements of one list)?
 * section header: This is the header of this function is lists.h
 * Return: This returns the number of the elements in the list
 */
size_t list_len(const list_t *h)
{
	int t;

	for (t = 0; h; t++)
	{
		h = h->next;
	}
	return (t);
}
