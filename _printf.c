#include "main.h"
/**
 * _printf - Fonction qui copie la fonction printf
 *@format: tableau de specifiers
* Return: total nombre de charactère de la fonction -ptintf
*/

int _printf(const char *format, ...)
{
	int i = 0, total_char = 0;
	va_list args;

	if (format == NULL || format[i + 1] == '\0')
		return (-1);

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
			i = find_specifier(format, ++i, args, &total_char);
		else
		{
			_putchar(format[i]);
			total_char++;
		}
		i++;
	}
	va_end(args);
	return (total_char);
}
