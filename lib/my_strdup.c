/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell1-amine.moussaoui
** File description:
** my_strdup.c
*/

#include "../include.h"

char* my_strdup(const char* str)
{
    char* dup;
    if (str == NULL)
        return NULL;
    dup = malloc(sizeof(char) * my_strlen(str) + 1);
    if (dup == NULL) {
        return NULL;
    }
    my_strcpy(dup, str);
    return dup;
}
