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
 * _to_add_pos- spaces to add to reach field width for positif int
 * @f_w:  field width
 * ui: long int
 *
 * Return: number of spaces that should be printed
 */

int _to_add_pos(int fw, long int n)
{
	long int nbr;
	int i = 1, d = 0;
	
	nbr = n;
	if (nbr < 10)
		d++;

	while (nbr > 10)
	{	while (nbr >= 10)
		{	nbr = nbr / 10;
			i = i * 10; }
			d++;
			nbr = n % i;
			while (nbr < (i / 10))
			{	i = i / 10;
			d++;
			nbr = nbr % i; }
			i = 1; 
	}
	if (nbr != 0)
		d++;
	if (fw <= d)
		return (0);
	else
		return (fw - d);
}
/**
 * _to_add_pos- spaces to add to reach field width for negatif int
 * @f_w:  field width
 * ui: long int
 *
 * Return: number of spaces that should be printed
 */

int _to_add_neg(int fw, long int n)
{
	long int nbr;
	int i = 1, d = 0;

	d++;
	nbr = n;
	if (nbr > -10)
		d++;
	while (nbr / 10)
	{
		while (nbr / 10)
		{	nbr = nbr / 10;
			i = i * 10; }
		d++;
		nbr = n % i;
		while (-nbr < (i / 10))
		{	i = i / 10;
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
/**
 * _to_add_oxX- spaces to add to reach field width for oct, hexa, and HEXA
 * @fw: field width
 * @n: number to print in (octal, hexadecimal or HEXADECIMAL)
 *
 * Return: number of spaces to print
 */

int _to_add_oxX(int fw, long int n)
{
	int i = 0;

	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 8;
		i++; }
	if (fw <= i)
		return (0);
	else
		return (fw - i);
}
/**
 * _to_add_string: spaces to add to reach field width
 * @fw: field width
 * @s: string to print
 *
 * Return: number of spaces to print
 */
 
int _to_add_string(int fw, char *s)
{
	int d = 0;
	
	while (*s)
	{	s++;
		d++;
	}
	if (d >= fw)
		return (0);
	else
		return (fw - d);
}
/**
 * _isdigit- checks for a digit (0 through 9).
 * @c: Integer to check
 *
 * Return: 1 if c is a digit 0 otherwise
 */

int _isdigit(int c)
{
	int i = '0';
	int find = 0;

	while (i <= '9')
	{
		if (c == i)
		{
			find = 1;
			break;
		}
		else
			i++;
	}
	return (find);
}
/**
 * _precision- prints float with precision
 * @len: length of what preceds
 * @pr: orecision
 * @b: float to print
 *
 * Return: new length after printing

int _precision(int len, int pr, float b)
{
	int nbr;
	float rm;
	int m = 1;
	char c;
       
	nbr = b / 1;
	rm = b - nbr;
	printf("\n this %f\n", rm);

	len = _print_positif_int(len, nbr);
	while (pr)
	{
		m = m * 10;
		pr--;
	}
	if (m != 1)
	{	c = '.';
		write(1, &c, 1);
		len++;
		printf("\n%d\n", rm * m);
		len = _print_positif_int(len, rm * m);
	}
	return (len);
}
*/
int err(int len)
{
	char c = '0';
	int i;

	write(1, &c, 1);
	len++;
	c = 'x';
	write(1, &c, 1);
	len++;
	c = 'f';
	for(i = 0; i <= 15; i++)
	{
		write(1, &c, 1);
		len++;
	}
	return(len);
}

/**
 * _printf-prints
 * @format: const pointer to char
 * ...: arguments
 *
 * Return: Integer
 */
int _printf(const char *format, ...)
{	int len = 0, ns, fw, nbr/**,pr*/;
	char c, c1, *p;
	/**float b;*/
	va_list ap;
	long int ui;
	unsigned long n;

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
		else if (*format == '%' && *(format + 1) == '%' && *(format + 2) != 'c' && *(format + 2) != 's' && *(format + 2) != 'd' && *(format + 2) != 'i' && *(format + 2) != 'u' && *(format + 2) != 'b' && *(format + 2) != 'o' && *(format + 2) != 'x' && *(format + 2) != 'X' && *(format + 2) != 'S' && *(format + 2) != 'p'
	&& ((*(format + 2) != 'l' && *(format + 2) != 'h' && !_isdigit(*(format + 2)) && *(format + 2) != '*') || (*(format + 3) != 'd' && *(format + 3) != 'i' && *(format + 3) != 'u' && *(format + 3) != 'o' && *(format + 3) != 'x' && *(format + 3) != 'X'))
	&& (!_isdigit(*(format + 2) && *(format + 2) != '*') && (*(format + 3) != 'c' && *(format + 3) != 's'))
	&& ((*(format + 2) != ' ' && *(format + 2) != '+') || (*(format + 3) != 'd' && *(format + 3) != 'i')) && ((*(format + 2) != ' ' || *(format + 3) != '+') && (*(format + 2) != '+' || *(format + 3) != ' '))
	&& (((*(format + 2) != ' ' || *(format + 3) != '+') && (*(format + 2) != '+' || *(format + 3) != ' ')) || (*(format + 4) != 'd' && *(format + 4) != 'i' )) 
       	&& ((*(format + 2) != '#') || (*(format + 3) != 'o' && *(format + 3) != 'x' && *(format + 3) != 'X')) /**&& (*(format + 2) != '.' && !_isdigit(*(format + 3)) && *(format + 4) != 'f')*/)
		{
			len = _print_char(len, format);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == '%' && *(format + 2) == '%')
		{
			len = _print_char(len, format);
			format = format + 2;
		}
		else if (*format == '%' && *(format + 1) == ' ' && *(format + 2) == '%' && *(format + 3) == ' ' && ((*(format + 4) != 'd' && *(format + 4) != 'i') && (*(format + 4) != '+' || (*(format + 5) != 'd' && *(format + 5) != 'i')))) 
		{	len = _print_char(len, format);
			len = _print_char(len, format + 1);
			format = format + 4;
		}


		else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{	nbr = va_arg(ap, int);
			if (nbr >= 0)
				len = _print_positif_int(len, nbr);
			else
				len = _print_negatif_int(len, nbr);
			format = format + 2; }
		else if (*format == '%' && (*(format + 1) == 'l' || *(format + 1) == 'h') && ( *(format + 2) != 'd' && *(format + 2) != 'i' && *(format + 2) != 'u' && *(format + 2) != 'o' && *(format + 2) != 'x' && *(format + 2) != 'X'))
		{
			len = _print_char(len, format);
			format = format + 2;

		}
		else if (*format == '%' && *(format + 1) == 'l' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
		{
			ui = va_arg(ap, long int);
			if (ui >= 0)
				len = _print_positif_int(len, ui);
			else
				len = _print_negatif_int(len, ui);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == 'h' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
			 {
				 nbr = va_arg(ap, int);
				 if (nbr >= 0)
					 len = _print_positif_int(len, nbr);
				 else
					 len = _print_negatif_int(len, nbr);
				 format = format + 3;
			 }
		else if (*format == '%' && (*(format + 1) == 'l' || *(format + 1) == 'h' ) && *(format + 2) == 'u')
		{
			n = va_arg(ap, unsigned long int);
			/**if (ui > UINT_MAX)
				ui = ui - UINT_MAX - 1;*/
			len = _print_positif_int(len, n);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == 'u')
		{	n = va_arg(ap, unsigned long int);
			if (n > UINT_MAX)
				n = n - UINT_MAX - 1;
			len = _print_positif_int(len, n);
                        format = format + 2; }

		else if (*format == '%' && *(format + 1) == 'c')
		{	c = va_arg(ap, int);
			len = _print_char(len, &c);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'b')
		{	
			ui = va_arg(ap, long int);
			if (ui > UINT_MAX)
				ui = ui - UINT_MAX - 1;
			len = _convert_ui_b(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 'o')
		{	
			ui = va_arg(ap, long int);
			if (ui > UINT_MAX)
				ui = ui - UINT_MAX - 1;
			len = _convert_oct(len, ui);
			format = format + 2; }
		else if (*format == '%' && *(format + 1) == 's')
		{	p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
				len = _print_string(len, p);
			format = format + 2; }
		else if (*format == '%' && (*(format + 1) == 'l' || *(format + 1) == 'h' ) && *(format + 2) == 'o')
		{
			n = va_arg(ap, unsigned long int);
			len = _convert_oct(len, n);
			format = format + 3;

		}
		else if (*format == '%' && *(format + 1) == 'x')
		{	
			ui = va_arg(ap, long int);
			if (ui > UINT_MAX)
				ui = ui - UINT_MAX - 1;
			len = _convert_hex(len, ui);
			format = format + 2; }
		else if (*format == '%' && (*(format + 1) == 'l' || *(format + 1) == 'h' ) && *(format + 2) == 'x')
		{
			n = va_arg(ap, unsigned long int);
			len = _convert_hex(len, n);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == 'X')
		{	
			ui = va_arg(ap, long int);
			if (ui > UINT_MAX)
				ui = ui - UINT_MAX - 1;
			len = _convert_HEX(len, ui);
			format = format + 2; }
		else if (*format == '%' && (*(format + 1) == 'l' || *(format + 1) == 'h' ) && *(format + 2) == 'X')
		{
			n = va_arg(ap, unsigned long int);
			len = _convert_HEX(len, n);
			format = format + 3;
		}
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
			else if (ui == -1)
				len = err(len);
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
			nbr = va_arg(ap, int);
			if (nbr >= 0)
			{
				c = *(format + 1);
				write(1, &c, 1);
				len++;
				len = _print_positif_int(len, nbr);
			}
			else
				len = _print_negatif_int(len, nbr);
			format = format + 3;
		}
		else if (*format == '%' && (((*(format + 1) == ' ' && *(format + 2) == '+') || (*(format + 1) == '+' && *(format + 2) == ' ')) && (*(format + 3) == 'd' || *(format + 3) == 'i')))
		{
			nbr = va_arg(ap, int);
			if (nbr >= 0)
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
				len = _print_positif_int(len, nbr);
			}
			else
				len = _print_negatif_int(len, nbr);
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
		else if (*format == '%' && _isdigit(*(format + 1)) && (*(format + 2) == 'd' || *(format + 2) == 'i'))
		{	nbr = va_arg(ap, int);
			if (nbr >= 0)
			{
				ns = _to_add_pos((*(format + 1) - 48), nbr);
				while (ns)
				{	c = ' ';
					write(1, &c, 1);
					len++;
					ns--;
				}
				len = _print_positif_int(len, nbr);
			}
			else
			{
				ns = _to_add_neg((*(format + 1) - 48), nbr);
				while (ns)
				{	c = ' ';
					write(1, &c, 1);
					len++;
					ns--;
				}
				len = _print_negatif_int(len, nbr);
			}
			format = format + 3; }
		else if (*format == '%' && *(format + 1) == '*' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
		{	fw = va_arg(ap, int);
			nbr = va_arg(ap, int);
			if (nbr >= 0)
			{
				ns = _to_add_pos(fw, nbr);
				while (ns)
				{	c = ' ';
					write(1, &c, 1);
					len++;
					ns--;
				}
				len = _print_positif_int(len, nbr);
			}
			else
			{
				ns = _to_add_neg(fw, nbr);
				while (ns)
				{	c = ' ';
					write(1, &c, 1);
					len++;
					ns--;
				}
				len = _print_negatif_int(len, nbr);
			}
			format = format + 3; }
		else if (*format == '%' && *(format + 1) == '*' && *(format + 2) == 'u')
		{
			fw = va_arg(ap, int);
			ui = va_arg(ap, long int);
			ns = _to_add_pos(fw, ui);
			while (ns)
			{
				c = ' ';
				write(1, &c, 1);
				len++;
				ns--;
			}
			len = _print_positif_int(len, ui);
			format = format + 3;
		}
	
		else if (*format == '%' && _isdigit(*(format + 1)) && *(format + 2) == 'u')
		{	ui = va_arg(ap, long int);
			ns = _to_add_pos((*(format + 1) - 48), ui);
			while (ns)
			{	c = ' ';
				write(1, &c, 1);
				len++;
				ns--;
			}
			len = _print_positif_int(len, ui);
			format = format + 3;
		}
		else if (*format == '%' && _isdigit(*(format + 1)) && *(format + 2) == 'c')
		{	c = va_arg(ap, int);
			ns = *(format + 1) - 48;
			while (ns > 1)
			{
				c1 = ' ';
				write(1, &c1, 1);
				len++;
				ns--;
			}
			len = _print_char(len, &c);
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == '*' && *(format + 2) == 'c')
		{	ns = va_arg(ap, int);
			c = va_arg(ap, int);
			while (ns > 1)
			{
				c1 = ' ';
				write(1, &c1, 1);
				len++;
				ns--;
			}
			len = _print_char(len, &c);
			format = format + 3;
		}

		else if (*format == '%' && _isdigit(*(format + 1)) && *(format + 2) == 's')
		{	p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
			{	ns = _to_add_string(*(format + 1) - 48, p);
				while (ns)
				{
					c1 = ' ';
					write(1, &c1, 1);
					len++;
					ns--;
				}
				len = _print_string(len, p);
			}
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == '*' && *(format + 2) == 's')
		{	fw = va_arg(ap, int);
			p = va_arg(ap, char *);
			if (p == NULL)
				len = _print_NULL(len);
			else
			{	ns = _to_add_string(fw, p);
				while (ns)
				{
					c1 = ' ';
					write(1, &c1, 1);
					len++;
					ns--;
				}
				len = _print_string(len, p);
			}
			format = format + 3;
		}

		else if (*format == '%' && _isdigit(*(format + 1)) && (*(format + 2) == 'o' || *(format + 2) == 'x' || *(format + 2) == 'X'))
		{	ui = va_arg(ap, long int);
			if (*(format + 2) == 'o')
			{	ns = _to_add_oxX((*(format + 1) - 48), ui);
				while (ns)
                        	{       c = ' ';
                                	write(1, &c, 1);
                                	len++;
                                	ns--;
                        	}
				len = _convert_oct(len, ui);
			}
			else if (*(format + 2) == 'x')
			{
				ns = _to_add_oxX((*(format + 1) - 48), ui);
                                if (ns > 0 && ui > 9)
					ns++;
				while (ns)
                                {       c = ' ';
                                        write(1, &c, 1);
                                        len++;
                                        ns--;
                                }
				len = _convert_hex(len, ui);
			}
			else
			{	
				ns = _to_add_oxX((*(format + 1) - 48), ui);
				if (ns > 0 && ui > 9)
					ns++;
                                while (ns)
                                {       c = ' ';
                                        write(1, &c, 1);
                                        len++;
                                        ns--;
                                }
				len = _convert_HEX(len, ui);
			}
			format = format + 3;
		}
		else if (*format == '%' && *(format + 1) == '*' && (*(format + 2) == 'o' || *(format + 2) == 'x' || *(format + 2) == 'X'))
		{	fw = va_arg(ap, int);
			ui = va_arg(ap, long int);
			if (*(format + 2) == 'o')
			{	ns = _to_add_oxX(fw, ui);
				while (ns)
                        	{       c = ' ';
                                	write(1, &c, 1);
                                	len++;
                                	ns--;
                        	}
				len = _convert_oct(len, ui);
			}
			else if (*(format + 2) == 'x')
			{
				ns = _to_add_oxX(fw, ui);
                                if (ns > 0 && ui > 9)
					ns++;
				while (ns)
                                {       c = ' ';
                                        write(1, &c, 1);
                                        len++;
                                        ns--;
                                }
				len = _convert_hex(len, ui);
			}
			else
			{	
				ns = _to_add_oxX(fw, ui);
				if (ns > 0 && ui > 9)
					ns++;
                                while (ns)
                                {       c = ' ';
                                        write(1, &c, 1);
                                        len++;
                                        ns--;
                                }
				len = _convert_HEX(len, ui);
			}
			format = format + 3;
		}
		/**else if (*format == '%' && *(format + 1) == '.' && _isdigit(*(format + 2)) && *(format + 3) == 'f')
		{
			b = va_arg(ap, double);
			pr = *(format + 3) - 48;
			len = _precision(len, pr, b);
			format = format + 4;
		}*/

		else
		{
			len = _print_char(len, format);
			format++; } }
	va_end(ap);
	return (len); }
