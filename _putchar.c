#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *x = str;

	while (*str)
		_putchar(*str++);
	return (str - x);
}

/**
 * _putchar - writes the character o to stdout
 * @o: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int o)
{
	static int d;
	static char buf[OUTPUT_BUF_SIZE];

	if (o == BUF_FLUSH || d >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, d);
		d = 0;
	}
	if (o != BUF_FLUSH)
		buf[d++] = o;
	return (1);
}
