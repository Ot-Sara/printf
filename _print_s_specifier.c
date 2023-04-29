#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**_print_s_specifier- prints string and handle Non printable characters
 * @len: length of what preceds
 * @p: pointer to char
 *
 * Return: new length after printing
 */
int _print_s_specifier(int len, char *p)
{
	char c;

	while (*p)
	{
		if (*p >= 32 && *p < 127)
		{	write(1, p, 1);
			len++;
		}
		else
		{
			c = '\\';
			write (1, &c, 1);
			len++;
			c = 'x';
			write (1, &c, 1);
			len++;
			if (*p <= 15)
			{
				c = '0';
				write(1, &c, 1);
				len++;
			}
			len = _convert_HEX(len, *p);
		}	
		p++;
	}
	return (len);

}

