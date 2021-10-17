/*
** EPITECH PROJECT, 2021
** teams
** File description:
** subscribe
*/

#include "client.h"

bool sub(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_print_subscribed(_commands[1], _commands[2]);
}