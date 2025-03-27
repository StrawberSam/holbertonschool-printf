/**
* Vérification de la validité de l'argument format si la chaîne `format`
* est `NULL`, la fonction retourne `-1`, ce qui indique une erreur.
*
* Parcours de la chaîne `format`
* La boucle parcourt chaque caractère de la chaîne jusqu'à ce qu'on atteigne
* la fin de celle-ci (`'\0'`).
* - Si le caractère actuel est un `%`, la fonction appelle `find_specifier`
* pour traiter le spécificateur de format.
* - Si ce n'est pas un `%`, le caractère est imprimé avec `_putchar` et le
* compteur `total_char` est incrémenté.
*
* Incrémentation de l'index `i`
* L'index `i` est incrémenté à chaque itération pour passer au caractère
* suivant dans la chaîne `format`.
*
* Retour du nombre total de caractères affichés
* La fonction retourne `total_char`, qui est le nombre de caractères
* effectivement imprimés.
*/



/**
 * Explication détaillée de la fonction `find_specifier` :
 *But de la fonction find_specifier :
*- Cherche un spécificateur dans la chaîne de format après '%'
*- Appelle la fonction appropriée pour afficher la valeur
*- Si aucun spécificateur valide, affiche '%<caractère>'
*Paramètres
*- format : Chaîne de format
*- i : Position dans la chaîne de format
*- args : Liste des arguments
*- total_char : Compteur de caractères affichés
*Retour
*- Retourne l'index mis à jour après traitement du spécificateur
 * La fonction `find_specifier` est appelée lorsqu'un caractère `%` est
 * rencontré dans la chaîne de format. Elle recherche le spécificateur
 * de format qui suit ce `%` et appelle la fonction correspondante.
 *
 * Un tableau `type[]` est utilisé pour associer chaque spécificateur à
 * sa fonction correspondante. Ce tableau contient des éléments de type
 * `type_function` qui lient un caractère (comme `c`, `s` ou `%`) à une
 * fonction d'impression appropriée.
 *
 * La fonction parcourt le tableau pour trouver une correspondance entre
 * le caractère actuel de `format[i]` et les éléments de `type[]`. Si
 * une correspondance est trouvée, la fonction correspondante est appelée
 * pour afficher le résultat, et le nombre total de caractères affichés
 * (`total_char`) est mis à jour.
 *
 * Si aucun spécificateur valide n'est trouvé, la fonction imprime
 * d'abord le caractère `%`, suivi du caractère actuel `format[i]`, ce
 * qui permet de gérer des spécificateurs inconnus comme `%x` (si `x`
 * n'est pas un spécificateur défini).
 *
 * La fonction retourne ensuite l'index `i` pour continuer à parcourir
 * la chaîne de format et traiter le prochain caractère.
 */



/**
 * La fonction `print_char` récupère un caractère de la liste
 * d'arguments variadiques et l'affiche à l'aide de `_putchar`.
 * Si l'affichage échoue, elle retourne -1. Sinon, elle retourne
 * 1 pour indiquer qu'un caractère a été imprimé.
 *
 * La fonction `print_string` récupère une chaîne de caractères
 * de la liste d'arguments et la parcourt caractère par caractère.
 * Chaque caractère est imprimé un par un avec `_putchar`. Si la
 * chaîne est `NULL`, elle est remplacée par la chaîne "(null)".
 * La fonction retourne le nombre total de caractères imprimés.
 *
 * La fonction `print_percent` est dédiée à l'impression du
 * caractère `%`. Elle ne prend aucun argument (l'argument
 * `arguments` est ignoré) et renvoie 1 si le caractère `%`
 * a été imprimé avec succès. Si l'affichage échoue, elle retourne -1.
 */


