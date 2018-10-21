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
	char *buf;
	char temp[] = "(null)";
	int i, flag;

	flag = 0;
	buf = va_arg(input, char *);
	if (buf == NULL)
	{
		buf = malloc(sizeof(char) * 7);
		if (buf == NULL)
			return (0);
		for (i = 0; temp[i] != '\0'; i++)
			*(buf + i) = temp[i];
		*(buf + i) = temp[i];
		flag = 1;
	}
	i = _strlen(buf);
	if (write(1, buf, sizeof(char) * i) == -1)
		return (0);

	if (flag != 0)
		free(buf);

	return (i);
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
	if (!temp)
		temp = 0;
	i = count_digits(temp);
	if (temp < 0)
		i++;
	buf = _itoa(temp);
	write(1, buf, sizeof(char) * i);

	free(buf);

	return (i);
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
