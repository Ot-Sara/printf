#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_string - prints string
 * @len: length of what preceds
 * @p: string to print
 * Return: new length after printing string
 */

int _print_string(int len, char *p)
{
	while (*p)
	{
		write(1, p, 1);
		len++;
		p++;
	}
	return (len);
}
