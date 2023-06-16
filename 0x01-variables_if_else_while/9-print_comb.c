#include <stdio.h>
/**
* main - prints all possible combinations of single-digit numbers
* Return: 0 (Success)
*/
int main(void)
{
int t;
for (t = 48; t < 58; t++)
{
putchar(t);
if (t != 57)
{
putchar(',');
putchar(' ');
}
}
putchar('\n');
return (0);
}
