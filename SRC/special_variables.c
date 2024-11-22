/*
** EPITECH PROJECT, 2023
** tools.c
** File description:
** tools
*/

#include "../include.h"
#include <stdbool.h>

int my_arrlen(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (; array[i]; i++);
    return i;
}

char *spe_var(char *str, env_t *ANY)
{
    int i = 0;
    char tmp[500], *result = NULL;
    if (!my_strncmp(str, "?", 1) || !my_strncmp(str, "status", 6)) {
        sprintf(tmp, "%d", ANY->state);
        result = my_strdup(tmp);
    } if (!my_strncmp(str, "cwd", 3))
        result = my_strdup(getcwd(tmp, 500));
    if (!my_strncmp(str, "oldpwd", 6))
        result = my_strdup(ANY->old_path);
    if (!result) {
        my_printf("%s: Undefined variable.\n", str);
        ANY->state = 1;
    } return result;
}

char *env_var(char *str, env_t *ANY)
{
    char **env = ANY->env_new, *tmp = &str[1], *result = NULL;

    for (int x = 0; env[x]; x++)
        if (!my_strncmp(env[x], tmp, my_strlen(tmp)))
            result = my_strdup(&env[x][(my_strlen(tmp) + 1)]);
    return (result) ? result : spe_var(&str[1], ANY);
}
