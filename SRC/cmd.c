/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** env.c
*/

#include "../include.h"

int cmd_fct(char **tab, env_t *ANY)
{
    char *chemin = malloc(sizeof(char) + 200);
    char *path = research_path(ANY, tab);
    if (my_strcmp(path, "error") == 0){
            my_printf("bash: %s: command not found.\n", tab[0]);
            ANY->state = 1;
            return (1);
    }
    my_strcpy(chemin, path);
    pid_t PID = fork();
    if (PID == 0)
        execve(chemin, tab, ANY->env_new);
    else {
        int seg;
        waitpid(PID, &seg, 0);
        ANY->state = 0;
        segv_fct(seg, ANY);
    }
}

char *new_str(char **tab)
{
    char *str_add;
    int nbr_arg = count_tab(tab);
    if (nbr_arg == 2){
        str_add = my_strcat(tab[1], "=");
        return (str_add);
    } else {
        str_add = my_strcat(tab[1], "=");
        char *str_v2 = my_strcat(str_add, tab[2]);
        return (str_v2);
    }
}

int setenv_fct(env_t *ANY, char **tab)
{
    if (tab[1] == NULL){
        env_fct(ANY);
    } else {
        alpha_num(tab);
        char *str_add = new_str(tab);
        int i = 0;
        int len = count_tab(ANY->env_new);
        char **new = malloc(sizeof(char*) * (len + 2));
        while (i != len){
            new[i] = malloc(sizeof(char) * (my_strlen(ANY->env_new[i]) + 1));
            new[i] = my_strcpy(new[i], ANY->env_new[i]);
            i++;
        }
        new[i] = malloc(sizeof(char) * (my_strlen(str_add) + 1));
        new[i] = my_strcpy(new[i], str_add);
        new[i + 1] = NULL;
        ANY->env_new = new;
        ANY->state = 0;
        return 0;
    }
}

int env_fct(env_t *ANY)
{
    for (int i = 0; ANY->env_new[i] != NULL; i++)
        my_printf("%s\n", ANY->env_new[i]);
    ANY->state = 0;
    return 0;
}

int cd_fct(char **tab, env_t *ANY)
{
    struct stat buffer;
    if (tab[1] == NULL){
        char **usr = research_usr(tab, ANY);
        chdir(usr[1]);
        return (ANY->state = 0);
    }
    if (!my_strcmp(tab[1], "-")) {
        chdir(ANY->old_path);
        return (ANY->state = 0);
    }
    ANY->old_path = ANY->path;
    char *path = malloc(sizeof(char) * my_strlen(tab[1]));
    my_strncpy(path, tab[1], my_strlen(tab[1]));
    if (chdir(path) == -1 && stat(path, &buffer) == -1){
        my_printf("%s: No such file or directory.\n", path);
        return (ANY->state = 1);
    } else if (it_is_file(buffer) == 0){
            my_printf("%s: Not a directory.\n", path);
            return (ANY->state = 1);
        }
}
