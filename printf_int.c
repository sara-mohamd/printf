#include "Main.h"
/**
 * printf_int - prints integer
 * @var: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list var)
{
	int y = va_arg(var, int);
	int num, final = y % 10, digital, exp = 1;
	int  v = 1;

	y = y / 10;
	num = y;

	if (final < 0)
	{
		_putchar('-');
		num = -num;
		y = -y;
		final = -final;
		v++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = y;
		while (exp > 0)
		{
			digital = num / exp;
			_putchar(digital + '0');
			num = num - (digital * exp);
			exp = exp / 10;
			v++;
		}
	}
	_putchar(final + '0');

	return (v);
}

/**
 * printf_dec - prints decimal
 * @var: argument to print
 * Return: number of characters printed
 */

int printf_dec(va_list var)
{
	int y = va_arg(var, int);
	int number, final = y % 10, digital;
	int  v = 1;
	int exp = 1;

	y = y / 10;
	number = y;

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
			_putchar(digital + '0');
			number = number - (digital * exp);
			exp = exp / 10;
			v++;
		}
	}
	_putchar(final + '0');

	return (v);
}
