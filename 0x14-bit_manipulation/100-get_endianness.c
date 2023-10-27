#include "main.h"
/**
 * get_endianness - This gets the endiannes of the arch
 * Description: Get the endiannes of the arch
 * section header: the header of this function is main.h
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int n = 1;
	char *c = (char *)&n;

	if (*c)
		return (1);
	return (0);
}
