/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** task02
*/

#include "my_printf.h"

int my_putstr(va_list list)
{
    char const *str = va_arg(list, char*);
    for (int r = 0; str[r] != '\0'; r = r + 1)
        my_putchar(str[r]);
}

int my_putstrp(char const *str)
{
    for (int r = 0; str[r] != '\0'; r = r + 1)
        my_putchar(str[r]);
}
