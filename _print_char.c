#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlin.h>

/**
 * _print_char - prints characters
 * @len: length of what preceds
 * @p: pointer to char
 * Return: new length after printing
 */

int _print_char(int len, const char *p)
{
	write(1, p, 1);
	len++;
	return (len);
}
