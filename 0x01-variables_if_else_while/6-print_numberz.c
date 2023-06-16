#include <stdio.h>
/**
* main - prints all single digit numbers of base 10 starting from 0,
* followed by a new line, using putchar
* Return: 0 (Success)
*/
int main(void)
{
int k;
for (k = 48; k < 58; k++)
{
putchar(k);
}
putchar('\n');
return (0);
}
