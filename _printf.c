#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - version simplifiée de printf suivant le flowchart fourni
 * @format: chaîne de format
 *
 * Return: nombre total de caractères imprimés, ou -1 en cas d'erreur
 *
 * Comportement:
 *  - retourne -1 si format == NULL
 *  - retourne -1 si un '%' est en fin de chaîne (format incorrect)
 *  - gère les spécificateurs : %c, %s, %%
 *  - si spécificateur inconnu -> imprime littéralement '%' suivi du caractère
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int printed_chars = 0;
    int res;
    int (*func)(va_list);

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++; /* avancer au spécificateur (ou à '\0') */

            /* cas : '%' en fin de chaîne -> format invalide */
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            /* récupérer la fonction correspondante au spécificateur */
            func = get_specifier_func(format[i]);

            if (func != NULL)
            {
                /* appel du handler */
                res = func(args);
                if (res < 0)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars += res;
            }
            else
            {
                /* spécificateur inconnu : imprimer '%' puis le caractère */
                if (write(1, "%", 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                if (write(1, &format[i], 1) != 1)
                {
                    va_end(args);
                    return (-1);
                }
                printed_chars += 2;
            }
        }
        else
        {
            /* caractère normal => affichage */
            if (write(1, &format[i], 1) != 1)
            {
                va_end(args);
                return (-1);
            }
            printed_chars++;
        }
        i++;
    }

    va_end(args);
    return (printed_chars);
}
