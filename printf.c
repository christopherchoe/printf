#include "holberton.h"

int _printf(const char *format, ...);

/**
  * print_format - prints the input string
  * @format: format string
  * @input: input array from variable argument list
  * @type_element: pointer to an array of structures of type Convert type
  * Return: number of printed characters (excluding null byte)
  */
int print_format(const char *format, va_list input, Convert_Type *type_element)
{
	const char *copy_format;
	int type_index;
	int num_printed;

	if (format != NULL)
		copy_format = format;
	else
		return (-1);
	num_printed = 0;
	/* go through the format string */
	while (*copy_format != '\0')
	{
		type_index = 0;
		/* check for conversion specifier */
		if (*copy_format == '%')
		{
			/* iterate through the type_elements array */
			while (type_element[type_index].format != NULL)
			{
				if (*(type_element[type_index].format) == *(copy_format + 1))
				{
					num_printed += type_element[type_index].print_type(input);
					copy_format++;
					break;
				}
				type_index++;
			}
		}
		else
			num_printed += print_single_char(copy_format);
		if (type_element[type_index].format == NULL)
		{
			if (*(copy_format + 1) != '%')
				num_printed += print_single_char(copy_format);
			num_printed += print_single_char(++copy_format);
		}
		copy_format++;
	}
	va_end(input);
	return (num_printed);
}

/**
  * _printf - declares the array for different types
  * @format: format of the string to be printed out
  * Return: number of values printed
  */
int _printf(const char *format, ...)
{
	Convert_Type type_element[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_decimal},
		{"i", print_decimal},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_low},
		{"X", print_hex_cap},
		{NULL, NULL}
	};
	va_list input;

	va_start(input, format);
	return (print_format(format, input, type_element));
}
