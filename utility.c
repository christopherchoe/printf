#include "holberton.h"
/** _atoi - converts a string to an integer
  * @s: string to be converted
  * Return: converted integer value
  */
int _atoi(char *s)
{
	unsigned int value;
	int pos_neg;

	pos_neg = 1;
	while ((*s < '0' || *s > '9') && *s != '\0')
	{
		if (*s == '-')
			pos_neg *= -1;
		s++;
	}

	for (value = 0; *s != '\0' && *s >= '0' && *s <= '9'; s++)
	{
		value = value * 10 + (*s - '0');
	}
	return (value * pos_neg);
}


