#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _convert_ui_b - prints the unsigned int argument is converted to binary
 * @n: integer to convert
 * @len: length of what preceds
 * Return: new length after printing
 */
int _convert_ui_b(int len, long int n)
{
	long int p = 1;
	char c;

	if (n == 0 || n == 1)
	{
		c = n + '0';
		write(1, &c, 1);
		len++;
		return (len);
	}
	while (n >= p)
		p = p * 2;
	p = p / 2;
	while (p != 0 && n > 0)
	{	n = n - p;
		c = '1';
		write(1, &c, 1);
		len++;
		p = p / 2;
		while (p != 0 && n < p)
		{	c = '0';
			write(1, &c, 1);
			len++;
			p = p / 2;
		}
	}
	return (len);
}
