#include <stdio.h>
/**
* main - prints all the numbers of base 16 in lowercase,
* followed by a new line
* Return: 0 (Success)
*/
int main(void)
{
int b;
char ch;
for (b = 48; b < 58; b++)
{
putchar(b);
}
for (ch = 'a'; ch <= 'f'; ch++)
{
putchar(ch);
}
putchar('\n');
return (0);
}
