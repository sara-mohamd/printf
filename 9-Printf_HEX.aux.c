#include "Main.h"

/**
 * printf_HEX_aux - prints an hexgecimal number.
 * @number: number to print.
 * Return: counter.
 */
int printf_HEX_aux(unsigned int number)
{
	int v;
	int *matrix;
	int sum = 0;
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
