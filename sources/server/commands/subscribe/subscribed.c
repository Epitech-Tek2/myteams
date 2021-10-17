/*
** EPITECH PROJECT, 2021
** teams
** File description:
** subscribed
*/

#include "server.h"

static int setup_search(server_client_t *_sclient, mstat_t *_file, string *res,
string *_concat)
{
    if (NULL == *_file->_parse) return -1;
    if (!strcmp(*_file->_parse, "name") || !strcmp(*_file->_parse, "uuid") ||
    !strcmp(*_file->_parse, "status"))
        _concat->append(_concat, parse_uuid(_file->_parse[1]), ";");
    if (!strcmp(parse_uuid(*_file->_parse), "team")) {
        for (int i = 1; i != _file->_length; i++)
            (void)((!strcmp(parse_uuid(_file->_parse[i]),
            remove_quotes(_sclient->_commands[1]))) &&
            res->append(res, _concat->_value));
        memset(_concat->_value, '\0', sizeof(_concat->_value));
    }
    return 0;
}

static void search_users_inteam(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r"),
    ._count = -1});
    string *res = new_string("302;");
    string *concat = new_string(NULL);

    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        setup_search(_sclient, file, res, concat);
    }
    dprintf(_sclient->_socket_fd, "%s", res->_value);
    fclose(file->_file);
}

bool subscribed(list_serv *_sclient, int const _id, int const _length)
{
    if (2 != _length) client_message("invalid command");
    if (!is_team(CCLIENT))
        client_message("503;%s", CCLIENT->_commands[1]);
    else search_users_inteam(CCLIENT);
}