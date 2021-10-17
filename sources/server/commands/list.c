/*
** EPITECH PROJECT, 2021
** teams
** File description:
** list
*/

#include "server.h"

static bool list_process(server_client_t *_sclient, bool is_team)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(is_team ? SAVE_TEAM :
    SAVE_CHANNEL, "r+"), ._count = -1});
    string *res = new_string(is_team ? "102;" : "103;");
    int i = 0;

    if (NULL == file || NULL == file->_file) return false;
    for (i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        if (my_exist(FDATA, file->_parse[1]) && (!strcmp(FDATA, is_team ?
        "name_team" : "name_channel") || !strcmp(FDATA, "uuid") ||
        !strcmp(FDATA, "description")))
            res->append(res, parse_uuid(file->_parse[1]))->append(res, ";");
    }
    (3 == i) ? dprintf(_sclient->_socket_fd, "anything available.") :
    dprintf(_sclient->_socket_fd, "%s", res->_value);
    fclose(file->_file);
    free(file);
    return false;
}

bool listt(list_serv *_sclient, int const _id, int const _length)
{
    if (!is_enought_arg(1, _length)) return false;
    return list_process(CCLIENT, !CCLIENT->_in_use ? true : false);
}