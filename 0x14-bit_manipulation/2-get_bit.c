#include "main.h"
/**
 * get_bit - Take the bit and return one bit
 * @t:  number
 * @ind: the position to read the bit
 * Description: return 1 bit
 * section header: the header is main.h
 * Return: the value of the bit
 */
int get_bit(unsigned long int t, unsigned int ind)
{
	unsigned long int bit;

	if (ind > 64)
		return (-1);

	bit = t >> ind;

	return (bit & 0x1);
}
