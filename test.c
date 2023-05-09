#include "main.h"
#include <unistd.h>
int _print_u(int len, unsigned long int n)
{
	unsigned long int i = 1;
	unsigned long int nbr = n;
	char c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		len++;
		return (len);
	}
	while (n / 10)
	{	n = n / 10;
		i = i * 10;
	}
	while(i >= 10)
	{
		c = (nbr / i) + '0';
		write(1, &c, 1);
		len++;
		nbr = nbr % i;
		i = i / 10;
	}
	c = nbr + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
