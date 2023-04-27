#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< HEAD
/**
 * _print_negatif_int- prints negatif integer
 * @len: length of what preceds
 * @n: Integer to print
 *
 * Return: new length after printing
 */
int _print_negatif_int(int len, int n)
{
	int nbr, i = 1;
	char c;

	c = '-';
	write(1, &c, 1);
	len++;
	nbr = n;
	if (nbr > -10)
	{	c = -nbr + '0';
		write(1, &c, 1);
		len++;
		return (len); }
	while (nbr / 10)
	{
		while (nbr / 10)
		{	nbr = nbr / 10;
			i = i * 10; }
		c = -nbr + '0';
		write(1, &c, 1);
		len++;
		nbr = n % i;
		while (-nbr < (i / 10))
		{	i = i / 10;
			c = '0';
			write(1, &c, 1);
			len++;
			nbr = nbr % i; }
		i = 1; }
	if (nbr != 0)
	{	c = (-(nbr % 10)) + '0';
		write(1, &c, 1);
		len++; }
	return (len);
}
/**
 * _print_positif_int- prints positif integer
 * @len: length of what preceds
 * @n: Integer to print
 *
 * Return: new length after printing
 */
int _print_positif_int(int len, int n)
{
=======

/**
 * _print_int - prints integer
 * @len: length of what preceds
 * @n: integer to print
 * Return: new length after printing string
 */

int _print_int(int len, int n)
{
	unsigned int n1 = n;
>>>>>>> 64ced2357c9177ec8e58a7e07dbbf0be240a11b2
	int nbr, i = 1;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		len++;
<<<<<<< HEAD
	}
	nbr = n;
	if (nbr < 10)
	{	c = nbr + '0';
		write(1, &c, 1);
		len++;
		return (len); }
	while (nbr >= 10)
	{
		while (nbr >= 10)
		{	nbr = nbr / 10;
			i = i * 10; }
		c = nbr + '0';
		write(1, &c, 1);
		len++;
		nbr = n % i;
		while (nbr < (i / 10))
		{	i = i / 10;
			c = '0';
			write(1, &c, 1);
			len++;
			nbr = nbr % i; }
		i = 1; }
	if (nbr != 0)
	{	c = (nbr % 10) + '0';
		write(1, &c, 1);
		len++; }
=======
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
>>>>>>> 64ced2357c9177ec8e58a7e07dbbf0be240a11b2
	return (len);
}
