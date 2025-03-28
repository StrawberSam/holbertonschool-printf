#include "main.h"
/**
 *print_char - fonction qui print un char
 * En C, les char sont automatiquement promus en int dans les fonctions
 *variadiques. Quand on récupère un char depuis va_list, on doit le traiter
 *comme un int. Pour afficher le char, on le stocke dans une variable char,
 *mais on le récupère avec va_arg(arguments, int)
 *@arguments:Liste variadique
 * Return: 1 pour le char
 */

int print_char(va_list arguments)
{
	char c = va_arg(arguments, int);
/* Affiche le caractère et vérifie si l'affichage a échoué */
	if (_putchar(c) == -1)
		return (-1);
	return (1); /* Retourne 1 car un seul caractère est imprimé */
}
/**
 *print_string - fonction qui print une chaîne de caractère
 *@arguments:Liste variadique
 *Return: counter pour afficher la string charactère par charactère
 */
int print_string(va_list arguments)
{ /* Récupère la chaîne de caractères depuis la liste d'arguments */
	char *str = va_arg(arguments, char *);
	int i, counter = 0;

	if (str == NULL)  /* Si chaîne est NULL, on affiche "(null)"*/
		str = "(null)";
 /* Parcourt et affiche chaque caractère de la chaîne à l'aide de i*/
	for (i = 0; str[i] != '\0'; i++)
	{ /* Vérifie si _putchar renvoie une erreur (-1) */
		if (_putchar(str[i]) == -1)
			return (-1);
		counter++;/* Incrémente le compteur après chaque affichage réussi */
	} /* Retourne le nombre total de caractères affichés */
	return (counter);
}

/**
 *print_percent - fonction qui print %
 *@arguments:Liste variadique
 * Return: 1 pour le compteur
 */
int print_percent(va_list arguments)
{ /* On ignore le paramètre arguments car il n'est pas utilisé */
	(void)arguments;
  /* Affiche le caractère '%' et vérifie si l'affichage a échoué */
	if (_putchar('%') == -1)
		return (-1);
	return (1); /* Retourne 1 car un seul caractère est imprimé */
}

/**
 * print_decimal - fonction qui print un décimal. On divise un nombre par
 * 10 dans le système décimal pour extraire ses chiffres, car chaque
 * chiffre d'un nombre correspond à une puissance de 10 (unités, dizaines,
 * centaines, etc.). En utilisant modulo 10, on récupère le dernier
 * chiffre, et en divisant le nombre par 10, on élimine ce chiffre pour
 * répéter l'opération jusqu'à ce que tout le nombre soit extrait. Diviser
 * par 10 permet donc de traiter chaque chiffre dans l'ordre de droite à
 * gauche, ce qui est propreà la base 10.
 * Base 10 (décimal) : Un tableau de taille 12 suffira pour un nombre
 * signé int de 32 bits (pour couvrir la plage de -2147483648 à 2147483647).
 *@arguments:Liste variadique
 * Return: Counter pour le compteur
 */

int print_decimal(va_list arguments)
{ /* Récupère l'entier depuis la liste d'arguments */
	long integer = va_arg(arguments, int);
	int counter = 0; /* Compteur de caractères affichés */
	char tab_numbers[12];/*Tableau stocker chiffres */
	int index = 0;/* Indice pour remplir le tableau */
	int i;/* Variable pour parcourir le tableau */

	if (integer < 0) /* Vérifie si l'entier est négatif */
	{
		_putchar('-');/* Affiche le signe '-' */
		integer = -integer;/* Convertit en positif */
		counter++;/* Incrémente le compteur */
	}
 /* Cas particulier : si l'entier est 0, on affiche directement 0*/
	if (integer == 0)
	{
		_putchar('0');
		counter++;
	}
/* Récupération des chiffres et stocke dans tab_numbers si integer positif*/
	while (integer > 0)
	{ /*récupère + stock dernier chiffre*/
		tab_numbers[index++] = integer % 10;
		integer = integer / 10; /* Réduit l'entier (1024 puis 102...) */
	} /* stocke les chiffres dans l'ordre inverse*/

/* Affichage des chiffres dans l'ordre correct */
	for (i = index - 1; i >= 0; i--)/* Parcourt le tableau à l'envers */
	{ /* Convertit le chiffre en caractère et l'affiche */
		(_putchar('0' + tab_numbers[i]));
		counter++;
	} /* Retourne le nombre total de caractères affichés */
	return (counter);
}
