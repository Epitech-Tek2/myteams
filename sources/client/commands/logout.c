/*
** EPITECH PROJECT, 2021
** teams
** File description:
** logout
*/

#include "client.h"

bool logout(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_event_logged_out(_commands[2], _commands[1]);
    return 0;
}