#ifndef MAIN_H
#define MAIN_H

#include "stdarg.h"

typedef struct type_function
{
	char type;
	void (*function_print)(va_list arguments);
} type_function;

int _putchar(char c);

#endif /* MAIN_H */
