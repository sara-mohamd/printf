#include "Main.h"

/**
 * printf_oct - prints an octal number.
 * @nano: arguments.
 * Return: sum.
 */
int printf_oct(va_list nano)
{
	int v;
	int *matrix;
	int sum = 0;
	unsigned int number = va_arg(nano, unsigned int);
	unsigned int temp = number;

	while (number / 8 != 0)
	{
		number /= 8;
		sum++;
	}
	sum++;
	matrix = malloc(sum * sizeof(int));

	for (v = 0; v < sum; v++)
	{
		matrix[v] = temp % 8;
		temp /= 8;
	}
	for (v = sum - 1; v >= 0; v--)
	{
		_putchar(matrix[v] + '0');
	}
	free(matrix);
	return (sum);
}
