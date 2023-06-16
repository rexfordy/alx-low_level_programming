#include <stdio.h>
/**
* main - Prints numbers between 00 to 89.
* Return:  0 (Success)
*/
int main(void)
{
int t, m;
t = 48;
m = 48;
while (m < 58)
{
t = 48;
while (t < 58)
{
if (m != t && m < t)
{
putchar(m);
putchar(t);
if (t == 57 && m == 56)
{
break;
}
putchar(',');
putchar(' ');
}
t++;
}
m++;
}
putchar('\n');
return (0);
}
