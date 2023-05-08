#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
int _printf(const char *format, ...);
int _print_string(int len, char *p);
int _print_positif_int(int len, unsigned long int n);
int _print_negatif_int(int len, long int n);
int _print_NULL(int len);
int _print_char(int len, const char *p);
int _convert_ui_b(int len, long int n);
int _convert_oct(int len, unsigned long int n);
int _convert_hex(int len, unsigned long int n);
int _convert_HEX(int len, unsigned long int n);
int _print_s_specifier(int len, char *p);
int _print_nil(int len);
#endif /* MAIN_H */
