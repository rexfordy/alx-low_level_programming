#include "main.h"
/**
 * cl_bit - set a bit to 0
 * @t: the number
 * @ind: the position to set the bit
 * Description: set 1 bit to 0
 * section header: the header  is main.h
 * Return: 1 in success -1 in failure
 */
int cl_bit(unsigned long int *t, unsigned int ind)
{
	if (ind > 64)
		return (-1);
	*t &= ~(1 << ind);
	return (1);
}
