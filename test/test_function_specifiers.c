#include "test_main.h"



int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	if (_putchar(c) == -1)
		return (-1);
	return (1);
}

int print_string(va_list arguments)
{
	char *str = va_arg(arguments, char *);
	int i, counter = 0;

	if (!str)
		str = NULL;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (_putchar(str[i]) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}
