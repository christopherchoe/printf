#include "holberton.h"

/**
  * buffer_init - free previous buffer and initializes again
  * @buf: buffer to free if filled, then initialize
  * Return: pointer to buffer
  */
char *buffer_init(char *buf)
{
	unsigned int i;

	if (buf != NULL)
		free(buf);

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
		return (NULL);
	for (i = 0; i < (sizeof(char) * 1024); i++)
		*(buf + i) = 1;

	*(buf + 1023) = '\0';

	return (buf);
}

/**
  * buffer_copy - adds to buffer and writes if full, reinitializing
  * @buf: buffer to copy to
  * @to_copy: string to copy to buffer
  * @n: index to start copying to
  * Return: count of printed chars
  */
int buffer_copy(char *buf, char *to_copy, int n)
{
	int count = 0;

	if (to_copy == NULL)
		return (count);
	while (*to_copy)
	{
		if (*(buf + n) == '\0')
		{
			buf = buffer_write(buf, 1023);
			n = 0;
		}
		/* this was before the if prior*/
		*(buf + n) = *to_copy++;
		n++;
		count++;
	}
	/* add flag for buffer reset, to account the int return of printf*/
	return (count);
}

/**
  * buffer_write - writes out buffer
  * @buf: buffer to write
  * @n: how many bytes to write
  * Return: newly initialized or freed buffer based on overflow condition
  */
char *buffer_write(char *buf, int n)
{
	write(1, buf, n);
	if (n == 1023)
		buf = buffer_init(buf);
	else
		free(buf);
	return (buf);
}

/**
  * buffer_over - checks if overflowed return and creates new index
  * @n: count returned
  * Return: unaltered if below 1023, new index if above
  */
int buffer_over(int n)
{
	if (n < 1024)
		return (n);
	while (n > 1024)
		n = n - 1024;
	return (n);
}

