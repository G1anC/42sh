/*
** EPITECH PROJECT, 2022
** Delivery
** File description:
** mini_fct.c
*/

int check_if(char **tab, int i, int j, int check)
{
    if (tab[i][j] == ';'){
        check++;
    }
    return check;
}
