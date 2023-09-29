#ifndef BITMANIPULATION
#define BITMANIPULATION

#include <unistd.h>
#include <stdio.h>

int _putchar(char d);
unsigned int bin_to_uint(const char *b);
void print_bin(unsigned long int b);
int get_bit(unsigned long int t, unsigned int ind);
int set_b(unsigned long int *t, unsigned int ind);
int cl_bit(unsigned long int *n, unsigned int ind);
unsigned int fl_bits(unsigned long int t, unsigned long int u);
int get_endianness(void);

#endif
