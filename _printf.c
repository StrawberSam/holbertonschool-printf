#include "main.h"
/**
 * _printf - Fonction qui copie la fonction printf
 *@format: tableau de specifiers
* Return: total nombre de charactère de la fonction -ptintf
*/

int _printf(const char *format, ...)
{
	int i = 0, total_char = 0;
	va_list arguments;

	if (format == NULL || format[i + 1] == '\0')
		return (-1);

	va_start(arguments, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
			i = find_specifier(format, ++i, arguments, &total_char);
		else
		{
			_putchar(format[i]);
			total_char++;
		}
		i++;
	}
	va_end(arguments);
	return (total_char);
}
