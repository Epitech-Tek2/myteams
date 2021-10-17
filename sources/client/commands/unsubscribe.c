/*
** EPITECH PROJECT, 2021
** teams
** File description:
** unsubscribe
*/

#include "client.h"

bool unsub(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    client_print_unsubscribed(_commands[1], _commands[2]);
}