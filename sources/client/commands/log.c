/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log
*/

#include "client.h"

bool logs(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_event_logged_in(_commands[2], _commands[1]);
    return 0;
}