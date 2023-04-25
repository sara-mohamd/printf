#include "Main.h"

/**
 * printf_pointer - prints an hexgecimal number.
 * @nano: arguments.
 * Return: counter.
 */
int printf_pointer(va_list nano)
{
	void *p;
	char *n = "(nil)";
	long int o;
	int b;
	int v;

	p = va_arg(nano, void*);
	if (p == NULL)
	{
		for (v = 0; n[v] != '\0'; v++)
		{
			_putchar(n[v]);
		}
		return (v);
	}

	o = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = printf_hex_aux(o);
	return (b + 2);
}
