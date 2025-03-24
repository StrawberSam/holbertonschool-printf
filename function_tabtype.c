#include "main.h"
#include "stdarg.h"
#include "stdio.h"

void (*function_tabtype(char *s))(int)
{
	type_function type[] = {
		{'c', print_char},
		{'s', print_string}
	};
}
