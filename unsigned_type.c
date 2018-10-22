#include "holberton.h"

/**
  * print_binary - prints binary version of unsigned int
  * @input: input from argument list
  * Return: number of characters printed
  */
int print_binary(va_list input)
{
	unsigned int copy_input;
	unsigned int result;
	int index, power_x;
	char *value_zero = "0";
	char *value_one = "1";

	copy_input = va_arg(input, unsigned int);
	power_x = 0;
	if (copy_input != 0)
	{
		result = copy_input - power(2, power_x);
		while (result >= power(2, power_x + 1) - power(2, power_x))
		{
			power_x++;
			result = copy_input - power(2, power_x);
		}
	}
	result = copy_input;
	for (index = 0; index <= power_x; index++)
	{
		if (result >= power(2, power_x - index))
		{
			write(1, value_one, sizeof(char));
			result -= power(2, power_x - index);
		}
		else
			write(1, value_zero, sizeof(char));
	}
	return (power_x + 1);
}
