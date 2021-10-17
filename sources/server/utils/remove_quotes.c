/*
** EPITECH PROJECT, 2021
** teams
** File description:
** remove_quotes
*/

#include "server.h"

char *remove_quotes(str_const_restrict _string)
{
    char *username_cpy = strdup(_string);

    username_cpy++;
    username_cpy[strlen(username_cpy) - 1] = '\0';
    return username_cpy;
}