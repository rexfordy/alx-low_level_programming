#include "main.h"
/**
 * flip_bits - This counts the bit to change to another value
 * @n: the number
 * @m: the number to compare
 * Description: compare to integers a count the differences in bits
 * section header: the header of this function is main.h
 * Return: the number of different bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int n;

	n = 0;
	n = n ^ m;
	while (n)
	{
		n += n & 1;
		n >>= 1;
	}
	return (n);
}
