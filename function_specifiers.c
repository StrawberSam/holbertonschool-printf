#include "main.h"
/**
 *print_char - fonction qui print un char
 *@arguments:Liste variadique
 *Return: 1 pour le char
 */

int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);

	if (_putchar(c) == -1)
		return (-1);
	return (1);
}
/**
 *print_string - fonction qui print une chaîne de caractère
 *@arguments:Liste variadique
 *Return: counter pour afficher la string charactère par charactère
 */
int print_string(va_list arguments)
{
	char *str = va_arg(arguments, char *);
	int i, counter = 0;

	if (!str)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (_putchar(str[i]) == -1)
			return (-1);
		counter++;
	}
	return (counter);
}

/**
 *print_percent - fonction qui print %
 *@arguments:Liste variadique
 *Return: 1 pour le compteur
 */
int print_percent(va_list arguments)
{
	(void)arguments;

	if (_putchar('%') == -1)
		return (-1);
	return (1);
}
