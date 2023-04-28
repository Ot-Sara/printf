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
	int *p;
	char b;
	int i = 0, j = 0;
	long int nbr;

	if (n == 0)
	{
		b = '0';
		write(1, &b, 1);
		len++;
		return (len); }
	nbr = n;
	while (n > 0)
	{
		n = n / 2;
		i++; }
	p = malloc(sizeof(int) * i);
	if (p == NULL)
		return (len);
	while (nbr > 0)
	{
		p[j] = nbr % 2;
		nbr = nbr / 2;
		j++; }
	j--;
	while (j >= 0)
	{
		b = p[j] + '0';
		write(1, &b, 1);
		len++;
		j--; }
	free(p);
	p = NULL;
	return (len); }
