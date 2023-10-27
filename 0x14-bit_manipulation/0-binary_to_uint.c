#include "main.h"
/**
 * binary_to_uint - This converts binary to decimal.
 * @b: the binary number in string format
 * Description: This converts binary to decimal
 * section header: The header of this function is main.h
 * Return: this return the convert number
 * or 0 if there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result, base;
	int n;

	result = 0;
	n = 0;
	base = 1;

	if (!b)
		return (0);

	while (*(b + n))
	{
		if (*(b + n) != '0' && *(b + n) != '1')
			return (0);
		n++;
	}
	for (n--; n >= 0; n--)
	{
		if (*(b + n) == '1')
			result = result + base;
		base = base * 2;
	}

	return (result);
}
