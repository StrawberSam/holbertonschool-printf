#include "main.h"

/**
 * _printf - Fonction qui copie la fonction printf
 *@format: tableau de specifiers
 * Return: 0 = ok; -1 = faux
 */
int _printf(const char * const format, ...)
{
	int i = 0, j, total_char = 0;
	va_list arguments;

	type_function type[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

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
			total_char++;

			while (type[j].type_cifs != '\0')
			{
				if (format[i] == type[j].type_cifs)
				{
					total_char += type[j].function_print(arguments);
					break;
				}
				j++;
				total_char++;
			}
		}
		else if (format[i] != '\0')
			_putchar(format[i]);
		i++;
		total_char++;
	}
	va_end(arguments);
	return (total_char);
}
