/*
** EPITECH PROJECT, 2021
** teams
** File description:
** messages
*/

#include "client.h"

bool messages(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    char *ptr;

    client_private_message_print_messages(_commands[1], strtoul(_commands[3],
    &ptr, 10), _commands[2]);
}