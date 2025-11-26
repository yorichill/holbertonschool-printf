#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct specifier
{
    char type;
    int (*func)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *s);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);

#endif
