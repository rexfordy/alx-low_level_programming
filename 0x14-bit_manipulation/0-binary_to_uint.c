#include "main.h"
/**
 * bin_to_uint - to convert from base 2 to vase 10.
 * @x: the number use to conveet to base 10.
 * base 2 is in string format
 * Description: conversion of binary to decimal
 * The header of this function is main.h
 * Return: This function returns the number converted
 */

unsigned int bin_to_uint(const char *x)
{
	unsigned int answer, base;
	int n;

	answer = 0;
	n = 0;
	base = 1;

	if (!x)
		return (0);

	while (*(x + n))
	{
		if (*(x + n) != '0' && *(n + i) != '1')
			return (0);
		i++;
	}
	for (n--; n >= 0; n--)
	{
		if (*(x + n) == '1')
			answer = answer + base;
		base = base * 2;
	}

	return (answer);
}

