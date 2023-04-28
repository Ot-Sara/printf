#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _convert_hex - converts in hexadecimal and prints
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
		b = '0';
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
	while (j >= 0)
	{
		b = p[j] + '0';
		write(1, &b, 1);
		len++;
		j--; }
	free(p);
	p = NULL;
	return (len); }

/**
 * _convert_oct - converts in octal and prints
 * @n: integer to convert
 * @len: length of what preceds
 * Return: new length after printing
 */
int _convert_oct(int len, long int n)
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
		n = n / 8;
		i++; }
	p = malloc(sizeof(int) * i);
	if (p == NULL)
		return (len);
	while (nbr > 0)
	{
		p[j] = nbr % 8;
		nbr = nbr / 8;
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
	long int ui;

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
		if (*format == '%' && *(format + 1) == 'u')
		{	ui = va_arg(ap, long int);
			len = _print_positif_int(len, ui);
                        format++; }
		else if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && (*(format + 2) != 's' &&
		*(format + 2) != 'c' && *(format + 2) != 'd' && *(format + 2) != 'i' &&
		*(format + 2) != 'b' && *(format + 2) != 'u' && *(format + 2) != 'o' && *(format + 2) != 'x'))
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
		{	
			ui = va_arg(ap, long int);
			len = _convert_ui_b(len, ui);
			format++; }
		else if (*format == '%' && *(format + 1) == 'o')
		{	
			ui = va_arg(ap, long int);
			len = _convert_oct(len, ui);
			format++; }
		else if (*format == '%' && *(format + 1) == 'x')
		{	
			ui = va_arg(ap, long int);
			len = _convert_hex(len, ui);
			format++; }

		else if ((*format == 'c' || *format == 's' || *format == '%' ||
		*format == 'd' || *format == 'i' || *format == 'b' || *format == 'u' || *format == 'o' || *format == 'x') && *(format - 1) == '%')
			format++;
		else
		{	len = _print_char(len, format);
			format++; } }
	va_end(ap);
	return (len); }
