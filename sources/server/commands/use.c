/*
** EPITECH PROJECT, 2021
** teams
** File description:
** use
*/

#include "server.h"

static bool check_uuid(server_client_t *_sclient, mstat_t *_file)
{
    for (int i = 0; i != _file->_length; i++)
        if (!strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(_sclient->_commands[2]))) {
            fclose(_file->_file);
            free(_file);
            return true;
        }
    return false;
}

static bool is_channel(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r"),
    ._count = -1});
    char line[5024];

    for (int i = 1; fgets(line, sizeof(line), file->_file); i++) {
        if (i != 2) continue;
        my_strctok(file, ';');
        if (check_uuid(_sclient, file)) return true;
    }
    fclose(file->_file);
    free(file);
    return false;
}

static bool check_length_tree(server_client_t *_sclient)
{
    if (is_team(_sclient) && is_user_in_team(_sclient) &&
    is_channel(_sclient)) {
        _sclient->_in_use = 2;
        _sclient->_team_uuid = strdup(_sclient->_commands[1]);
        _sclient->_channel_uuid = strdup(_sclient->_commands[2]);
        dprintf(_sclient->_socket_fd, "500");
    }
    return true;
}

bool use(list_serv *_sclient, int const _id, int const _length)
{
    if (1 == _length) {
        set_default_use(CCLIENT);
        return true;
    }
    if (2 == _length) {
        if (is_team(CCLIENT)) {
            CCLIENT->_team_uuid = strdup(remove_quotes(CCLIENT->_commands[1]));
            CCLIENT->_in_use = true;
        } else return error_unauthorize();
        return true;
    }
    if (3 == _length) return check_length_tree(CCLIENT);
    return false;
}