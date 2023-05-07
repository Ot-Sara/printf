#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _print_negatif_int- prints negatif integer
 * @len: length of what preceds
 * @n: Integer to print
 *
 * Return: new length after printing
 */
int _print_negatif_int(int len, long int n)
{
	long int i = 1;
	long int nbr = n;
	char c;

	c = '-';
	write(1, &c, 1);
	len++;
	if (n > -10)
	{
		c = -n + '0';
		write(1, &c, 1);
		len++;
		return (len);
	}
	while (n / 10)
	{	n = n / 10;
		i = i * 10;
	}
	while(i >= 10)
	{
		c = -(nbr / i) + '0';
		write(1, &c, 1);
		len++;
		nbr = nbr % i;
		i = i / 10;
	}
	c = -nbr + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
/**
 * _print_positif_int- prints positif integer
 * @len: length of what preceds
 * @n: Integer to print
 *
 * Return: new length after printing
 */
int _print_positif_int(int len, long int n)
{
	long int i = 1;
	long int nbr = n;
	char c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		len++;
		return (len);
	}
	while (n / 10)
	{	n = n / 10;
		i = i * 10;
	}
	while(i >= 10)
	{
		c = (nbr / i) + '0';
		write(1, &c, 1);
		len++;
		nbr = nbr % i;
		i = i / 10;
	}
	c = nbr + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
