/*
** EPITECH PROJECT, 2021
** teams
** File description:
** user
*/

#include "client.h"

bool user(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_print_user(_commands[2], _commands[1], get_status(_commands[3]));
    return 0;
}