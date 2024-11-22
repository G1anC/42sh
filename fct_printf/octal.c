/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** octal.c
*/

#include "my_printf.h"

unsigned int octal(va_list list)
{
    int n = va_arg(list, int);
    int i = 0;
    int rest = 0;
    int r = 1;
    while (n != 0) {
        rest = n % 8;
        i = i + rest * r;
        n = n / 8;
        r = r * 10;
    }
    my_put_nbr(i);
}
