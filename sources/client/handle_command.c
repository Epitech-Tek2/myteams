/*
** EPITECH PROJECT, 2021
** teams
** File description:
** handle_command
*/

#include "client.h"

static commands get_command(str_const_restrict _any_command,
str_const_restrict _command)
{
    if (NULL == _any_command) return command[NOP];
    for (int i = 1; i != 18; ++i)
        if (!strcmp(_any_command, commands_name[i - 1])) return command[i];
    print((char *)_command);
    return command[NOP];
}

int handle_requested_command(client_t *_sclient, str_const_restrict _command)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    char **commands = NULL;
    int length = 0;

    *file = (mstat_t){._str = (char *)_command, ._count = 0};
    my_strctok(file, ';');
    commands = file->_parse;
    length = file->_length;
    free(file);
    if (NULL == commands) return -1;
    if (!strcmp(commands[0], "200") && !_sclient->_is_logged) {
        logging_user(_sclient, (char *)_command);
        return 0;
    }
    get_command(commands[0], _command)(_sclient, (arr_const_restrict)commands,
    _command, length);
}