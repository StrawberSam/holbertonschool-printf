#include "main.h"

/**
 * find_specifier - cette fonction est appelée lorsqu'un caractère `%` est
 * rencontré dans la chaîne de format(format). Elle recherche le
 * spécificateur de format qui est après '%' et appelle la fonction
 * correspondante. Un tableau type[] est utilisé pour associer chaque
 * spécificateur à sa fonction correspondante. Ce tableau contient des
 * éléments de type 'type_function' qui associe un caractère
 * (c, d, o,...) à une fonction d'impression correspondante.
 * La fonction parcourt le tableau pour trouver une correspondance entre
 * le caractère actuel de 'format[i]' et les éléments répertorié dans
 * tableau 'type[]'. Si une correspondance est trouvée, la fonction
 * correspondante est appelée pour afficher le résultat, et le nombre
 * total de caractères affichés'total_char' est mis à jour.
 * Si aucun spécificateur valide n'est trouvé, la fonction imprime
 * d'abord le caractère '%', suivi du caractère actuel 'format[i]', ce
 * qui permet de gérer des spécificateurs inconnus comme '%x' ('x'n'étant
 * pas un spécificateur défini dns notre tableau).
 * @format: Chaîne de charactère avec format
 * @i: index du caractère après %, celui qu'on doit vérifier %c par exemple
 * @arguments: Liste des arguments pour print la valeur à afficher (main.c)
 * @total_char: pointeur vers le nombre total de caractères compté
 * Return: Retourne l'index mis à jour après traitement du spécificateur
 */
int find_specifier(const char *format, int i, va_list arguments,
	int *total_char)
{
	int j; /* compteur pour parcourir notre tableau de structure*/
	type_function type[] = { /* associe spécifieur à sa fonction */
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_decimal},
		{'b', print_binaire},
		{'u', print_unsigned},
		{'o', print_octal},
		{'\0', NULL}
	};
/* Parcours le tableau type jusqu'à la fin */
	for (j = 0; type[j].type_cifs != '\0'; j++)
	{ /* si lettre après % correspond avec lettre dans tableau*/
		if (format[i] == type[j].type_cifs)
		{/* print fonction et MAJ le nombre de caractère à afficher*/
			*total_char += type[j].function_print(arguments);
			return (i); /* retourne le nombre de caractère*/
		}
	} /* si pas correspondance, print '%' + caractère actuel ex : %x */
	_putchar('%');
	_putchar(format[i]); /* exemple %x, non pris en charge dans tableau*/
	*total_char += 2; /* ajoute 2 caractères au compteur : % + inconnu */
	return (i); /* retourne le compteur de caractère */
}
