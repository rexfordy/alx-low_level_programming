#include "main.h"
/**
 * set_bit - set a bit to 1
 * @n: the number
 * @index: the position to set the bit
 * Description: set 1 bit to 1
 * section header: the header of this function is main.h
 * Return: 1 if success, or -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 64)
		return (-1);
	*n += 1 << index;
	return (1);
}
