/*
 * _printf.c
 * Implémentation simplifiée de _printf suivant ton flowchart:
 * - gère %c, %s, %%
 * - si format == NULL -> return -1
 * - si '%' en fin de chaîne -> return -1 (format incorrect)
 * - si specificateur inconnu -> affiche '%' puis le char (comme sur ton schéma)
 *
 * Toutes les fonctions internes retournent le nombre de caractères
 * écrits ou -1 en cas d'erreur.
 */

#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* write */
#include <stddef.h> /* NULL */

/* -------- Handlers (implémentés localement) -------- */

/**
 * print_char - imprime un caractère issu de va_list
 * @args: va_list contenant l'argument (promu en int)
 * Return: 1 (caractère écrit) ou -1 en cas d'erreur d'écriture
 */
static int print_char(va_list args)
{
    char c = (char)va_arg(args, int);

    if (write(1, &c, 1) != 1)
        return (-1);
    return (1);
}

/**
 * print_string - imprime une chaîne issue de va_list
 * @args: va_list contenant le pointeur char *
 * Return: nombre de caractères écrits ou -1 en cas d'erreur
 *
 * Comportement : si str == NULL -> affiche "(null)"
 */
static int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;
    int i;

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i] != '\0'; i++)
    {
        if (write(1, &s[i], 1) != 1)
            return (-1);
        count++;
    }
    return (count);
}

/**
 * print_percent - imprime un pourcentage littéral '%'
 * @args: non utilisé (présent pour signature)
 * Return: 1 ou -1
 */
static int print_percent(va_list args)
{
    (void)args;
    if (write(1, "%", 1) != 1)
        return (-1);
    return (1);
}

/* -------- Table de correspondance & recherche -------- */

/**
 * get_specifier_func - retourne le handler associé à un char de format
 * @c: caractère de spécification attendu
 * Return: pointeur vers la fonction handler ou NULL si introuvable
 *
 * La table est définie ici localement (dans ce fichier) — pas besoin d'un
 * fichier specifiers séparé.
 */
static int (*get_specifier_func(char c))(va_list)
{
    specifier_t table[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'\0', NULL}
    };
    int i;

    for (i = 0; table[i].type != '\0'; i++)
    {
        if (table[i].type == c)
            return (table[i].func);
    }
    return (NULL);
}

/* -------- Fonction publique _printf (logique du flowchart) -------- */

/**
 * _printf - version allégée de printf
 * @format: chaîne de format
 * Return: nombre de caractères imprimés ou -1 en cas d'erreur
 *
 * Étapes (correspond au flowchart) :
 * 1) Si format == NULL -> return -1
 * 2) Parcours caractère par caractère
 *    - si pas '%' -> write caractère et incrémenter compteur
 *    - si '%' -> examiner caractère suivant :
 *        a) fin de chaîne -> format incorrect -> return -1
 *        b) retrouver handler via get_specifier_func
 *           - si handler existant -> l'appeler et ajouter son retour
 *           - si handler NULL -> afficher '%' puis le caractère (conforme au flowchart)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int total = 0;
    int res;
    int (*func)(va_list);

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            if (write(1, &format[i], 1) != 1)
            {
                va_end(args);
                return (-1);
            }
            total++;
            i++;
            continue;
        }

        /* Nous avons rencontré un '%' */
        i++; /* avancer sur le caractère après '%' */

        /* cas: format se termine par '%' seul -> erreur selon schéma */
        if (format[i] == '\0')
        {
            va_end(args);
            return (-1);
        }

        /* chercher le handler correspondant */
        func = get_specifier_func(format[i]);

        if (func != NULL)
        {
            res = func(args);
            if (res == -1)
            {
                va_end(args);
                return (-1);
            }
            total += res;
        }
        else
        {
            /* specificateur inconnu: afficher '%' puis le caractère */
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
            total += 2;
        }
        i++;
    }

    va_end(args);
    return (total);
}
