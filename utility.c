#include "holberton.h"

/** 
  * _atoi - converts a string to an integer
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

/**
  * write_buf - writes out a buffer and returns buffer length
  * @buf: pointer to a buffer with our string to write
  * Return: how many chars printed
  */
int write_buf(char *buf)
{
	int i;

	for (i = 0; *(buf + i) != '\0'; i++)
		;

	write(1, buf, sizeof(char) * i);
	
	return (i - 1);
}

