/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** task02
*/

#include "../include.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int k = 0;
    if (n <= 0){
        return 0;
    }
    while ( k < n && k < my_strlen(src)){
    dest[k] = src[k];
    k++;
    }
    dest[k] = '\0';
    return dest;
}
