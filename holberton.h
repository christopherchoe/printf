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

/* printf functions */
int _printf(const char *, ...);
int print_format(const char *, va_list, Convert_Type *);
int check_null_str(const char *, va_list);

/* printf basic types */
int print_char(va_list);
int print_string(va_list);
int print_decimal(va_list);
int print_single_char(const char *);

/* printing advanced types */
int print_unsigned(va_list);
int print_binary(va_list);
int print_hex_low(va_list);
int print_hex_cap(va_list);
int print_octal(va_list);

/* printing manipulated strings */
int print_rev_str(va_list);
int print_rot13(va_list);
int print_unprint(va_list);
char *unprint_hex(int);
int unprint_strlen(char *);
char *string_malloc(char *);
char *rev_string(char *);
char *rot13(char *);

/* printing extra types */
int print_address(va_list);

/* utility functions */
int _strlen(char *);
char *_itoa(int);
char *_u_itoa(unsigned long int);
int count_digits(int);
unsigned long int power(unsigned long int, unsigned long int);
#endif
