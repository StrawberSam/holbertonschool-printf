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

/**
 *print_decimal - fonction qui print un décimal
 *@arguments:Liste variadique
 *Return: Counter pour le compteur
 */

int print_decimal(va_list arguments)
{
	long integer = va_arg(arguments, int);
	int counter = 0;
	char tab_numbers[12];
	int index = 0;
	int i;

	if (integer == 0)
	{
		_putchar('0');
		counter++;
	}

	if (integer < 0)
	{
		_putchar('-');
		integer = -integer;
		counter++;
	}
	printf("nombre entier imprimé : %d\n", integer);
	while (integer > 0)
	{
		tab_numbers[index++] = integer % 10;
		integer = integer / 10;
	}

	for (i = index - 1; i >= 0; i--)
	{
		(_putchar('0' + tab_numbers[i]));
		counter++;
	}
	return (counter);
}

/**
 *print_int - fonction qui print un entier
 *@arguments:Liste variadique
 *Return: Counter pour le compteur
 */
int print_int(va_list arguments)
{
	int integer = va_arg(arguments, int);
	int counter = 0;
	char tab_numbers[12];
	int index = 0;
	int i;

	if (integer == 0)
	{
		_putchar('0');
		counter++;
	}

	if (integer < 0)
	{
		_putchar('-');
		integer = -integer;
		counter++;
	}
	printf("nombre entier imprimé : %i\n", integer);
	while (integer > 0)
	{
		tab_numbers[index++] = integer % 10;
		integer = integer / 10;
	}

	for (i = index - 1; i >= 0; i--)
	{
		(_putchar('0' + tab_numbers[i]));
		counter++;
	}
	return (counter);
}
