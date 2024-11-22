/*
** EPITECH PROJECT, 2022
** oe
** File description:
** oe
*/

#include "../include.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int length = my_strlen(dest);
    for (i = 0; src[i] != 0; i++) {
        dest[length + i] = src[i];
    }
    dest[length + i] = '\0';
    return dest;
}
