#include "holberton.h"

/**
  * _strlen - return length of a string
  * @s: char pointer for string to measure length
  * Return: length of string, n
  */
int _strlen(char *s)
{
	int n, i;

	n = 0;
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
	int d;
	char *s;
	unsigned int n_copy;

	d = count_digits(n);
	if (n < 0)
	{
		d++;
		n_copy = n * -1;
	}
	else
		n_copy = n;
	s = malloc(sizeof(char) * (d + 1));
	if (s == NULL)
		return (NULL);

	*(s + d--) = '\0';

	do {
		*(s + d) = (unsigned char)(n_copy % 10 + '0');
		n_copy = n_copy / 10;
		d--;
	} while (n_copy != 0);
	if (d == 0 && n < 0)
	{
		*(s + d) = '-';
	}

	return (s);
}

/**
  * count_digits - counts number of digits
  * @n: numeric argument to count digits of
  * Return: number of digits
  */
int count_digits(int n)
{
	int i;

	i = 0;
	do {
		n /= 10;
		i++;
	} while (n != 0);

	return (i);
}

/**
  * power - calculates the power of two input values
  * @base: base
  * @raise: power to raise base to
  * Return: value of base raised to the power of raise
  */
unsigned int power(int base, int raise)
{
	unsigned int result;

	result = 1;
	while (raise-- > 0)
		result *= base;
	return (result);
}

