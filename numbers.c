#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @myparams: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *myparams)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long x = num;
	(void)myparams;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[x % base];
		x /= base;
	} while (x != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list var, params_t *myparams)
{
	unsigned long lo;

	if (myparams->l_modifier)
		lo = (unsigned long)va_arg(var, unsigned long);
	else if (myparams->h_modifier)
		lo = (unsigned short int)va_arg(var, unsigned int);
	else
		lo = (unsigned int)va_arg(var, unsigned int);
	myparams->unsign = 1;
	return (print_number(convert(lo, 10, CONVERT_UNSIGNED, myparams), myparams));
}

/**
 * print_address - prints address
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list var, params_t *myparams)
{
	unsigned long int i = va_arg(var, unsigned long int);
	char *str;

	if (!i)
		return (_puts("(nil)"));

	str = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, myparams);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, myparams));
}
