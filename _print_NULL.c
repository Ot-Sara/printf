#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_NULL - prints null
 * @len: length of what preceds
 * Return: new length after printing
 */

int _print_NULL(int len)
{
	char *c = "(null)";
	
	while (*c)
	{
		write(1, c, 1);
		c++;
	}
	len = len + 6;
	return (len);
}
