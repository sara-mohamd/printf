#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @var: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list var, params_t *myparams)
{
	unsigned long l;
	int j = 0;
	char *str;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(var, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(var, unsigned int);
	else
		l = (unsigned int)va_arg(var, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, myparams);
	if (myparams->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	myparams->unsign = 1;
	return (j += print_number(str, myparams));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @var: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list var, params_t *myparams)
{
	unsigned long l;
	int j = 0;
	char *str;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(var, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(var, unsigned int);
	else
		l = (unsigned int)va_arg(var, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, myparams);
	if (myparams->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	myparams->unsign = 1;
	return (j += print_number(str, myparams));
}
/**
 * print_binary - prints unsigned binary number
 * @var: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list var, params_t *myparams)
{
	unsigned int z = va_arg(var, unsigned int);
	char *str = convert(z, 2, CONVERT_UNSIGNED, myparams);
	int j = 0;

	if (myparams->hashtag_flag && z)
		*--str = '0';
	myparams->unsign = 1;
	return (j += print_number(str, myparams));
}

/**
 * print_octal - prints unsigned octal numbers
 * @var: the argument pointer
 * @myparams: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list var, params_t *myparams)
{
	unsigned long l;
	char *str;
	int j = 0;

	if (myparams->l_modifier)
		l = (unsigned long)va_arg(var, unsigned long);
	else if (myparams->h_modifier)
		l = (unsigned short int)va_arg(var, unsigned int);
	else
		l = (unsigned int)va_arg(var, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, myparams);

	if (myparams->hashtag_flag && l)
		*--str = '0';
	myparams->unsign = 1;
	return (j += print_number(str, myparams));
}
