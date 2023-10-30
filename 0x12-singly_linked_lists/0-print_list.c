#include "lists.h"
/**
 * print_list - This prints the elements in a list.
 * a blank line
 * @h: This is the list
 * Description: This prints the elements of one list
 * section header: This is the header of this function is lists.h
 * Return: this return the number of the elements in the list
 */
size_t print_list(const list_t *h)
{
	int t;

	for (t = 0; h ; t++)
	{
		if (h->str == '\0')
			printf("[0] (nil)\n");
		else
			printf("[%t] %s\n", h->len, h->str);
		h = h->next;
	}

	return (t);
}
