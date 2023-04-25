#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @initiate: starting address
 * @stop: stopping address
 * @skip: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *initiate, char *stop, char *skip)
{
	int sum = 0;

	while (initiate <= stop)
	{
		if (initiate != skip)
			sum += _putchar(*initiate);
		initiate++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @var: string
 * @myparams: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list var, params_t *myparams)
{
	int l, total = 0;
	char *str = va_arg(var, char *);
	(void)myparams;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; l--, str--)
			total += _putchar(*str);
	}
	return (total);
}

/**
 * print_rot13 - prints string in rot13
 * @var: string
 * @myparams: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list var, params_t *myparams)
{
	int d, index;
	int sum = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(var, char *);
	(void)myparams;

	d = 0;
	index = 0;
	while (a[d])
	{
		if ((a[d] >= 'A' && a[d] <= 'Z')
		    || (a[d] >= 'a' && a[d] <= 'z'))
		{
			index = a[d] - 65;
			sum += _putchar(arr[index]);
		}
		else
			sum += _putchar(a[d]);
		d++;
	}
	return (sum);
}
