#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

/* Type pour lier un caractère de spécificateur à une fonction */
typedef int (*handler_t)(va_list);

/* Structure pour la table de spécificateurs */
typedef struct specifier
{
    char type;
    handler_t func;
} specifier_t;

/* Prototypes */
int _printf(const char *format, ...);

/* Fonctions gérées (handlers) et lookup */
int (*get_specifier_func(char c))(va_list);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
