#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct print
{
	char *format;
	int (*print_type)(va_list);
} type_find;

int _printf(const char *, ...);
int print_char(va_list);
int print_string(va_list);
int print_decimal(va_list);

#endif
