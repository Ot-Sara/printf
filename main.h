#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _printf_string(int len, char *p);
int _print_int(int len, int n);
int _printf(const char *format, ...);

#endif /* MAIN_H */

