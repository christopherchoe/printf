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
	s = malloc(sizeof(char) * d);
	if (s == NULL)
		return (NULL);

	d--;

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
  * _u_itoa - converts unsigned int to string
  * @n: number
  * Return: string to converted string
  */
char *_u_itoa(unsigned long int n)
{
	int num_digits, index;
	unsigned long int n_copy;
	char *storage;

	n_copy = n;
	num_digits = 0;
	/* count number of digits */
	do {
		n_copy /= 10;
		num_digits++;
	} while (n_copy != 0);
	storage = malloc(sizeof(char) * (num_digits + 1));
	if (storage == NULL)
		return (NULL);
	n_copy = n;
	/*
	 * for (index = 0; index < num_digits; index++)
	 * {
	 *	storage[index] = (n_copy / power(10, (num_digits - index - 1))) + '0';
	 *	n_copy %= power(10, num_digits - index - 1);
	 * }
	 * storage[index] = '\0';
	 */
	storage[num_digits] = '\0';
	for (index = (num_digits - 1); index >= 0; index--)
	{
		storage[index] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	return (storage);
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
unsigned long int power(unsigned long int base, unsigned long int raise)
{
	unsigned long int result;

	result = 1;
	while (raise-- != 0)
		result *= base;
	return (result);
}
