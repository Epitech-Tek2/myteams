/*
** EPITECH PROJECT, 2021
** teams
** File description:
** subscribe
*/

#include "server.h"

static void check_uuid(server_client_t *_sclient, int const _length,
mstat_t *_file, int const _i)
{
    for (int i = 0; i != _length; i++) {
        if (strcmp(_file->_parse[i], "uuid")) continue;
        if (!strcmp(parse_uuid(_file->_parse[1]),
        remove_quotes(_sclient->_commands[1])))
            _file->_count = _i + 2;
    }
}

static void check_name(server_client_t *_sclient, int const _length,
mstat_t *_file, int const _i)
{
    for (int i = 0; i != _length; i++) {
        if (strcmp(_file->_parse[i], "name")) continue;
        if (!strcmp(parse_uuid(_file->_parse[1]), _sclient->_username))
            _file->_count = _i + 3;
    }
}

static bool process_appening(server_client_t *_sclient, mstat_t *_file,
int const _line)
{
    append_client_data_in_save_file(SAVE_USER, _line,
    remove_quotes(_sclient->_commands[1]));
    _sclient->_team_uuid = NULL;
    fclose(_file->_file);
    return true;
}

static bool append_user_in_team(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r"),
    ._count = -1});

    if (NULL == file || NULL == file->_file) return -1;
    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        if (i == file->_count) return process_appening(_sclient, file, i);
        check_name(_sclient, file->_length, file, i);
    }
    return false;
}

static bool is_user_subscribed(server_client_t *_sclient, mstat_t *_file)
{
    for (int i = 0; i != _file->_length; i++)
        if (!strcmp(parse_uuid(_file->_parse[i]), _sclient->_username))
            return false;
    return false;
}

static bool process_subscribe(list_serv *_sclient, int const _id,
mstat_t *_file)
{
    dprintf(CCLIENT->_socket_fd, "104;%s;%s", CCLIENT->_uuid,
    remove_quotes(CCLIENT->_commands[1]));
    server_event_user_subscribed(remove_quotes(CCLIENT->_commands[1]),
    CCLIENT->_uuid);
    append_user_in_team(CCLIENT);
    fclose(_file->_file);
    return true;
}

static bool subscribe_process(list_serv *_sclient, int const _id)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_TEAM, "r+"),
    ._count = -1});

    if (NULL == file || NULL == file->_file) return -1;
    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        if (i == file->_count) return process_subscribe(_sclient, _id, file);
        check_uuid(CCLIENT, file->_length, file, i);
    }
    return false;
}

bool subscribe(list_serv *_sclient, int const _id, int const _length)
{
    if (2 != _length) client_message("invalid command");
    return subscribe_process(_sclient, _id);
}