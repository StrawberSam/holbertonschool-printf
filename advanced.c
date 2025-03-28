#include "main.h"

/**
 * print_binaire - Fonction qui transforme un nombre décimal en binaire.
 * On divise un nombre par 2 dans le système binaire pour extraire ses
 * chiffres car chaque chiffre d'un nombre binaire est soit 0, soit 1.
 * En utilisant modulo 2, on récupère le dernier chiffre, et en divisant
 * le nombre par 2, on élimine ce chiffre pour répéter l'opération jusqu'à
 * ce que tout le nombre soit extrait. Diviser par 2 permet donc de traiter
 * chaque chiffre de droite à gauche, ce qui est propre à la base 2.
 * Base 2 (binaire) : Un tableau de taille 33 sera nécessaire pour un nombre
 * signé int de 32 bits (en raison de la représentation du signe et de la
 * valeur maximale 2147483647, qui a 31 bits plus 1 bit pour le signe).
 * @arguments: Liste variadique contenant le nombre à convertir.
 * Return: Counter pour le compteur des caractères affichés.
 */

int print_binaire(va_list arguments)
{
	/* Récupère le nombre à convertir en binaire depuis liste d'arguments */
	unsigned int binaire = va_arg(arguments, int);
	int counter = 0; /* Compteur de caractères affichés */
	char tab_binaire[33]; /* Tableau stocker chiffres binaires */
	int index = 0; /* Indice pour remplir le tableau */
	int i; /* Variable pour parcourir le tableau */

	/* Cas particulier : si le nombre est 0, on affiche directement '0' */
	if (binaire == 0)
	{
		_putchar('0');
		counter++;
	}

	/* Récupération des chiffres binaires et stockage dans tab_binaire */
	for (i = 0; binaire > 0; i++)
	{/* Récupère et stocke le dernier chiffre binaire */
		tab_binaire[index++] = binaire % 2;
		binaire = binaire / 2;
	} /* Divise le nombre par 2 pour éliminer le dernier chiffre */

	/* Affichage des chiffres binaires dans l'ordre correct */
	for (i = index - 1; i >= 0; i--) /* Parcourt le tableau à l'envers */
	{/* Convertit le chiffre binaire en caractère et l'affiche */
		_putchar('0' + tab_binaire[i]);
		counter++; /* Incrémente le compteur */
	}

	/* Retourne le nombre total de caractères affichés */
	return (counter);
}

/**
 * print_unsigned - Fonction affiche un entier non signé (unsigned int).
 * On divise un nombre par 10 dans système décimal pour extraire ses
 * chiffres, car chaque chiffre d'un nombre correspond à une puissance
 * de 10 (unités, dizaines, centaines, etc.). En utilisant modulo 10,
 * on récupère le dernier chiffre, et en divisant le nombre par 10, on
 * élimine ce chiffre pour répéter l'opération jusqu'à ce que tout le
 * nombre soit extrait. Diviser par 10 permet donc de traiter chaque
 * chiffre de droite à gauche, ce qui est propre à la base 10.
 * Base 10 (décimal) : Un tableau de taille 12 suffira pour un nombre
 * signé int de 32 bits (pour couvrir la plage de -2147483648 à 2147483647).
 * @arguments: Liste variadique contenant l'entier non signé à afficher.
 * Return: Counter pour le compteur des caractères affichés.
 */
int print_unsigned(va_list arguments)
{
	/* Récupère l'entier non signé depuis la liste d'arguments */
	unsigned int unsigned_int = va_arg(arguments, int);
	int counter = 0; /* Compteur de caractères affichés */
	char tab_unsigned_int[12]; /* Tableau pour stocker chiffres */
	int index = 0; /* Indice pour remplir le tableau */
	int i; /* Variable pour parcourir le tableau */

	/* Cas particulier : si l'entier est 0, on affiche directement '0' */
	if (unsigned_int == 0)
	{
		_putchar('0');
		counter++;
	}

	/* Récupération des chiffres et stockage dans tab_unsigned_int */
	for (i = 0; unsigned_int > 0; i++)
	{/* Récupère et stocke le dernier chiffre */
		tab_unsigned_int[index++] = unsigned_int % 10;
		unsigned_int = unsigned_int / 10;
	} /* Divise le nombre par 10 pour éliminer le dernier chiffre */

	/* Affichage des chiffres dans l'ordre correct */
	for (i = index - 1; i >= 0; i--) /* Parcourt le tableau à l'envers */
	{/* Convertit le chiffre en caractère et l'affiche */
		_putchar('0' + tab_unsigned_int[i]);
		counter++; /* Incrémente le compteur */
	}

	/* Retourne le nombre total de caractères affichés */
	return (counter);
}

/**
 * print_octal - Fonction qui transforme un nombre décimal en octal.
 * On divise un nombre par 8 dans le système octal pour extraire ses
 * chiffres, car chaque chiffre d'un nombre octal correspond à une
 * puissance de 8 (unités, huitaines, soixante-quatrièmes, etc.).
 * En utilisant modulo 8, on récupère le dernier chiffre, et en divisant
 * le nombre par 8, on élimine ce chiffre pour répéter l'opération
 * jusqu'à ce que tout le nombre soit extrait. Diviser par 8 permet
 * donc de traiter chaque chiffre dans l'ordre de droite à gauche,
 * ce qui est propre à la base 8.
 * Base 8 (octal) : Un tableau de taille 12 sera suffisant pour les
 * entiers non signés unsigned int de 32 bits.
 * @arguments: Liste variadique contenant le nombre à convertir.
 * Return: Counter pour le compteur des caractères affichés.
 */
int print_octal(va_list arguments)
{/* Récupère le nombre à convertir en octal depuis la liste d'arguments */

	unsigned int octal = va_arg(arguments, int);
	int counter = 0; /* Compteur de caractères affichés */
	char tab_octal[12]; /* Tableau stocker chiffres octaux */
	int index = 0; /* Indice pour remplir le tableau */
	int i; /* Variable pour parcourir le tableau */

	/* Cas particulier : si le nombre est 0, on affiche directement '0' */
	if (octal == 0)
	{
		_putchar('0');
		counter++;
	}

	/* Récupération des chiffres octaux et stockage dans tab_octal */
	for (i = 0; octal > 0; i++)
	{/* Récupère et stocke le dernier chiffre octal */
		tab_octal[index++] = octal % 8;
		octal = octal / 8;
	} /* Divise le nombre par 8 pour éliminer le dernier chiffre */

	/* Affichage des chiffres octaux dans l'ordre correct */
	for (i = index - 1; i >= 0; i--) /* Parcourt le tableau à l'envers */
	{/* Convertit le chiffre en caractère et l'affiche */
		_putchar('0' + tab_octal[i]);
		counter++; /* Incrémente le compteur */
	}

	/* Retourne le nombre total de caractères affichés */
	return (counter);
}
