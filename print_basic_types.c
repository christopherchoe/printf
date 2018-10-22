#include "holberton.h"

/**
  * print_char - adds the single character to buffer
  * @input: argument array that is passed
  * @buf: buffer to copy char to
  * @n: index of buffer to copy to
  * Return: 1
  */
int print_char(va_list input, char *buf, int n)
{
	char ch;

	ch = va_arg(input, int);

	*(buf + n) = ch;

	return (1);
}

/**
  * print_string - prints the string
  * @input: argument array that is passed
  * @buf: buffer to copy to
  * @n: index to start copying to buffer
  * Return: number of characters copied
  */
int print_string(va_list input, char *buf, int n)
{
	char *str;
	char temp[] = "(null)";
	int i, num_copied;

	num_copied = 0;
	str = va_arg(input, char *);
	if (str == NULL)
	{
		for (i = 0; temp[i] != '\0'; i++)
			*(buf + i) = temp[i];
		*(buf + i) = temp[i];
		str = temp;
	}
	i = _strlen(str);
	num_copied = buffer_copy(buf, str, n);

	return (num_copied);
}

/**
  * print_decimal - print decimal integer
  * @input: argument array that is passed
  * @buf: buffer to copy to
  * @n: index to start copying to buffer
  * Return: number of digits copied
  */
int print_decimal(va_list input, char *buf, int n)
{
	char *c;
	int i, temp, num_copied;

	num_copied = 0;
	temp = va_arg(input, int);
	if (!temp)
		temp = 0;
	i = count_digits(temp);
	if (temp < 0)
		i++;
	c = _itoa(temp);
	num_copied = buffer_copy(buf, c, n);

	if (c != NULL)
		free(c);

	return (num_copied);
}

/**
  * print_single_char - prints single char to the output
  * @str: pointer input
  * @buf: buffer to copy to
  * @n: index to start buffer copy
  * Return: 1 because we only copy one single char
  */
int print_single_char(const char *str, char *buf, int n)
{
	char temp;

	temp = *str;
	*(buf + n) = temp;

	return (1);
}

