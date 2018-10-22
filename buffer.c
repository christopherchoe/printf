#include "holberton.h"

/**
  * buffer_init - free previous buffer and initializesagain
  * @buf: buffer to free if filled or initialize
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
  * Return: new index for buffer
  */
int buffer_copy(char *buf, char *to_copy, int n)
{
	while (*to_copy)
	{
		*(buf + n) = *to_copy++;
		n++;
		if (*(buf + n) == '\0')
		{
			buf = buffer_write(buf, 1023);
			n = 0;
		}
	}
	return (n);
}

/**
  * buffer_write - writes out buffer
  * @buf: buffer to write
  * @n: how many bytes to write
  * Return: newly initialized buffer
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

