#include "main.h"

void print_char(va_list arguments)
{
	_putchar(va_arg(arguments, int));
}

void print_string(va_list arguments)
{
	char *str = va_arg(arguments, char *);
	int i = 0;

	if (!str)
		str = "(nil)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

int _printf(const char * const format, ...)
{
	int i = 0; int j;

	type_function type[] = {
		{'c', print_char},
		{'s', print_string}
	};
	va_list arguments;
	va_start(arguments, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 2)
		{
			if (format[i] == type[j].type_cifs)
			{
				type[j].function_print(arguments);
				break;
			}
			j++;
		}
		i++;
	}
	va_end(arguments);
	_putchar('\n');
	return (0);
}
