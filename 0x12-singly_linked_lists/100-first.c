#include <stdio.h>
/**
 * premain - This executes code before the main
 * description - This executes code before the main
 * return - non return, void function
 */
void __attribute__ ((constructor)) premain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
