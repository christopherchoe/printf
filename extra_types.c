#include "holberton.h"

/**
  * print_hex - prints the hex values
  * @input: input address
  * @base: string that represents the base characters
  * Return: number of values printed
  */
int print_hex(unsigned long int input, char *base)
{
	unsigned long int output;
	int bytes;

	bytes = 0;
	if (input > 15)
		bytes += print_hex(input / 16, base);
	output = input % 16;
	bytes += write(1, base + output, 1);
	return (bytes);
}
/**
  * print_address - prints the address of the input
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_address(va_list input)
{
	void *storage;
	unsigned long int address;
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
	write(1, start, 2);
	return (2 + print_hex(address, hex_values));
}
