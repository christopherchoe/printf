#include "holberton.h"

/**
  * _printf - prints the input string
  * @format: format string
  * Return: number of printed characters (excluding null byte)
  */
int _printf(const char *format, ...)
{
	type_find type_elements[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_decimal},
		{"i", print_decimal},
		{NULL, NULL}
	};
	va_list input;
	char *copy_format;
	int type_index;
	int num_printed;

	va_start(input, format);
	copy_format = format;

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
				/* when match is found */
				if (*(type_elements[type_index].format) == *(copy_format + 1))
				{
					type_elements[type_index].print_type(input);
					copy_format++;
					break;
				}
				type_index++;
			}
		}
		else
		{
			/* print non conversion specifiers to standard output */
		}
		copy_format++;
	}
}
