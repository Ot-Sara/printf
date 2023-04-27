#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_string - prints string
 * @len: length of what preceds
 * @p: string to print
 * Return: new length after printing string
 */
int _print_string(int len, char *p)
{
	while (*p)
	{
		write(1, p, 1);
		len++;
		p++; }
	return (len);
}
/**
 * _print_int - prints integer
 * @len: length of what preceds
 * @n: integer to print
 * Return: new lentgh after printing integer
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
			nbr = nbr % i;
		}
		i = 1;
	}
	c = (nbr % 10) = '0';
	write(1, &c, 1);
	len++;
	return (len);
}
/**
 * _printf - prints characters
 * @format: const pointer to char
 * ...: arguments
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int n, len = 0;
	char c, *p;
	va_list ap;

	if (format == NULL || *format == '/0')
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{	n = va_arg(ap, int);
			len = _print_int(len, n);
			format++; }
		else if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && (*(format + 2) != 's'
					&& *(format + 2) != 'c' && *(format + 2) != 'd' && *(format + 2) != 'i'))
		{	write(1, format, 1);
			len++;
			format++; }
		else if (*format == '%' && *(format + 1) == 'c')
		{	c = va_arg(ap, int);
			write(1, &c, 1);
			len++;
			format++; }
		else if (*format == '%' && *(format + 1) == 's')
		{	p = va_arg(ap, char *);
			if (p == NULL)
			{	exit(2);
				return (0); }
			len = _print_string(len, p);
			format++; }
		else if ((*format == 'c' || *format == 's' || *format == '%' || *format ==
					'd' || *format == 'i') && *(format - 1) == '%')
			format++;
		else
		{	write(1, format, 1);
			len++;
			format++; } }
	return (len); }
