/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** research.c
*/

#include "../include.h"

void check(char **tab, env_t *ANY, char *line);

int double_redir(char **tab, int i, env_t *ANY, char *line)
{
    int fd;
    int status = open(tab[i + 1], O_WRONLY | O_CREAT, S_IRUSR
    | S_IRGRP | S_IWGRP | S_IWUSR);
    if (status == -1){
        my_printf("%s: Permission denied.\n", tab[i + 1]);
        return (ANY->state = 1);
    }
    struct stat info;
    stat(tab[i + 1], &info);
    char* str = malloc(sizeof(char) * info.st_size);
    int file = open(tab[i + 1], O_RDONLY);
    read(file, str, info.st_size);
    fd = dup(1);
    dup2(status, 1);
    tab[i] = NULL;
    tab[i + 1] = NULL;
    my_printf("%s", str);
    minishell(ANY, line, tab);
    close(status);
    dup2(fd, 1);
}

int simple_redirect(char **tab, int i, env_t *ANY, char *line)
{
    int status = open(tab[i + 1], O_WRONLY | O_TRUNC);
    if (status == -1){
        my_printf("%s: No such file or directory.\n", tab[i + 1]);
        ANY->state = 1;
        return (1);
    }
    tab[i] = NULL;
    tab[i + 1] = NULL;
    minishell(ANY, line, tab);
}

int simple_redir(char **tab, int i, env_t *ANY, char *line)
{
    int fd;
    int status = open(tab[i + 1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR
    | S_IRGRP | S_IWGRP | S_IWUSR);
    if (status == -1){
        my_printf("%s: Permission denied.\n", tab[i + 1]);
        ANY->state = 1;
        return (1);
    }
    fd = dup(1);
    dup2(status, 1);
    tab[i] = NULL;
    tab[i + 1] = NULL;
    minishell(ANY, line, tab);
    close(status);
    dup2(fd, 1);
}

int check_redir(char **tab, env_t *ANY, char *line)
{
    int i = 0, check = 1;
    while (tab[i]){
        if (my_strcmp(tab[i], ">") == 0){
            check = 2;
            simple_redir(tab, i, ANY, line);
            return (ANY->state = 0);
        }
        if (my_strcmp(tab[i], ">>") == 0){
            check = 2;
            double_redir(tab, i, ANY, line);
            return (ANY->state = 0);
        }
        if (my_strcmp(tab[i], "<") == 0){
            check = 2;
            simple_redirect(tab, i, ANY, line);
            return (ANY->state = 0);
        }
        i++;
    }
    return check;
}

void check_comma(env_t *ANY, char *line)
{
    char *token;
    for (token = strtok(line, ";"); token != NULL; token = strtok(NULL, ";")) {
        char *command = malloc(sizeof(char) * my_strlen(token));
        command = token;
        char **tab = transform_tab(command);
        if (tab[0] != NULL && tab[0] != ' '){
            check(tab, ANY, line);
        }
    }
}
