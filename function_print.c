#include "main.h"

void print_char(va_list arguments)
{
	_putchar(va_arg(arguments, int));
}

void print_string(va_list arguments)
{/* si la string est NULL, on affiche (nil) */
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
	va_list arguments;
	int i = 0;
	int j;
	/* tableau associant types et fonctions de print */
	type_function type[] = {
		{'c', print_char},
		{'s', print_string}
	};

	va_start(arguments, format); /* initialisation de la liste variadique */
	while (format && format[i]) /* on parcourt la chaîne "format" */
	{
		j = 0;
		while (j < 2) /* on cherche si le type est reconnu */
		{
			if (format[i] == type[j].type_cifs)
			{
				type[j].function_print(arguments); /* on appelle la bonne fonction */
				break; /* on sort du while une fois le type trouvé */
			}
			j++;
		}
		i++; /* on passe au caractère suivant dans "format" */
	}
	va_end(arguments); /* on nettoie la liste variadique */
	_putchar('\n'); /* on ajoute le saut de ligne final */
	return (0);
}
