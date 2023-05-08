#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
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
int _to_add_pos(int fw, long int n);
int _to_add_neg(int fw, long int n);
int _to_add_oxX(int fw, long int n);
int _to_add_string(int fw, char *s);
int _isdigit(int c);
int err(int len);
#endif /* MAIN_H */
