/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** octal.c
*/

#include "my_printf.h"

unsigned int binaire(va_list list)
{
    int n = va_arg(list, int);
    int tab[10];
    int i = 0;
    while ( n > 0){
        tab[i] = n % 2;
        n = n / 2;
        i++;
    }
    i = i - 1;
    while (i >= 0){
        my_put_nbr(tab[i]);
        i--;
    }
}
