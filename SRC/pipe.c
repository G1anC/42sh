/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell2-amine.moussaoui
** File description:
** pipe.c
*/

#include "../include.h"

int check_redir(char **tab, env_t *ANY, char *line);
int check_pipe(char **tab, env_t *ANY, char *line);

void check(char **tab, env_t *ANY, char *line)
{
    if (check_redir(tab, ANY, line) == 1
    && check_pipe(tab, ANY, line) == 1)
        minishell(ANY, line, tab);
}

void my_pipe(char **tab, char **str, env_t* ANY, char *line)
{
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        minishell(ANY, line, tab);
        exit(0);
    }
    pid = fork();
    if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        minishell(ANY, line, str);
        exit(0);
    }
    close(fd[1]); close(fd[0]);
    waitpid(pid, NULL, 0);
}

void alloc_str_type(char **tab, int i, env_t *ANY, char *line)
{
    char *str[20] = {0};
    tab[i] = NULL;
    i++;
    for (int e = 0; tab[i] != '\0'; e++, i++){
        str[e] = tab[i];
        tab[i] = NULL;
    }
    my_pipe(tab, str, ANY, line);
    return 0;
}

int check_pipe(char **tab, env_t *ANY, char *line)
{
    int i = 0, check = 1;

    while (tab[i]) {
        if (my_strcmp(tab[i], "||") == 0) {
            check = 2;
            double_pipe(tab, i, ANY, line);
            break;
        }
        if (my_strcmp(tab[i], "&&") == 0) {
            check = 2;
            double_esp(tab, i, ANY, line);
            break;
        }
        if (my_strcmp(tab[i], "|") == 0) {
            check = 2;
            alloc_str_type(tab, i, ANY, line);
        }
        i++;
    }
    return check;
}
