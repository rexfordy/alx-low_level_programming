#include <stdio.h>
/**
* main - prints all possible different combinations of three digits
* Return: Always 0 (Success)
*/
int main(void)
{
int p, o, n;
for (p = 48; p < 58; p++)
{
for (o = 49; o < 58; o++)
{
for (n = 50; n < 58; n++)
{
if (n > o && o > p)
{
putchar(p);
putchar(o);
putchar(n);
if (p != 55 || o != 56)
{
putchar(',');
putchar(' ');
}
}
}
}
}
putchar('\n');
return (0);
}
