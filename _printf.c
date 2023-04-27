#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{	n = va_arg(ap, int);
			len = _print_int(len, n);
			format++; }
		else if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && (*(format + 2) !=
		's' && *(format + 2) != 'c' && *(format + 2) != 'd' && *(format + 2) != 'i'))
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
				len = _print_NULL(len);
			else
				len = _print_string(len, p);
			format++; }
		else if ((*format == 'c' || *format == 's' || *format == '%' ||
			*format == 'd' || *format == 'i') && *(format - 1) == '%')
			format++;
		else
		{	write(1, format, 1);
			len++;
			format++; } }
	va_end(ap);
	return (len); }
