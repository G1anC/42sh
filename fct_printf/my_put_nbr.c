/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my_printf.h"

signed int my_put_nbr_s(int nb)
{
    int debut;
    int fin;
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else {
        fin = nb % 10;
        debut = nb / 10;
        if (debut != 0)
            my_put_nbr(debut);
        my_putchar(fin + '0');
    }
}

int my_put_nbr(int nb)
{
    int debut;
    int fin;
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    } else {
        fin = nb % 10;
        debut = nb / 10;
        if (debut != 0)
            my_put_nbr(debut);
        my_putchar(fin + '0');
    }
}

signed int my_put_nbrbis(va_list list)
{
    int nb = va_arg(list, int);
    my_put_nbr_s(nb);
}

unsigned int my_put_nbrun(va_list list)
{
    int nb = va_arg(list, int);
    my_put_nbr(nb);
}
