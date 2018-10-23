#include "holberton.h"

/**
  * print_address - prints the address of the input
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_address(va_list input)
{
	void *storage;
	unsigned long int address, result, x, index;
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
	address = (unsigned long)storage;
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
