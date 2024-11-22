/*
** EPITECH PROJECT, 2023
** echo.c
** File description:
** echo
*/

#include "../include.h"
#include <sys/types.h>
#include <dirent.h>

int is_existing(char *str, char c)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

static void echo_star(void)
{
    struct dirent *x;
    DIR *dh = opendir(".");

    while ((x = readdir(dh)) != NULL) {
        if (x->d_name[0] != '.')
            my_printf("%s", x->d_name);
    } my_printf("\n");
    closedir(dh);
    return;
}

static char find_replacement(char *c)
{
    if (*c == 'v') return '\v';
    if (*c == 't') return '\t';
    if (*c == 'n') return '\n';
    if (*c == 'r') return '\r';
    if (*c == 'f') return '\f';
    if (*c == 'a') return '\a';
    if (*c == 'b') return '\b';
    if (*c == '0') return '\0';
    if (*c == '?') return '\?';
    if (*c == 'e') return '\e';
    return *c;
}

static char *monsieur_propre(char *arg)
{
    int i = 0, j = 0, x = 0, checker = 0;
    char *clean = malloc(sizeof(char) * (my_strlen(arg) + 1)), *str = arg;
    char tmp[600];

    while (*str != '\0') {
        if (*str == '\"') {
            str++;
            continue;
        } if (*str == '\\') {
            clean[x++] = find_replacement(++str);
            str++;
            continue;
        } my_strncat(clean, str++, 1);
        x++;
    } clean[x++] = '\0';
    return my_strdup(clean);
}

extern int echo_function(char **argv, env_t *ANY)
{
    char *str = "", *tmp = "";
    if (my_arrlen(argv) == 1) {
        my_printf("\n");
        ANY->state = 0;
        return 0;
    } for (int i = 1; argv[i]; i++) {
        if (argv[i][0] == '$')
            argv[1] = env_var(argv[i], ANY);
        if (-1 != is_existing(argv[i], '*')) {
            echo_star();
            continue;
        } if (-1 != is_existing(argv[i], '\"'))
            my_printf("%s", monsieur_propre(argv[i]));
        else
            my_printf("%s", argv[i]);
    } my_printf("\n");
    return (ANY->state = 0);
}
