#include "holberton.h"

int print_address(va_list input)
{
	void *storage;
	unsigned long address;
	int num_printed;

	storage = va_arg(input, void *);
	address = (unsigned long)storage;
	num_printed = _printf("0x7ffe%x", address);
	return (num_printed);
}
