/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_arraylen(char **array)
{
    int i;
    for (i = 0; array[i] != NULL; i++);
    return i;
}

int my_strlen(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
