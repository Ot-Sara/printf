#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _to_add_string - spaces to add to reach field width
 * @fw: field width
 * @s: string to print
 * Return: number of spaces to print
 */

int _to_add_string(int fw, char *s)
{
	int d = 0;

	while (*s)
	{
		s++;
		d++;
	}
	if (d >= fw)
		return (0);
	else
		return (fw - d);
}
