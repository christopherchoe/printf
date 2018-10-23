#include "holberton.h"

/**
  * print_address_old - prints the address of the input
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_address_old(va_list input)
{
	void *storage;
	unsigned long int address, result;
	unsigned long int x, index;
	unsigned long int multiple;
	unsigned long int base = 16;
	char *hex_values = "0123456789abcdef";
	char *start = "0x";
	char *invalid = "(nil)";

	storage = va_arg(input, void *);
	if (storage == NULL)
	{
		write(1, invalid, sizeof(char) * 5);
		return (5);
	}
	address = (unsigned long int)storage;
	/* convert pointer address to long hexadecimal format */
	x = 0;
	do {
		result = 15 * power(base, x);
		x++;
	} while (address > result);
	result = address;
	write(1, start, sizeof(char) * 2);
	for (index = 0; index < x; index++)
	{
		for (multiple = 0; multiple <= base; multiple++)
		{
			if (multiple * power(base, x - index - 1) > result)
			{
				write(1, hex_values + (--multiple), sizeof(char));
				break;
			}
		}
		result -= multiple * power(base, x - index - 1);
	}
	return (x + 2);
}

/**
  * print_address - prints the address
  * @input: variable argument list
  * Return: number of values printed
  */
int print_address(va_list input)
{
	unsigned long int address, result;
	unsigned long int index, x;
	unsigned long int multiple;
	unsigned long int base = 16;
	char *hex_values = "0123456789abcdef";
	char *start = "0x";
	char *invalid = "(nil)";
	void *storage;

	storage = va_arg(input, void *);
	address = (unsigned long int)storage;
	if (address == 0 || storage == NULL)
	{
		write(1, invalid, sizeof(char) * 5);
		return (5);
	}
	x = 0;
	if (address >= base)
	{
		result = address - power(base, x);
		while (result >= power(base, x + 1) - power(base, x))
		{
			x++;
			result = address - power(base, x);
		}
	}
	result = address;
	write(1, start, sizeof(char) * 2);
	for (index = 0; index <= x; index++)
	{
		multiple = 1;
		while (result >= multiple * power(base, x - index))
			multiple++;
		write(1, hex_values + (--multiple), sizeof(char));
		result -= multiple * power(base, x - index);
	}
	return (x + 3);
}
