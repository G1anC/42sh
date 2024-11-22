/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell2-amine.moussaoui
** File description:
** segv.c
*/

#include "../include.h"

int segv_fct(int seg, env_t *ANY)
{
    if (WIFEXITED(seg) == 0) {
            my_printf("%s", strsignal(WTERMSIG(seg)));
        if (WCOREDUMP(seg) == 128){
            my_printf(" (core dumped)");
            ANY->state = 128;
        }
        my_printf("\n");
    }
}
