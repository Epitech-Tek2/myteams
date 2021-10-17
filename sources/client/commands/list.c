/*
** EPITECH PROJECT, 2021
** teams
** File description:
** list
*/

#include "client.h"

bool listt(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    if (!strcmp(*_commands, "102"))
        for (int i = 2; i < _length; i += 3)
            client_print_team(_commands[i + 1], _commands[i], _commands[i + 2]);
    if (!strcmp(*_commands, "103"))
        for (int i = 2; i < _length; i += 3)
            client_print_channel(_commands[i + 1], _commands[i],
            _commands[i + 2]);
    return true;
}