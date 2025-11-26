#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len, len2;

    /* Test String & Char */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Len:[%d, %i]\n", len, len2);

    /* Test Int et Négatif */
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

    /* Test Character */
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    /* Test String */
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    /* Test Percent */
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);

    return (0);
}