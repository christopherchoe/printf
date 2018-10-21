#include "holberton.h"

/**
  * _strlen - return length of a string
  * @s: char pointer for string to measure length
  * Return: length of string, n
  */
int _strlen(char *s)
{
	int n, i;

	for (i = 0; *(s + i) != '\0'; i++)
		n++;

	return (n);
}

/**
  * _itoa - converts an integer to a string
  * @n: integer to convert
  * Return: converted string
  */
char *_itoa(int n)
{
	int i, d;
	char *s;

	d = count_digits(n);
	if (n < 0)
		d++;

	s = malloc(sizeof(char) * d);
	if (s == NULL)
		return (NULL);

	d--;

	while (n != 0)
	{
		*(s + d) = n % 10 + '0';
		n = n / 10;
		d--;
	}

	if (d != 0)
	{
		d--;
		*(s + d) = '-';
	}

	return (s);
}

/**
  * count_digits - counts the number of digits in a given argument
  * @n: numeric argument to count digits of
  * Return: number of digits
  */
int count_digits(long int n)
{
	int i;

	do {
		n /= 10;
		i++;
	} while (n != 0);

	return (i);
}

