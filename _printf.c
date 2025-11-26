#include "main.h"

/**
 * get_op - Sélectionne la fonction correspondant au caractère
 * @c: Le caractère specifier
 * Return: Pointeur vers la fonction ou NULL
 */

int (*get_op(char c))(va_list)
{
	specifier_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};
	int i = 0;

	while (specs[i].type)
	{
		if (specs[i].type == c)
			return (specs[i].func);
		i++;
	}
	return (NULL);
}

/**
 * _printf - Fonction principale
 * @format: Chaîne de format
 * Return: Nombre de caractères imprimés
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*f)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		if (format[i + 1] == '\0')
			return (-1);

		f = get_op(format[i + 1]);
		if (f)
		{
			count += f(args);
			i += 2;
		}
		else
		{
			count += _putchar('%');
			if (format[i + 1] != '%')
				count += _putchar(format[i + 1]);
			i += (format[i + 1] == '%') ? 1 : 2; /* Correction subtile pour %% */
		}
	}
	va_end(args);
	return (count);
}
