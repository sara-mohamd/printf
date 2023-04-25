#include "Main.h"

/**
 * printf_HEX - prints an hexgecimal number.
 * @nano: arguments.
 * Return: sum.
 */
int printf_HEX(va_list nano)
{
	int v;
	int *matrix;
	int sum = 0;
	unsigned int number = va_arg(nano, unsigned int);
	unsigned int temp = number;

	while (number / 16 != 0)
	{
		number /= 16;
		sum++;
	}
	sum++;
	matrix = malloc(sum * sizeof(int));

	for (v = 0; v < sum; v++)
	{
		matrix[v] = temp % 16;
		temp /= 16;
	}
	for (v = sum - 1; v >= 0; v--)
	{
		if (matrix[v] > 9)
			matrix[v] = matrix[v] + 7;
		_putchar(matrix[v] + '0');
	}
	free(matrix);
	return (sum);
}
