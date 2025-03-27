#include "main.h"

/**
 * find_specifier - trouve le bon spécifieur avec la bonne fonction
 * @format: Chaîne de charactère avec format
 * @i: index du caractère après %, celui qu'on doit vérifier
 * @args: Liste des arguments pour print la valeur à afficher
 * @total_char: pointeur vers le nombre total de caractères compté
 * Return: retourne Nouvel index après traitement
 */
int find_specifier(const char *format, int i, va_list arguments,
	int *total_char)
{
	int j;
	type_function type[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};

	for (j = 0; type[j].type_cifs != '\0'; j++)
	{
		if (format[i] == type[j].type_cifs)
		{
			*total_char += type[j].function_print(arguments);
			return (i);
		}
	}
	_putchar('%');
	_putchar(format[i]);
	*total_char += 2;
	return (i);
}
