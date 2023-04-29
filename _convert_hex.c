#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 *  _convert_hex - converts in hexadecimal and prints
 * @n: integer to convert
 * @len: length of what preceds
 * Return: new length after printing
 */
int _convert_hex(int len, long int n)
{
	int *p;
	char b;
	int i = 0, j = 0;
	long int nbr;

	if (n == 0)
	{
		b= '0';
		write(1, &b, 1);
		len++;
		return (len); }
	nbr = n;
	while (n > 0)
	{
		n = n / 16;
		i++; }
	p = malloc(sizeof(int) * i);
	if (p == NULL)
		return (len);
	while (nbr > 0)
	{
		p[j] = nbr % 16;
		nbr = nbr / 16;
		j++; }
	j--;
	while (j >=0)
	{
		if (p[j] <= 9)
			b = p[j] + '0';
		else if (p[j] == 10)
			b = 'a';
		else if (p[j] == 11)
			b = 'b';
		else if (p[j] == 12)
			b = 'c';
		else if (p[j] == 13)
			b = 'd';
		else if (p[j] == 14)
			b = 'e';
		else
			b = 'f';
		write(1, &b, 1);
		len++;
		j--; }
	free(p);
	p = NULL;
	return(len); }
	
