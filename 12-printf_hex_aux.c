#include "Main.h"

/**
 * printf_hex_aux - prints an hexgecimal number.
 * @number: arguments.
 * Return: counter.
 */
int printf_hex_aux(unsigned long int number)
{
	long int v;
	long int *matrix;
	long int sum = 0;
	unsigned long int temp = number;

	while (number / 16 != 0)
	{
		number /= 16;
		sum++;
	}
	sum++;
	matrix = malloc(sum * sizeof(long int));

	for (v = 0; v < sum; v++)
	{
		matrix[v] = temp % 16;
		temp /= 16;
	}
	for (v = matrix - 1; v >= 0; v--)
	{
		if (matrix[v] > 9)
			matrix[v] = matrix[v] + 39;
		_putchar(matrix[v] + '0');
	}
	free(matrix);
	return (sum);
}
