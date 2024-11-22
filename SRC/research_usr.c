/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell1-amine.moussaoui
** File description:
** research_usr.c
*/

#include "../include.h"

int type_word_usr(char c)
{
    if (c == ' ' || c == '\n' || c == '\0' || c == '=')
        return (0);
    return (1);
}

int nbr_word_usr(char *map)
{
    int r = 0;
    int x = 0;

    while (map != NULL && map[r]) {
        if (type_word_usr(map[r]) == 1 && type_word_usr(map[r + 1]) == 0)
            x++;
        r++;
    }
    return (x);
}

char **transform_tab_usr(char *map)
{
    char **tab = malloc(sizeof(*tab) * (nbr_word_usr(map) + 1));
    int j = 0;
    int r = 0;
    int i = 0;

    while (map != NULL && map[i]) {
        if (type_word_usr(map[i]))
            j++;
        if (type_word_usr(map[i]) == 1 && type_word_usr(map[i + 1]) == 0) {
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

char **research_usr(char **tab, env_t *ANY)
{
    int len = count_tab(ANY->env_new);
    int n = 0;
    char **usr = NULL;
    for (int i = 0; i != len; n++, i++){
        if (n != 0)
            n = 0;
        if (ANY->env_new[i][n] == 'H' && ANY->env_new[i][n + 1] == 'O'
        && ANY->env_new[i][n + 2] == 'M' && ANY->env_new[i][n + 3] == 'E'){
            usr = transform_tab_usr(ANY->env_new[i]);
            return usr;
        }
    }
}
