#include "Main.h"

/**
 * _putchar - writes the character o to stdout
 * @o: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char o)
{
	return (write(1, &o, 1));
}
