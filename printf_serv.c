#include "Main.h"

/**
 * printf_srev - function that prints a str in reverse
 * @var: type struct va_arg where is allocated printf arguments
 *
 * Return: the string
 */
int printf_srev(va_list var)
{

	char n = va_arg(var, char);
	int v;
	int j = 0;

	if (n == NULL)
		n = "(null)";
	while (n[j] != '\0')
		j++;
	for (v = j - 1; v >= 0; v--)
		_putchar(n[v]);
	return (j);
}
