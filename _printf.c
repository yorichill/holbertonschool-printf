/* _printf.c
 * Implémentation simplifiée de _printf qui gère : %c, %s et %%
 *
 * Contrainte : fichier compatible avec -std=gnu89 (déclarations en tête de bloc).
 */

#include "main.h"    /* contient le prototype de _printf et autres helpers */
#include <stdarg.h>
#include <unistd.h>  /* pour write */
#include <stddef.h>  /* pour NULL */


/**
* _printf - Réplique simplifiée de printf
* @format: Chaîne contenant du texte + directives de formatage
*
* Return: Nombre total de caractères imprimés, ou -1 en cas d'erreur
*/
int _printf(const char *format, ...)
{
va_list args; /* Liste des arguments variables */
int i = 0; /* Index dans la chaîne format */
int printed_chars = 0; /* Compteur de caractères imprimés */
int result; /* Résultat d'un handler */


/* Vérification que format n'est pas NULL */
if (format == NULL)
return (-1);


va_start(args, format); /* Initialisation de la liste variadique */


while (format[i] != '
␀
') /* Parcours de la chaîne */
{
if (format[i] == '%') /* Si on détecte une directive */
{
i++; /* On passe au caractère suivant qui indique le type */


if (format[i] == '
␀
')
{
va_end(args);
return (-1); /* Format incorrect comme "%" seul */
}


/* Rechercher la fonction correspondant au type */
int (*func)(va_list) = get_specifier_func(format[i]);


if (func != NULL)
{
/* Appel de la fonction qui gère ce format */
result = func(args);


if (result == -1)
{
va_end(args);
return (-1);
}
printed_chars += result;
}
else
{
/* Spécificateur inconnu : on affiche "%x" tel quel */
write(1, "%", 1);
write(1, &format[i], 1);
printed_chars += 2;
}
}
else
{
/* Sinon on imprime le caractère normalement */
write(1, &format[i], 1);
printed_chars++;
}
i++;
}


va_end(args); /* Libération de la liste variadique */
return (printed_chars);
}
