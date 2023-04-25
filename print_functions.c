#include "main.h"

/**
 * print_char - prints character
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list var, params_t *myparams)
{
	char pad_char = ' ';
	unsigned int pad = 1, total = 0, ch = va_arg(var, int);

	if (myparams->minus_flag)
		total += _putchar(ch);
	while (pad++ < myparams->width)
		total += _putchar(pad_char);
	if (!myparams->minus_flag)
		total += _putchar(ch);
	return (total);
}

/**
 * print_int - prints integer
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list var, params_t *myparams)
{
	long lo;

	if (myparams->l_modifier)
		lo = va_arg(var, long);
	else if (myparams->h_modifier)
		lo = (short int)va_arg(var, int);
	else
		lo = (int)va_arg(var, int);
	return (print_number(convert(lo, 10, 0, myparams), myparams));
}

/**
 * print_string - prints string
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list var, params_t *myparams)
{
	char *str = va_arg(var, char *), pad_char = ' ';
	unsigned int pad = 0, total = 0, d = 0, x;

	(void)myparams;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	x = pad = _strlen(str);
	if (myparams->precision < pad)
		x = pad = myparams->precision;

	if (myparams->minus_flag)
	{
		if (myparams->precision != UINT_MAX)
			for (d = 0; d < pad; d++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	while (x++ < myparams->width)
		total += _putchar(pad_char);
	if (!myparams->minus_flag)
	{
		if (myparams->precision != UINT_MAX)
			for (d = 0; d < pad; d++)
				total += _putchar(*str++);
		else
			total += _puts(str);
	}
	return (total);
}

/**
 * print_percent - prints string
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list var, params_t *myparams)
{
	(void)var;
	(void)myparams;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list var, params_t *myparams)
{
	char *str = va_arg(var, char *);
	char *hex;
	int total = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			hex = convert(*str, 16, 0, myparams);
			if (!hex[1])
				total += _putchar('0');
			total += _puts(hex);
		}
		else
		{
			total += _putchar(*str);
		}
	}
	return (total);
}
