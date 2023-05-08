#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _to_add_neg - spaces to add to reach field wisth for negative int
 * @fw: field width
 * @n: long int
 * Return: number of spaces that should be printed
 */

int _to_add_neg(int fw, long int n)
{
	long int nbr;
	int i = 1, d = 0;

	d++;
	nbr = n;
	if (nbr > 10)
		d++;
	while (nbr / 10)
	{
		while (nbr / 10)
		{
			nbr = nbr / 10;
			i = i * 10; }
		d++;
		nbr = n % i;
		while (-nbr < (i / 10))
		{
			i = i / 10;
			d++;
			nbr = nbr % i; }
		i = 1; }
	if (nbr != 0)
		d++;
	if (fw <= d)
		return (0);
	else
		return (fw - d);
}
