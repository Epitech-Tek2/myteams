/*
** EPITECH PROJECT, 2021
** teams
** File description:
** users
*/

#include "client.h"

bool users(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    for (int i = 1; i < _length; i += 3)
        client_print_users(_commands[i + 1], _commands[i],
        get_status(_commands[i + 2]));
    return 0;
}