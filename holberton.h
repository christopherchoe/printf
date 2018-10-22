#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
  * struct print - prototype
  * @format: string that corresponds to conversion specifier
  * @print_type: pointer to function that will print the specified argument
  *
  * Description: this structure defines a prototype for diff. types in c
  */
typedef struct print
{
	char *format;
	int (*print_type)(va_list);
} Convert_Type;

/* printing functions */
int _printf(const char *, ...);
int print_char(va_list);
int print_string(va_list);
int print_decimal(va_list);
int print_single_char(const char *);

int print_unsigned(va_list);
int print_binary(va_list);
int print_hex_low(va_list);
int print_hex_cap(va_list);
int print_octal(va_list);

/* utility functions */
int _strlen(char *);
char *_itoa(int);
int count_digits(int);
unsigned int power(int, int);
#endif
