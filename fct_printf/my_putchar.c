/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** my_putchar.c
*/


#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putcharbis(void)
{
    write(1, "%", 1);
}

void my_putcharvg(va_list list)
{
    char c = va_arg(list, int);
    write(1, &c, 1);
}
