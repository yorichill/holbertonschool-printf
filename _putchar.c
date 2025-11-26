#include "main.h"

/**
 * _putchar - Écrit un caractère sur la sortie standard
 * @c: Le caractère à imprimer
 * Return: 1 (succès), -1 (erreur)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
