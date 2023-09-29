#include "main.h"
/**
 * fl_bits - count the bit to change to another value
 * @t: the number
 * @u: the number to compare
 * Description: compare to integer and count the differences in bits
 * section header: the header is main.h
 * Return: the number of different bits
 */
unsigned int fl_bits(unsigned long int t, unsigned long int u)
{
	int b;

	b = 0;
	t = t ^ u;
	while (t)
	{
		b += t & 1;
		t >>= 1;
	}
	return (b);
}
