#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list var, params_t *myparams)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int d = 0;

	while (specifiers[d].specifier)
	{
		if (*s == specifiers[d].specifier[0])
		{
			return (specifiers[d].f);
		}
		d++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @var: argument pointer
 * @myparams: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list var, params_t *myparams)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(var, myparams));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @s: the format string
 * @myparams: the parameters struct
 *
 * Return: if flag was valid
 */
int get_flag(char *fs, params_t *myparams)
{
	int d = 0;

	switch (*s)
	{
		case '+':
			d = myparams->plus_flag = 1;
			break;
		case ' ':
			d = myparams->space_flag = 1;
			break;
		case '#':
			d = myparams->hashtag_flag = 1;
			break;
		case '-':
			d = myparams->minus_flag = 1;
			break;
		case '0':
			d = myparams->zero_flag = 1;
			break;
	}
	return (d);
}

/**
 * get_modifier - finds the modifier func
 * @fs: the format string
 * @myparams: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *myparams)
{
	int d = 0;

	switch (*s)
	{
	case 'h':
		d = myparams->h_modifier = 1;
		break;
	case 'l':
		d = myparams->l_modifier = 1;
		break;
	}
	return (d);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @myparams: the parameters struct
 * @var: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *myparams, va_list var)
{
	int d = 0;

	if (s == '')
	{
		d = va_arg(var, int);
		s++;
	}
	else
	{
		while (_isdigit(*fs))
			d = d * 10 + (*s++ - '0');
	}
	myparams->width = d;
	return (s);
}
