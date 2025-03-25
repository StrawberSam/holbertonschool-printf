#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct type_function
{
	char type_cifs;
	void (*function_print)(va_list arguments);
} type_function;

int _putchar(char c);
void print_char(va_list arguments);
void print_string(va_list arguments);
int _printf(const char * const format, ...);

#endif /* MAIN_H */
