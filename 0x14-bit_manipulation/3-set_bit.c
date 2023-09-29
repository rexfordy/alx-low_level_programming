#include "main.h"
/**
 * set_bit - set a bit to 1
 * @t: the number
 * @index: the position to set the bit
 * Description: set 1 bit to 1
 * section header: the header is main.h
 * Return: 1 in success -1 in failure
 */
int set_bit(unsigned long int *t, unsigned int index)
{
	if (index > 64)
		return (-1);
	*t += 1 << index;
	return (1);
}
