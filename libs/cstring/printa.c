/*
** EPITECH PROJECT, 2021
** teams
** File description:
** printa
*/

#include "include/cstring.h"

void printa(char **_arr)
{
    for (int i = 0; _arr[i]; ++i) printf("%s\n", _arr[i]);
}