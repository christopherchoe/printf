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
	int (*print_type)(va_list, char *, int);
} Convert_Type;

int _printf(const char *, ...);
int print_char(va_list, char *, int);
int print_string(va_list, char *, int);
int print_decimal(va_list, char *, int);
int print_single_char(const char *, char *, int);
int _strlen(char *);
char *_itoa(int);
int count_digits(int);
unsigned int power(int, int);
char *buffer_init(char *);
int buffer_copy(char *, char *, int);
char *buffer_write(char *, int);
int buffer_over(int);
#endif
