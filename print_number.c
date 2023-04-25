#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @k: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int k)
{
	return (k >= '0' && k <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int d = 0;

	while (*s++)
		d++;
	return (d);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *myparams)
{
	unsigned int d = _strlen(str);
	int neg = (!myparams->unsign && *str == '-');

	if (!myparams->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		d--;
	}
	if (myparams->precision != UINT_MAX)
		while (d++ < myparams->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!myparams->minus_flag)
		return (print_number_right_shift(str, myparams));
	else
		return (print_number_left_shift(str, myparams));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *myparams)
{
	unsigned int x = 0, neg, neg2, d = _strlen(str);
	char pad_char = ' ';

	if (myparams->zero_flag && !myparams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!myparams->unsign && *str == '-');
	if (neg && d < myparams->width && pad_char == '0' && !myparams->minus_flag)
		str++;
	else
		neg = 0;
	if ((myparams->plus_flag && !neg2) ||
		(!myparams->plus_flag && myparams->space_flag && !neg2))
		d++;
	if (neg && pad_char == '0')
		x += _putchar('-');
	if (myparams->plus_flag && !neg2 && pad_char == '0' && !myparams->unsign)
		x += _putchar('+');
	else if (!myparams->plus_flag && myparams->space_flag && !neg2 &&
		!myparams->unsign && myparams->zero_flag)
		x += _putchar(' ');
	while (d++ < myparams->width)
		x += _putchar(pad_char);
	if (neg && pad_char == ' ')
		x += _putchar('-');
	if (myparams->plus_flag && !neg2 && pad_char == ' ' && !myparams->unsign)
		x += _putchar('+');
	else if (!myparams->plus_flag && myparams->space_flag && !neg2 &&
		!myparams->unsign && !myparams->zero_flag)
		x += _putchar(' ');
	x += _puts(str);
	return (x);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @myparams: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *myparams)
{
	unsigned int z = 0, neg, neg2, d = _strlen(str);
	char pad_char = ' ';

	if (myparams->zero_flag && !myparams->minus_flag)
		pad_char = '0';
	neg = neg2 = (!myparams->unsign && *str == '-');
	if (neg && d < myparams->width && pad_char == '0' && !myparams->minus_flag)
		str++;
	else
		neg = 0;

	if (myparams->plus_flag && !neg2 && !myparams->unsign)
		z += _putchar('+'), d++;
	else if (myparams->space_flag && !neg2 && !myparams->unsign)
		z += _putchar(' '), d++;
	z += _puts(str);
	while (d++ < myparams->width)
		z += _putchar(pad_char);
	return (z);
}
