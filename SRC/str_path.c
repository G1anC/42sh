/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** transform_tab.c
*/

#include "../include.h"

int type_word_path(char c)
{
    if (c == ':' || c == '\n' || c == '\0' || c == '=')
        return (0);
    return (1);
}

int nbr_word_path(char *map)
{
    int r = 0;
    int x = 0;

    while (map != NULL && map[r]) {
        if (type_word_path(map[r]) == 1 && type_word_path(map[r + 1]) == 0)
            x++;
        r++;
    }
    return (x);
}

char **transform_tab_path(char *map)
{
    char **tab = malloc(sizeof(*tab) * (nbr_word_path(map) + 1));
    int j = 0;
    int r = 0;
    int i = 0;

    while (map != NULL && map[i]) {
        if (type_word_path(map[i]))
            j++;
        if (type_word_path(map[i]) == 1 && type_word_path(map[i + 1]) == 0) {
            tab[r] = malloc(j + 1);
            my_strncpy(tab[r], &map[i - j + 1], j);
            tab[r][j] = '\0';
            j = 0;
            r++;
        }
        i++;
    }
    tab[r] = 0;
    return (tab);
}
