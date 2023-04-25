#include "Main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match w[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list var;
	int v = 0, g, pin = 0;

	va_start(var, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[v] != '\0')
	{
		g = 13;
		while (g >= 0)
		{
			if (w[g].ip[0] == format[v] && w[g].ip[1] == format[v + 1])
			{
				pin += w[g].f(var);
				v = v + 2;
				goto Here;
			}
			g--;
		}
		_putchar(format[v]);
		pin++;
		v++;
	}
	va_end(var);
	return (pin);
}
