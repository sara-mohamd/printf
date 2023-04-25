#include "Main.h"
/**
 * printf_exclusive_string - print exclusuives string.
 * @nano: argumen t.
 * Return: the length of the string.
 */

int printf_exclusive_string(va_list nano)
{
	char *n;
	int v, pin = 0;
	int cost;

	n = va_arg(nano, char *);
	if (n == NULL)
		n = "(null)";
	for (v = 0; n[v] != '\0'; v++)
	{
		if (n[v] < 32 || n[v] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			pin = pin + 2;
			cost = n[v];
			if (cost < 16)
			{
				_putchar('0');
				pin++;
			}
			pin = pin + printf_HEX_aux(cost);
		}
		else
		{
			_putchar(n[v]);
			pin++;
		}
	}
	return (pin);
}
