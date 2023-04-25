#include "Main.h"
/**
 * printf_unsigned - prints integer
 * @var: argument to print
 * Return: number of characters printed
 */
int printf_unsigned(va_list var)
{
	unsigned int y = va_arg(var, unsigned int);
	int number, final = y % 10, digital, exp = 1;
	int  v = 1;

	y = y / 10;
	num = y;

	if (final < 0)
	{
		_putchar('-');
		number = -number;
		y = -y;
		final = -final;
		v++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			exp = exp * 10;
			number = number / 10;
		}
		number = y;
		while (exp > 0)
		{
			digital = number / exp;
			_putchar(digit + '0');
			number = number - (digital * exp);
			exp = exp / 10;
			v++;
		}
	}
	_putchar(final + '0');

	return (v);
}
