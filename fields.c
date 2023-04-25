#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @s: the format string
 * @myparams: the parameters struct
 * @var: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *s, params_t *myparams, va_list var)
{
int d = 0;

if (*s != '.')
return (s);
s++;
if (*s == '*')
{
d = va_arg(var, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
myparams->precision = d;
return (s);
}
