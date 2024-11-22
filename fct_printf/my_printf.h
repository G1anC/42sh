/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** my_printf.h
*/

int my_printf(const char* format, ...);

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>

    unsigned int hexadecimal(va_list list);
    unsigned int hexadecimal_upp(va_list list);
    unsigned int binaire(va_list list);
    signed int my_put_nbrbis(va_list list);
    unsigned int my_put_nbrun(va_list list);
    void my_putcharbis(void);
    void my_putcharvg(va_list list);
    int my_putstr(va_list list);
    unsigned int octal(va_list list);
    void adress(va_list list);
    void my_putchar(char c);
    int my_putstrp(char const *str);
    int my_put_nbr(int nb);
    ssize_t write(int fd, const void *buf, size_t count);

#endif
