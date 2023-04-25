#include "Main.h"

/**
 * printf_bin - prints a binary number.
 * @nano: arguments.
 * Return: 1.
 */
int printf_bin(va_list nano)
{
	int flags = 0;
	int content = 0;
	int v, a = 1, b;
	unsigned int number = va_arg(nano, unsigned int);
	unsigned int p;

	for (v = 0; v < 32; v++)
	{
		p = ((a << (31 - v)) & number);
		if (p >> (31 - v))
			flags = 1;
		if (flags)
		{
			b = p >> (31 - v);
			_putchar(b + 48);
			content++;
		}
	}
	if (content == 0)
	{
		content++;
		_putchar('0');
	}
	return (content);
}
