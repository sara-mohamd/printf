#include "Main.h"
/**
 * printf_rot13 - printf str to ROT13 place into buffer
 * @var: type struct va_arg where is allocated printf arguments
 * Return: counter
 *
 */
int printf_rot13(va_list var)
{
	int v, j, sum = 0;
	int K = 0;
	char n = va_arg(var, char);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (n == NULL)
		n = "(null)";
	for (v = 0; n[v]; v++)
	{
		K = 0;
		for (j = 0; alpha[j] && !K; j++)
		{
			if (n[v] == alpha[j])
			{
				_putchar(beta[j]);
				sum++;
				K = 1;
			}
		}
		if (!K)
		{
			_putchar(n[v]);
			sum++;
		}
	}
	return (sum);
}
