#include "main.h"

/**
 * print_char - Affiche un caractère
 * @args: Liste d'arguments
 * Return: 1
 */

int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Affiche une chaîne
 * @args: Liste d'arguments
 * Return: Nombre de caractères affichés
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

/**
 * print_percent - Affiche le symbole %
 * @args: Liste non utilisée
 * Return: 1
 */

int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_int - Affiche un entier
 * @args: Liste d'arguments
 * Return: Nombre de chiffres affichés
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	unsigned int div = 1;

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)-n;
	}
	else
		num = (unsigned int)n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}
	return (count);
}
