#include "holberton.h"

/**
  * string_malloc - mallocs space for the string
  * @str: string to malloc space for
  * Return: newly copied string
  */
char *string_malloc(char *str)
{
	char temp[] = "(null)";
	char *rtn;
	int i, k;

	if (str == NULL)
	{
		rtn = malloc(sizeof(char) * 7);
		if (rtn == NULL)
			return (NULL);
		for (i = 0; temp[i] != '\0'; i++)
			*(rtn + i) = temp[i];
		*(rtn + i) = temp[i];
		i--;
	}
	else
	{
		i = _strlen(str);
		rtn = malloc(sizeof(char) * (i + 1));
		if (rtn == NULL)
			return (0);
		for (k = 0; k < i; k++)
			*(rtn + k) = *(str + k);
		*(rtn + k) = *(str + k);
	}

	return (rtn);
}

/**
  * unprint_hex - converts unprintable character to hexadecimal
  * @n: ascii code of unprintable character
  * Return: 2 character representation of code
  */
char *unprint_hex(int n)
{
	unsigned long int index, multiple, x = 2;
	unsigned long int num, base = 16;
	char *hex_values = "0123456789ABCDEF";
	char *rtn;

	num = (unsigned long int)n;

	rtn = malloc(sizeof(char) * 3);
	if (rtn == NULL)
		return (NULL);

	for (index = 0; index < 2; index++)
	{
		for (multiple = 0; multiple <= base; multiple++)
		{
			if (multiple * power(base, x - index - 1) > num)
			{
				*(rtn + index) = *(hex_values + --multiple);
				break;
			}
		}
		num -= multiple * power(base, x - index - 1);
	}
	*(rtn + index) = '\0';
	return (rtn);
}

/**
  * unprint_strlen - finds string length for unprintable conversion
  * @str: string to find new length for
  * Return: length of new string
  */
int unprint_strlen(char *str)
{
	int i, k = 0;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) > 0 && *(str + i) < 32)
			k += 4;
		else if ((unsigned char)*(str + i) >= 127)
			k += 4;
		else
			k++;
	}

	return (k);
}

