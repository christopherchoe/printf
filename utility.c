#include "holberton.h"

/**
  * _strlen - return length of a string
  * @s: char pointer for string to measure length
  * Return: length of string, n
  */
int _strlen(char *s)
{
	int n, i;

	for (i = 0; *(s + i) != '\0'; i++)
		n++;

	return (n);
}

/** 
  * _itoa - converts an integer to a string
  * @n: integer to convert
  * Return: converted string
  */
char *_itoa(int n)
{
	int i, digits;
	char *s;


	s = malloc(sizeof(char) * digits);
	if (s == NULL)
		return (NULL);
	return (s);
}

