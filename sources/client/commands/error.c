/*
** EPITECH PROJECT, 2021
** teams
** File description:
** error
*/

#include "client.h"

bool error_c(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length)
{
    return (
    !strcmp(*_commands, "500") ? client_error_unauthorized() :
    !strcmp(*_commands, "501") ? client_error_already_exist() :
    !strcmp(*_commands, "502") ? client_error_unknown_user(_commands[1]) :
    !strcmp(*_commands, "503") ? client_error_unknown_team(_commands[1]) :
    0);
}