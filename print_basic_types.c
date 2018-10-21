#include "holberton.h"

/**
  * print_char - prints the single character
  * @input: argument array that is passed
  * Return: 1
  */
int print_char(va_list input)
{
	char buf[1];

	buf[0] = va_arg(input, int);
	write(1, buf, sizeof(char));
	return (1);
}

/**
  * print_string - prints the string
  * @input: argument array that is passed
  * Return: number of characters
  */
int print_string(va_list input)
{
/*	char buf[];
	int i;

	buf = va_arg(input, char *);

	if (buf == NULL)
		return (0);

	return (write_buf(buf)); */
	return (0);
}

/**
  * print_decimal - print decimal integer
  * @input: argument array that is passed
  * Return: number of digits
  */
int print_decimal(va_list input)
{
	char *buf;
	int i, temp;

	temp = va_arg(input, int);

	write(1, buf, sizeof(char) * (i - 1));

	return (i - 1);
}

/**
  * print_single_char - prints single char to the output
  * @str: pointer input
  * Return: 1 because we only print one single char
  */
int print_single_char(const char *str)
{
	write(1, str, sizeof(char));

	return (1);
}
