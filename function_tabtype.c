#include "main.h"

void (*function_tabtype(char *s))(int)
{
	type_function type[] = {
		{'c', print_char},
		{'s', print_string},
		{NULL, NULL}
	};

	int i = 0;

	while (type[i].type_cifs != NULL && strcmp(s, type[i].type_cifs) != 0)
	{
		i++;
	}
	return (type[i].function_print);
}
