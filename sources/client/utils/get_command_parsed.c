/*
** EPITECH PROJECT, 2021
** teams
** File description:
** get_command_parsed
*/

#include "client.h"

char **get_command_parsed(str_const_restrict _command, char const _sep)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    char **commands = NULL;

    *file = (mstat_t){._str = (char *)_command, ._count = 0};
    my_strctok(file, _sep);
    commands = file->_parse;
    free(file);
    return commands;
}