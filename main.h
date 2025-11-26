#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct specifier - Structure pour mapper un symbole à une fonction
 * @type: Le caractère (ex: 'c', 's', 'd')
 * @func: Le pointeur vers la fonction handler
 */
typedef struct specifier
{
	char type;
	int (*func)(va_list);
} specifier_t;

/* Fonction principale */
int _printf(const char *format, ...);

/* Fonction de base */
int _putchar(char c);

/* Fonctions "ouvriers" (Handlers) */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

#endif