/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** hexadecimal.c
*/

#include "my_printf.h"

unsigned int hexadecimal(va_list list)
{
    int nb = va_arg(list, int);
    char place[100000];
    int i = 0;
    while (nb > 0) {
        int rest = nb % 16;
        if (rest < 10)
            place[i] = '0' + rest;
        else
            place[i] = 'a' + (rest - 10);
        nb = nb / 16;
        i++;
    }
    while (i--) {
        my_putchar(place[i]);
    }
}

unsigned int hexadecimal_upp(va_list list)
{
    int nb = va_arg(list, int);
    char place[100000];
    int i = 0;
    while (nb > 0){
        int rest = nb % 16;
        if (rest < 10)
            place[i] = '0' + rest;
        else
            place[i] = 'A' + (rest - 10);
        nb = nb / 16;
        i++;
    }
    while (i--) {
        my_putchar(place[i]);
    }
}
