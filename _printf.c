#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _print_nil- prints (nil)
 * @len: length of what preceds
 *
 * Return: new length after printing
 */
int _print_nil(int len)
{
	char c;
	c = '(';
	write(1,&c,1);
	c = 'n';
	write(1,&c,1);
	c = 'i';
	write(1,&c,1);
	c = 'l';
	write(1,&c,1);
	c = ')';
	write(1,&c,1);
	len = len + 5;
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
{	int len = 0;
	char c, *p;
	va_list ap;
	long int ui;

	if (format == NULL || *format == '\0')
	{
		exit(1);
		return (0);
	}
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == '\0' || (*(format + 1) == ' ' && *(format + 2) == '\0')))
			
			return (-1);
		else if (*format == '%' && *(format + 1) == '%' && *(format + 2) != 'c' && *(format + 2) != 's' && *(format + 2) != 'd' && *(format + 2) != 'i' && *(format + 2) != 'u' && *(format + 2) != 'b' && *(format + 2) != 'o' && *(format + 2) != 'x' && *(format + 2) != 'X' && *(format + 2) != 'S' && *(format + 2) != 'p' && (*(format + 2) != 'l' || (*(format + 3) != 'd' && *(format + 3) != 'i' && *(format + 3) != 'u')) && ((*(format + 2) != ' ' && *(format + 2) != '+') || (*(format + 3) != 'd' && *(format + 3) != 'i')) && ((*(format + 2) != ' ' || *(format + 3) != '+') && (*(format + 2) != '+' || *(format + 3) != ' ')) && (((*(format + 2) != ' ' || *(format + 3) != '+') && (*(format + 2) != '+' || *(format + 3) != ' ')) || (*(format + 4) != 'd' && *(format + 4) != 'i' ))  && ((*(format + 2) != '#') || (*(format + 3) != 'o' && *(format + 3) != 'x' && *(format + 3) != 'X')))
		{	len = _print_char(len, format);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == ' ' && *(format + 2) == '%' && *(format + 3) == ' ' && ((*(format + 4) != 'd' && *(format + 4) != 'i') && (*(format + 4) != '+' || (*(format + 5) != 'd' && *(format + 5) != 'i')))) 
		{	len = _print_char(len, format);
			len = _print_char(len, format + 1);
			format = format + 4;
		}


		else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{	ui = va_arg(ap, long int);
			if (ui >= 0)
				len = _print_positif_int(len, ui);
			else
				len = _print_negatif_int(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'l' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
		{
			ui = va_arg(ap, long int);
			if (ui >= 0)
				len = _print_positif_int(len, ui);
			else
				len = _print_negatif_int(len, ui);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == 'l' && *(format + 2) == 'u')
		{
			ui = va_arg(ap, long int);
			len = _print_positif_int(len, ui);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == 'u')
		{	ui = va_arg(ap, long int);
			len = _print_positif_int(len, ui);
                        format = format + 2; }

		else if (*format == '%' && *(format + 1) == 'c')
		{	c = va_arg(ap, int);
			len = _print_char(len, &c);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 's')
		{	p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
				len = _print_string(len, p);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'b')
		{	
			ui = va_arg(ap, long int);
			len = _convert_ui_b(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'o')
		{	
			ui = va_arg(ap, long int);
			len = _convert_oct(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'x')
		{	
			ui = va_arg(ap, long int);
			len = _convert_hex(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'X')
		{	
			ui = va_arg(ap, long int);
			len = _convert_HEX(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'S')
		{	p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
				len = _print_s_specifier(len, p);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'p')
		{
			ui = va_arg(ap, long int);
			if (ui == 0)
				len = _print_nil(len);
			else
			{	c = '0';
				write(1, &c, 1);
				c = 'x';
				write(1,&c,1);
				len = len + 2;
				len = _convert_hex(len, ui);
			}
			format = format + 2;
		}
		else if (*format == '%' && (*(format + 1) == ' ' || *(format + 1) == '+')&& (*(format + 2) == 'd' || *(format + 2) == 'i'))
		{
			ui = va_arg(ap, long int);
			if (ui >= 0)
			{
				c = *(format + 1);
				write(1, &c, 1);
				len++;
				len = _print_positif_int(len, ui);
			}
			else
				len = _print_negatif_int(len, ui);
			format = format + 3;
		}
		else if (*format == '%' && (((*(format + 1) == ' ' && *(format + 2) == '+') || (*(format + 1) == '+' && *(format + 2) == ' ')) && (*(format + 3) == 'd' || *(format + 3) == 'i')))
		{
			ui = va_arg(ap, long int);
			if (ui >= 0)
			{
				if (*(format + 1) == ' ')
				{
					c = *(format + 1);
					write(1, &c, 1);
					len++;
				}
				c = '+';
				write(1, &c, 1);
				len++;
				len = _print_positif_int(len, ui);
			}
			else
				len = _print_negatif_int(len, ui);
			format = format + 4;
		}
		else if (*format == '%' && *(format + 1) == '#' && (*(format + 2) == 'o' || *(format + 2) == 'x' || *(format + 2) == 'X'))
		{
			ui = va_arg(ap, long int);
			c = '0';
			write(1, &c, 1);
			len++;
			if ((ui != 0) && (*(format + 2) == 'x'))
			{
				c = 'x';
				write(1, &c, 1);
				len++;
				len = _convert_hex(len, ui);
			}
			else if ((ui != 0) && (*(format + 2) == 'X'))
			{
				c = 'X';
				write(1, &c, 1);
				len++;
				len = _convert_HEX(len, ui);
			}
			else if ((ui != 0) && (*(format + 2) == 'o'))
			{	
				
				len = _convert_oct(len, ui);
			}
			format = format + 3;
		}
	


		else
		{	len = _print_char(len, format);
			format++; } }
	va_end(ap);
	return (len); }
