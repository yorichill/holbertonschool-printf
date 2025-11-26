#include "main.h"

/**
 * _putchar - Écrit un caractère sur la sortie standard (fd 1)
 * @c: Le caractère à imprimer
 *
 * Return: 1 en cas de succès, -1 en cas d'erreur.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}