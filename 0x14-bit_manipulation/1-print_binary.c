#include "main.h"
/**
 * print_binary - convert from decimal to binary
 * Function to output decimal to binary system with no use of % /
 * @b: the decimal number
 * Description: conversion from base 10 base 2
 * section header: Its header is main.h
 * Return: no return
 */
void print_binary(unsigned long int b)
{
	int flag = 0;
	unsigned long int msk = 1;

	msk <<= 63;
	if (b == 0)
		_putchar('0');

	while (msk > 0)
	{
		if ((b & msk) == 0 && flag == 1)
			_putchar('0');
		if ((b & msk) != 0)
		{
			_putchar('1');
			flag = 1;
		}

		msk = msk >> 1;
	}
}
