#include "Main.h"
/**
 * _strlen - Returns the lenght of a string.
 * @n: Type char pointer
 * Return: o.
 */
int _strlen(char *n)
{
	int o;

	for (o = 0; n[o] != 0; o++)
		;
	return (o);

}
/**
 * _strlenc - Strlen function but applied for constant char pointer n
 * @n: Type char pointer
 * Return: o
 */
int _strlenc(const char *n)
{
	int o;

	for (o = 0; n[o] != 0; o++)
		;
	return (o);
