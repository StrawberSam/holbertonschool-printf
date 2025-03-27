#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * struct type_function - tableau de structure regroupant type et *fonction
 *@type_cifs: type de specifier
 *@function_print: pointeur de fonction sur la fonction correspondante au type
 */

typedef struct type_function
{
	char type_cifs;
	int (*function_print)(va_list arguments);
} type_function;

int _putchar(char c);
int _printf(const char *format, ...);
int find_specifier(const char *format, int i, va_list arguments, int *total_char);

int print_char(va_list arguments);
int print_string(va_list arguments);
int print_percent(va_list arguments);
int print_decimal(va_list arguments);
int print_int(va_list arguments);

#endif /* MAIN_H */
