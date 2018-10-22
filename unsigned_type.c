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

/**
  * print_unsigned - prints unsigned int
  * @input: input from variable argument list
  * Return: number of characters printed
  *
  * int print_unsigned(va_list input)
  * {
  *	return (0);
  */

/**
  * print_hex_cap - prints an unsigned hexadecimal number
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_hex_cap(va_list input)
{
	unsigned int copy_input;
	unsigned int result;
	int index, x;
	char *hex_print = "0123456789ABCDEF";
	int base = 16;
	int multiple, num_copied;
	/* char *input_to_buf; */

	copy_input = va_arg(input, unsigned int);
	x = 0;
	if (copy_input > base)
	{
		result = copy_input - power(base, x);
		while (result >= power(base, x + 1) - power(base, x))
		{
			x++;
			result = copy_input - power(base, x);
		}
	}
	result = copy_input;
	num_copied = 0;
	/*
	 * input_to_buf = malloc(sizeof(char) * 2);
	 * if (input_to_buf == NULL)
	 *	return (0);
	 * input_to_buf[1] = '\0';
	 */
	for (index = 0; index <= x; index++)
	{
		multiple = 1;
		while (result >= multiple * power(base, x - index))
		{
			multiple++;
		}
	/*	input_to_buf[0] = *(hex_values + (--multiple)); */
	/*	num_copied += buffer_copy(buf, input_to_buf, n + index); */
		write(1, (hex_print + (--multiple)), sizeof(char));
		result -= multiple * power(base, x - index);
	}
	return (x + 1);
}

/**
  * print_hex_low - prints an unsigned hexadecimal number
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_hex_low(va_list input)
{
	unsigned int copy_input;
	unsigned int result;
	int index, x;
	char *hex_print = "0123456789abcdef";
	int base = 16;
	int multiple, num_copied;
	/*char *input_to_buf;*/

	copy_input = va_arg(input, unsigned int);
	x = 0;
	if (copy_input > base)
	{
		result = copy_input - power(base, x);
		while (result >= power(base, x + 1) - power(base, x))
		{
			x++;
			result = copy_input - power(base, x);
		}
	}
	result = copy_input;
	num_copied = 0;
	/*
	 * input_to_buf = malloc(sizeof(char) * 2);
	 * if (input_to_buf == NULL)
	 *	return (0);
	 * input_to_buf[1] = '\0';
	 */
	for (index = 0; index <= x; index++)
	{
		multiple = 1;
		while (result >= multiple * power(base, x - index))
		{
			multiple++;
		}
	/*	input_to_buf[0] = *(hex_values + (--multiple)); */
	/*	num_copied += buffer_copy(buf, input_to_buf, n + index); */
		write(1, (hex_print + (--multiple)), sizeof(char));
		result -= multiple * power(base, x - index);
	}
	return (x + 1);
}

/**
  * print_octal - prints an unsigned octal number
  * @input: input from variable argument list
  * Return: number of characters printed
  */
int print_octal(va_list input)
{
	unsigned int copy_input;
	unsigned int result;
	int index, x;
	char *octal_values = "012345678";
	int base = 8;
	int multiple, num_copied;
	/*char *input_to_buf;*/

	copy_input = va_arg(input, unsigned int);
	x = 0;
	if (copy_input > base)
	{
		result = copy_input - power(base, x);
		while (result >= power(base, x + 1) - power(base, x))
		{
			x++;
			result = copy_input - power(base, x);
		}
	}
	result = copy_input;
	num_copied = 0;
	/*
	 * input_to_buf = malloc(sizeof(char) * 2);
	 * if (input_to_buf == NULL)
	 *	return (0);
	 * input_to_buf[1] = '\0';
	 */
	for (index = 0; index <= x; index++)
	{
		multiple = 1;
		while (result >= multiple * power(base, x - index))
		{
			multiple++;
		}
	/*	input_to_buf[0] = *(hex_values + (--multiple)); */
	/*	num_copied += buffer_copy(buf, input_to_buf, n + index); */
		write(1, (octal_values + (--multiple)), sizeof(char));
		result -= multiple * power(base, x - index);
	}
	return (x + 1);
}
