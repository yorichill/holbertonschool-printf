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
 * _putchar - écrit un caractère sur stdout
 * @c: caractère à écrire
 *
 * Retourne : 1 si succès (nombre d'octets écrits),
 *            -1 si erreur d'écriture.
 *
 * Note : fonction bas-niveau centralisée pour détecter les erreurs d'écriture.
 */
int _putchar(char c)
{
    if (write(1, &c, 1) != 1)
        return (-1);
    return (1);
}

/**
 * _puts - écrit une chaîne NUL-terminée sur stdout
 * @s: chaîne à écrire (si NULL, on affiche "(null)" par convention)
 *
 * Retourne : nombre total de caractères écrits, ou -1 si erreur d'écriture.
 *
 * Comportement :
 *  - si s == NULL on affiche "(null)" (comportement courant pour tests)
 *  - on utilise _putchar pour chaque caractère pour gérer les erreurs
 */

int _puts(const char *s)
{
    int count = 0;
    const char *p;

    if (s == NULL)
        p = "(null)";
    else
        p = s;

    while (*p)
    {
        if (_putchar(*p) < 0)
            return (-1);
        count++;
        p++;
    }
    return (count);
}
