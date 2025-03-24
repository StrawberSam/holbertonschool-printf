#include "main.h"
#include "stdarg.h"
#include "stdio.h"

int i;

void print_char(va_list arguments)
{
	va_arg(arguments, char);
	_putchar('c');
}

void print_string(va_list arguments)
{
	va_arg(arguments, char *);

	for (i = 0; i != '\0'; i++)
	_putchar(i);
}
