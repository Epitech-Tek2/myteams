/*
** EPITECH PROJECT, 2021
** teams
** File description:
** check_creation
*/

#include "server.h"

static bool check_team(server_client_t *_sclient, mstat_t *_file)
{
    my_strctok(_file, ';');
    for (int i = 0; i != _file->_length; i++)
        if (!strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(_sclient->_commands[1])))
            return true;
    return false;
}

bool is_team(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_TEAM, "r")});

    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        if (2 != i) continue;
        if (check_team(_sclient, file)) return true;
    }
    fclose(file->_file);
    free(file);
    return false;
}

static bool check_user_in_team(server_client_t *_sclient, mstat_t *_file)
{
    for (int i = 1; i != _file->_length; i++)
        if (!strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(_sclient->_commands[1]))) {
            fclose(_file->_file);
            return true;
        }
    return false;
}

bool is_user_in_team(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r"),
    ._count = -1});
    char *tmp = strdup("303;");

    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        if (2 != i) continue;
        my_strctok(file, ';');
        if (NULL != *file->_parse && 1 < file->_length &&
        !strcmp(parse_uuid(file->_parse[1]), "team") &&
        check_user_in_team(_sclient, file))
            return true;
    }
    fclose(file->_file);
    free(file);
    return false;
}