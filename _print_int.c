#include "main.c"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_int - prints integer
 * @len: length of what preceds
 * @n: integer to print
 * Return: new length after printing string
 */

int _print_int(int len, int n)
{
	unsigned int n1 = n;
	int nbr, i = 1;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		len++;
		n1 = -n1;
	}
	nbr = n1;
	while (nbr >= 10)
	{
		while (nbr >= 10)
		{
			nbr = nbr / 10;
			i = i * 10;
		}
		c = nbr + '0';
		write(1, &c, 1);
		len++;
		nbr = n1 % i;
		while (nbr < (i / 10))
		{
			i = i / 10;
			c = '0';
			write(1, &c, 1);
			len++;
			nbr = nbr % 10;
		}
		i = 1;
	}
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
