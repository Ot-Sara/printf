#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _convert_ui_b- prints the unsigned int argument is converted to binary
 * @n: integer to convert
 * @len: length of what preceds
 *
 * Return: new length after printing
 */
int _convert_ui_b(int len, int n)
{
	int *p;
	char b;
	int i = 0, j = 0, nbr, ov = 1;
	unsigned int n1;

	if (n == 0)
	{	b = '0';
		write(1, &b, 1);
		len++;
		return (len); }
	if (n < 0)
		n1 = -n;
	else
		n1 = n;
	nbr = n1;
	while (n1 > 0)
	{	n1 = n1 / 2;
		i++; }
	p = malloc(sizeof(int) * i);
	while (nbr > 0)
	{	p[j] = nbr % 2;
		nbr = nbr / 2;
		if (n < 0)
		{	if ((p[j] == 0) && (ov == 0))
			{	p[j] = 1;
				ov = 0; }
			else if ((p[j] == 0) && (ov == 1))
			{	p[j] = 0;
				ov = 1; }
			else if ((p[j] == 1) && (ov == 0))
			{	p[j] = 0;
				ov = 0; }
			else
			{	p[j] = 1;
				ov = 0; } }
		j++; }
	j--;
	while (j >= 0)
	{	b = p[j] + '0';
		write(1, &b, 1);
		len++;
		j--; }
	free(p);
	return (len); }
/**
 * _printf-prints
 * @format: const pointer to char
 * ...: arguments
 *
 * Return: Integer
 */
int _printf(const char *format, ...)
{	int n, len = 0;
	char c, *p;
	va_list ap;

	if (format == NULL || *format == '\0')
		return (-1);
	va_start(ap, format);
	while (*format)
	{	if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{	n = va_arg(ap, int);
			if (n >= 0)
				len = _print_positif_int(len, n);
			else
				len = _print_negatif_int(len, n);
			format++; }
		else if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && (*(format + 2) != 's' &&
		*(format + 2) != 'c' && *(format + 2) != 'd' && *(format + 2) != 'i' &&
		*(format + 2) != 'b'))
		{	len = _print_char(len, format);
			format++; }
		else if (*format == '%' && *(format + 1) == 'c')
		{	c = va_arg(ap, int);
			len = _print_char(len, &c);
			format++; }
		else if (*format == '%' && *(format + 1) == 's')
		{	p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
				len = _print_string(len, p);
			format++; }
		else if (*format == '%' && *(format + 1) == 'b')
		{	n = va_arg(ap, int);
			len = _convert_ui_b(len, n);
			format++; }

		else if ((*format == 'c' || *format == 's' || *format == '%' ||
		*format == 'd' || *format == 'i' || *format == 'b') && *(format - 1) == '%')
			format++;
		else
		{	len = _print_char(len, format);
			format++; } }
	va_end(ap);
	return (len); }
