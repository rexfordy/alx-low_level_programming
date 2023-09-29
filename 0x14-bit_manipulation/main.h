#ifndef BITMANIPULATION
#define BITMANIPULATION

#include <unistd.h>
#include <stdio.h>

int _putchar(char d);
unsigned int binary_to_uint(const char *x);
void print_binary(unsigned long int b);
int get_bit(unsigned long int t, unsigned int ind);
int set_bit(unsigned long int *t, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int ind);
unsigned int flag_bits(unsigned long int t, unsigned long int u);
int get_endianness(void);

#endif
