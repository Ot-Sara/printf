#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _print_char- prints charcacter
 * @len: length of what preceds
 * @p: pointer to char
 *
 * Return: new length after printing
 */
int _print_char(int len, const char *p)
{
	write(1, p, 1);
	len++;
	return (len);
}
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
			if (n >= 0)
				len = _print_positif_int(len, n);
			else
				len = _print_negatif_int(len, n);
			format++; }
		else if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && (*(format + 2) !=
		's' && *(format + 2) != 'c' && *(format + 2) != 'd' && *(format + 2) != 'i'))
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
		else if ((*format == 'c' || *format == 's' || *format == '%' ||
			*format == 'd' || *format == 'i') && *(format - 1) == '%')
			format++;
		else
		{	len = _print_char(len, format);
			format++; }
	}
	va_end(ap);
	return (len); }
