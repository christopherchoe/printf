#include "holberton.h"

int _printf(const char *format, ...);

/**
  * print_format - prints the input string
  * @format: format string
  * @input: input array from variable argument list
  * Return: number of printed characters (excluding null byte)
  */
int print_format(const char *format, va_list input, Conversion_Type *type_elements)
{
	const char *copy_format;
	int type_index;
	int num_printed;
	char *null_char = "";
	copy_format = format;
	num_printed = 0;
	/* go through the format string */
	while (*copy_format != '\0')
	{
		type_index = 0; 
		/* check for conversion specifier */
		if (*copy_format == '%')
		{
			/* iterate through the type_elements array */
			while (type_elements[type_index].format != NULL)
			{
				if (*(type_elements[type_index].format) == *(copy_format + 1))
				{
					num_printed += type_elements[type_index].print_type(input);
					copy_format++;
					break;
				}
				type_index++;
			}
		}
		else
		{
			/* print non conversion specifiers to standard output */
			num_printed += print_single_char(copy_format);
		}
		copy_format++;
	}
	write(1, null_char, sizeof(char));
	va_end(input);
}

int _printf(const char *format, ...)
{
	Conversion_Type type_elements[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_decimal},
		{"i", print_decimal},
		{NULL, NULL}
	};
	va_list input;
	
	va_start(input, format);
	return (print_format(format, input, type_elements));
}
