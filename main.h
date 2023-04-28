#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
int _printf(const char *format, ...);
int _print_string(int len, char *p);
int _print_positif_int(int len, long int n);
int _print_negatif_int(int len, int n);
int _print_NULL(int len);
int _print_char(int len, const char *p);
int _convert_ui_b(int len, long int n);
int _convert_oct(int len, long int n);
int _convert_hex(int len, long int n);
int _convert_HEX(int len, long int n);
#endif /* MAIN_H */
