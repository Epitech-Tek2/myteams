/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create
*/

#include "client.h"

bool create_channel(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_event_channel_created(_commands[1], _commands[2], _commands[3]);
    return 0;
}

bool create_team(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_event_team_created(_commands[1], _commands[2], _commands[3]);
    return 0;
}