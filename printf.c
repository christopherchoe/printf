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
	int number_format;
	int n;
	char *buf;

	buf = malloc(sizeof(char));
	if (buf == NULL)
		return (0);
	buf = buffer_init(buf);
	if (buf == NULL)
		return (0);
	if (format != NULL)
		copy_format = format;
	else
	{
		return (-1);
	}
	number_format = 0;
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
					number_format = type_element[type_index].print_type(input, buf, number_format);
					copy_format++;
					break;
				}
				type_index++;
			}
		}
		else
			number_format = print_single_char(copy_format, buf, number_format);
		if (type_element[type_index].format == NULL)
		{
			if (*(copy_format + 1) != '%')
				number_format = print_single_char(copy_format, buf, number_format);
			number_format = print_single_char(++copy_format, buf, number_format);
		}
		copy_format++;
	}
	*(buf + number_format) = '\0';
	n = _strlen(buf);
	buffer_write(buf, n);
	va_end(input);

	return (n);
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
		{NULL, NULL}
	};
	va_list input;

	va_start(input, format);
	return (print_format(format, input, type_element));
}
