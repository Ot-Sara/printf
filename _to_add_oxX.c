#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _to_add_oxX - spaces to add to reach field width for octal,
 * hexadecimal and HEXADECIMAL
 * @fw: field width
 * @n: number to print in (octal, hexadecimal, HEXADECIMAL)
 * Return: number of spaces to print
 */

int _to_add_oxX(int fw, long int n)
{
	int i = 0;

	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 8;
		i++;
	}
	if (fw <= i)
		return (0);
	else
		return (fw - i);
}
