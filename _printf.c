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
/* Vérification de format (NULL ou une chaîne contenant uniquement '%') */
	if (format == NULL || format[i + 1] == '\0')
		return (-1);

	va_start(arguments, format); /* Initialisation liste arguments variables */

	while (format != NULL && format[i] != '\0')/* Parcourt la chaîne format */
	{
		if (format[i] == '%')/*Vérifie si 1 spécificateur de format est trouvé*/
			i = find_specifier(format, ++i, arguments, &total_char);
		else /*î=renvoie vers fonction gère les print quand '%' est trouvé*/
		{ /* ELSE si '%' pas trouvé */
			_putchar(format[i]);/* Affiche le caractère normal (ex : "hello") */
			total_char++;/* Incrémente le compteur de caractères affichés */
		}
		i++;/* Passe au caractère suivant dans 'format[i]'*/
	}
	va_end(arguments);/* Libère la liste des arguments */
	return (total_char);/* Retourne le nombre total de caractères affichés */
}
