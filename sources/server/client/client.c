/*
** EPITECH PROJECT, 2021
** teams
** File description:
** client
*/

#include "server.h"

static commands get_command(str_const_restrict _any_command)
{
    if (NULL == _any_command) return command[NOP];
    for (int i = 1; i != 12; ++i)
        if (!strcmp(_any_command, commands_name[i - 1])) return command[i];
    return command[NOP];
}

static int call_requested_command(list_serv *_sclient,
mstat_t *_stat, int const _id)
{
    int error = 0;

    if (!strcmp(CCLIENT->_commands[0], "/login")) {
        error = login_client(_sclient, _id);
        return error;
    }
    else if (CCLIENT->_is_logged && !strcmp(CCLIENT->_message, "/logout"))
        return logout(_sclient, _id);
    if (CCLIENT->_is_logged)
        get_command(CCLIENT->_commands[0])(_sclient, _id, _stat->_length);
    return 0;
}

static int process_requested_command(list_serv *_sclient,
int const _id, mstat_t *_stat)
{
    CCLIENT->_commands = _stat->_parse;
    if (check_cmd("/help")) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return help(_sclient, _id);
    }
    if (-1 == call_requested_command(_sclient, _stat, _id)) {
        my_free_arr(_stat->_parse);
        free( _stat);
        return -1;
    }
    my_free_arr(_stat->_parse);
    free( _stat);
    return 0;
}

int handle_client_command(list_serv *_sclient, int const _id)
{
    mstat_t *stat = malloc(sizeof(mstat_t));

    if (NULL == stat) return -1;
    if (strlen(CCLIENT->_message))
        CCLIENT->_message[strlen(CCLIENT->_message) - 1] = '\0';
    *stat = (mstat_t){._length = 0, ._parse = NULL};
    if (NULL == CCLIENT->_message) return 0;
    strcpy(stat->_line, CCLIENT->_message);
    my_strctok(stat, ' ');
    if (NULL == stat->_parse) {
        free(stat);
        return 1;
    }
    return process_requested_command(_sclient, _id, stat);
}