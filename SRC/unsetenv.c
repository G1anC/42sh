/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell1-amine.moussaoui
** File description:
** unsetenv.c
*/

#include "../include.h"

char** cheking_big(env_t *ANY, int i, char **new)
{
    int r = 0;
    for (r = 0; r < i && ANY->env_new[r] != NULL; r++){
        new[r] = malloc(sizeof(char) * (my_strlen(ANY->env_new[r]) + 1));
        new[r] = my_strcpy(new[r], ANY->env_new[r]);
    }
    for (r = i + 1; ANY->env_new[r] != NULL; r++) {
        new[r - 1] = malloc(sizeof(char) * (my_strlen(ANY->env_new[r]) + 1));
        new[r - 1] = my_strcpy(new[r - 1], ANY->env_new[r]);
    }
    new[r - 1] = NULL;
    ANY->env_new = new;
}

int unsetenv_fct(env_t *ANY, char **tab)
{
    if (tab[1] == NULL){
        my_printf("unsetenv: Too few arguments.\n");
        return (ANY->state = 0);
    }
    int result, i = 0, a = 0;
    char **check;
    int len = count_tab(ANY->env_new);
    char **new = malloc(sizeof(char*) * (len + 2));
    while (i != len){
        check = transform_tab_unset(ANY->env_new[i]);
        result = my_strcmp(tab[1], check[0]);
        if (result == 0){
            a++;
            break;
        }
        i++;
    }
    if (a > 0)
        cheking_big(ANY, i, new);
    return (ANY->state = 0);
}
