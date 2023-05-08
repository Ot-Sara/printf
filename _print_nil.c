#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _print_nil - prints (nil)
 * @len: length of what preceds
 * Return: new length after printing
 */

int _print_nil(int len)
{
	char c;

	c = '(';
	write(1, &c, 1);
	c = 'n';
	write(1, &c, 1);
	c = 'i';
	write(1, &c, 1);
	c = 'l';
	write(1, &c, 1);
	c = ')';
	write(1, &c, 1);
	len = len + 5;
	return (len);
}
