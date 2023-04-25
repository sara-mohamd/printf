#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @fs: the format string
 * @myparams: the parameters struct
 * @var: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *fs, params_t *myparams, va_list var)
{
	int d = 0;

	if (*fs != '.')
		return (fs);
	fs++;
	if (fs == '')
	{
		d = va_arg(var, int);
		fs++;
	}
	else
	{
		while (_isdigit(*fs))
			d = d * 10 + (*fs++ - '0');
	}
	myparams->precision = d;
	return (fs);
}
