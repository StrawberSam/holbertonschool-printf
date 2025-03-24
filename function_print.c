#include "main.h"
#include "stdarg.h"
#include "stdio.h"

void print_char(va_list arguments)
{
	va_arg(arguments, char);
	_putchar('c');
}

