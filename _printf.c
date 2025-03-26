#include "main.h"

/**
 * _printf - Fonction qui copie la fonction printf
 *@format: tableau de specifiers
 * Return: 0 = ok; -1 = faux
 */
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

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i = i + 1;
			if (format[i] == '\0')
				break;
			else if (format[i] == '%')
			_putchar(37);
			j = 0;
			while (j < 4)
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
			_putchar(format[i]);
		i++;
	}
	va_end(arguments);
	return (0);
}
