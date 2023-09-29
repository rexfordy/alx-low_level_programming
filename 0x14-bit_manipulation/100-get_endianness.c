#include "main.h"
/**
 * get_endianness - get the endiannes of the arch
 * Description: Function to get the endianes of the arch
 * section header: the header is main.h
 * Return: 1 in little indian - 0 in big indian.
 */

int get_endianness(void)
{
	unsigned int b = 1;
	char *d = (char *)&b;

	if (*d)
		return (1);
	return (0);
}
