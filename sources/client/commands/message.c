/*
** EPITECH PROJECT, 2021
** teams
** File description:
** message
*/

#include "client.h"

bool message(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_event_private_message_received(_commands[1], _commands[2]);
}