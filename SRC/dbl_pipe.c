/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-42sh-amine.moussaoui
** File description:
** dbl_pipe.c
*/

#include "../include.h"

void check(char **tab, env_t *ANY, char *line);

int double_esp(char **tab, int i, env_t *ANY, char *line)
{
    char *str[20] = {0};
    tab[i] = NULL;
    i++;
    for (int e = 0; tab[i] != '\0'; e++, i++){
        str[e] = tab[i];
        tab[i] = NULL;
    }
    int verif = minishell(ANY, line, tab);
    if (verif == 0)
        check(str, ANY, line);
}

int double_pipe(char **tab, int i, env_t *ANY, char *line)
{
    char *str[20] = {0};
    tab[i] = NULL;
    i++;
    for (int e = 0; tab[i] != '\0'; e++, i++){
        str[e] = tab[i];
        tab[i] = NULL;
    }
    int verif = minishell(ANY, line, tab);
    if (verif != 0)
        check(str, ANY, line);
}
