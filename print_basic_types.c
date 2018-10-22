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
	char *ch;

	ch = malloc(sizeof(char) * 2);
	if (ch == NULL)
		return (0);
	*ch = va_arg(input, int);
	*(ch + 1) = '\0';

	n = (buffer_copy(buf, ch, n));

	free(ch);
	return (n);
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
	int i, flag;

	flag = 0;
	str = va_arg(input, char *);
	if (str == NULL)
	{
		str = malloc(sizeof(char) * 7);
		if (buf == NULL)
			return (0);
		for (i = 0; temp[i] != '\0'; i++)
			*(buf + i) = temp[i];
		*(buf + i) = temp[i];
		flag = 1;
	}
	i = _strlen(str);
	n = buffer_copy(buf, str, n);

	if (flag != 0)
		free(str);

	return (n);
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
	int i, temp;

	temp = va_arg(input, int);
	if (!temp)
		temp = 0;
	i = count_digits(temp);
	if (temp < 0)
		i++;
	c = _itoa(temp);
	n = buffer_copy(buf, c, n);

	if (c != NULL)
		free(c);

	return (n);
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
	char *temp;

	temp = malloc(sizeof(char) * 2);
	if (temp == NULL)
		return (0);

	*temp = *str;
	*(temp + 1) = '\0';
	n = buffer_copy(buf, temp, n);

	if (temp != NULL)
		free(temp);
	return (n);
}

