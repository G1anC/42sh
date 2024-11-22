/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** basic_fct.c
*/

#include "../include.h"


char *check_path(char **path, char **tab, env_t *ANY)
{
    struct stat buffer;
    struct stat status;
    for (int r = 1; path[r] != NULL; r++){
        my_strcat(path[r], "/");
        my_strcat(path[r], tab[0]);
        if (stat(path[r], &buffer) == 0)
            return (path[r]);
    }
    my_strcat(ANY->path, "/");
    my_strcat(ANY->path, tab[0]);
    if (stat(ANY->path, &status) == 0)
        return (ANY->path);
    return ("error");
}

char *research_path(env_t *ANY, char **tab)
{
    int len = count_tab(ANY->env_new);
    int n = 0;
    char **path = NULL;
    char *real_path;
    for (int i = 0; i != len; n++, i++){
        if (n != 0)
            n = 0;
        if (ANY->env_new[i][n] == 'P' && ANY->env_new[i][n + 1] == 'A'
        && ANY->env_new[i][n + 2] == 'T' && ANY->env_new[i][n + 3] == 'H'){
            path = transform_tab_path(ANY->env_new[i]);
        }
        if (path != NULL){
            real_path = check_path(path, tab, ANY);
            return real_path;
        }
    }
    return ("error");
}

int count_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL){
        i++;
    }
    return i;
}
