#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int len = 0, nbr;
	char c, *p;
	va_list ap;

	if (format == NULL || *format == '\0')
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format - 1) != '%' && *(format + 1) == '\0')
			return (-1);
		else if ((*format != 'c' && *format != 's' && *format != '%' &&
				*format != 'd' && *format != 'i') || ((*format == 'c'
				 || *format == 's' || *format == 'd' || *format == 'i') &&
				*(format - 1) != '%') || (*format == '%' && (*(format + 1) == '%'
				|| (*(format - 1) != '%' && *(format + 1) != 'c' && *(format + 1)
				!= 's' && *(format + 1) != 'd' && *(format + 1) != 'i'))))
		{	write(1, format, 1);
			len++; }
		else if ((*format == 'c') && *(format - 1) == '%')
		{
			c = va_arg(ap, int);
			write(1, &c, 1);
			len++; }
		else if (*format == 's' && *(format - 1) == '%')
		{
			p = va_arg(ap, char *);
			if (p == NULL)
			{	exit(2);
				return (0); }
			while (*p)
			{	write(1, p, 1);
				len++;
				p++; } }
		else if ((*format == 'd' || *format == 'i') && *(format - 1) == '%')
		{	nbr = va_arg(ap, int);
			len = _printf(len, nbr); }
		format++; }
	va_end(ap);
}
