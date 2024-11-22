/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** my_printf.c
*/

#include "my_printf.h"

int research(const char* format, int n, va_list list)
{
    n++;
    char tab[] = {'d', 'i', 's', 'c', '%', 'b', 'o', 'u', 'x', 'X', 'p', '\0'};
    int (*func[11])(va_list) = {my_put_nbrbis, my_put_nbrbis,
    my_putstr, my_putcharvg, my_putcharbis, binaire, octal,
    my_put_nbrun, hexadecimal, hexadecimal_upp, adress};
    int i = 0;
    while ( tab[i] != '\0'){
        if (tab[i] == format[1]){
            func[i](list);
        }
        i++;
    }
    return n;
}

int my_printf(const char* format, ...)
{
    int n = 0;
    va_list list;
    va_start(list, format);
    while (format[n] != '\0'){
        if (format[n] == '%') {
            n = research(&format[n], n, list);
        } else{
            my_putchar(format[n]);
        }
        n++;
    }
    va_end(list);
    return 0;
}
