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
		if(_putchar(str[i]) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

int _printf(const char * const format, ...)
{
	int i = 0, j;
	type_function type[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

	va_list arguments;
	va_start(arguments, format);

	if (!format)
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

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

		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}

	va_end(arguments);
	return (0);
}
