#include "main.h"

/**
 * _printf - prints anything specified
 * @format: the format which is strin
 *
 * Return: number of bytes that printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	va_list var;
	char *b, *star;
	params_t myparams = PARAMS_INIT;

	va_start(var, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_params(&myparams, var);
		if (*b != '%')
		{
			total += _putchar(*b);
			continue;
		}
		star = b;
		b++;
		while (get_flag(b, &myparams)) /* while char at b is flag char */
		{
			b++; /* next char */
		}
		b = get_width(b, &myparams, var);
		b = get_precision(b, &myparams, var);
		if (get_modifier(b, &myparams))
			b++;
		if (!get_specifier(b))
			total += print_from_to(start, b,
				myparams.l_modifier || myparams.h_modifier ? b - 1 : 0);
		else
			total += get_print_func(b, var, &myparams);
	}
	_putchar(BUF_FLUSH);
	va_end(var);
	return (total);
}
