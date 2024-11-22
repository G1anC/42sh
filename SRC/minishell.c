/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** minishell.c
*/

#include "../include.h"

char** envp_cpy(char** envp)
{
    int i;
    char** copy = malloc(sizeof(char*) * (count_tab(envp) + 1));
    for (i = 0; envp[i]; i++)
        copy[i] = my_strdup(envp[i]);
    copy[i] = NULL;
    return copy;
}

int minishell_other(env_t *ANY, char *line, char **tab, int i)
{
    if (my_strcmp(tab[0], "exitt") == 0){
        i++;
        my_printf("%s: Command not found.\n", tab[0]);
        ANY->state = 1;
        return 1;
    }
    if (my_strcmp(tab[0], "unsetenv") == 0){
        i++;
        unsetenv_fct(ANY, tab);
    }
    if (my_strcmp(tab[0], "echo") == 0){
        i++;
        echo_function(tab, ANY);
    }
    if (i == 0)
        cmd_fct(tab, ANY);
    return (ANY->state);
}

int minishell(env_t *ANY, char *line, char **tab)
{
    int i = 0;
    if (my_strcmp(tab[0], "env") == 0){
        i++;
        env_fct(ANY);
    }
    if (my_strcmp(tab[0], "cd") == 0){
        i++;
        cd_fct(tab, ANY);
    }
    if (my_strcmp(tab[0], "setenv") == 0){
        i++;
        setenv_fct(ANY, tab);
    }
    if (my_strcmp(tab[0], "exit") == 0){
        i++;
        write(1, "exit\n", 5);
        exit(0);
    }
    minishell_other(ANY, line, tab, i);
    return (ANY->state);
}

char *cmd(char *line, int term, env_t *ANY)
{
    size_t len = 0;
    __ssize_t size;
    char *path = (char*) malloc(PATH * sizeof(char));
    if (term == 1){
        getcwd(path, PATH);
        my_printf("%s $> ", path);
        size = getline(&line, &len, stdin);
        ANY->path = path;
        if (size == -1)
            return "exit";
    }else {
        ANY->path = getcwd(path, PATH);
        size = getline(&line, &len, stdin);
        if (size == -1)
            exit(0);
    }
    return line;
}

int main(int argc, char **argv, char **env)
{
    char *line = "";
    env_t ANY;
    ANY.env_new = envp_cpy(env);
    int term = isatty(0);
    getcwd(ANY.old_path, PATH);
    while (1){
        line = cmd(&line, term, &ANY);
        if (my_strcmp(line, "exit") == 0){
            write(1, "exit\n", 5);
            break;
        }
        check_comma(&ANY, line);
    }
}
