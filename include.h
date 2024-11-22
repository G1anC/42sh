/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** include.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <dirent.h>
    #define PATH 1000
    #define ENV ANY.env_new

    typedef struct env{
        char **env_new;
        char *path;
        int state;
        char *old_path;
    }env_t;

    int my_strlen(char const *str);
    char **transform_tab(char *map);
    int my_strcmp(char const *s1, char const *s2);
    int env_fct(env_t *ANY);
    int cd_fct(char **tab, env_t *ANY);
    int setenv_fct(env_t *ANY, char **tab);
    char *my_strcat(char *dest, char const *src);
    int cmd_fct(char **tab, env_t *ANY);
    int my_printf(const char* format, ...);
    char *check_path(char **path, char **tab, env_t *ANY);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    int count_tab(char **tab);
    char *research_path(env_t *ANY, char** tab);
    char **transform_tab_path(char *map);
    char **research_usr(char **tab, env_t *ANY);
    char **transform_tab_usr(char *map);
    char** string_split(char const * str, char* separator);
    int my_arraylen(char **array);
    int nbr_word_usr(char *map);
    int type_word_usr(char c);
    char* my_strdup(const char* str);
    int minishell_other(env_t *ANY, char *line, char **tab, int i);
    int unsetenv_fct(env_t *ANY, char **tab);
    char **transform_tab_unset(char *map);
    int alpha_num(char **tab);
    int it_is_file(struct stat buffer);
    void check_comma(env_t *ANY, char *line);
    int minishell(env_t *ANY, char *line, char **tab);
    int segv_fct(int status, env_t *ANY);
    extern int echo_function(char **argv, env_t *ANY);
    int double_pipe(char **tab, int i, env_t *ANY, char *line);
    int double_esp(char **tab, int i, env_t *ANY, char *line);
    char * my_strncat( char* dest , char* const src, int nb);
    int my_arrlen(char **array);
    char *env_var(char *str, env_t *ANY);
    int my_strncmp (char const *s1, char const *s2, int n);

#endif
