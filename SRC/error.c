/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-minishell1-amine.moussaoui
** File description:
** error.c
*/

#include "../include.h"

int it_is_file(struct stat buffer)
{
    if (S_ISREG(buffer.st_mode))
        return 0;
    else
        return 1;
}

int alpha_num(char **tab)
{
    char *ptr = tab[1];
    char *ptr_nbr = tab[1];
    while (*ptr != '\0'){
        if (!((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')
        || (*ptr >= '0' && *ptr <= '9'))){
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 1;
        }
        if (*ptr_nbr >= '0' && *ptr_nbr <= '9'){
            my_printf("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
        ptr++;
    }
}
