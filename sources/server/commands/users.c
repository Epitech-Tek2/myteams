/*
** EPITECH PROJECT, 2021
** teams
** File description:
** users
*/

#include "server.h"

static bool cmd_users(list_serv *_sclient, int const _id)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    string *res = new_string("303;");

    if (NULL == file) return false;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r+"), ._parse = NULL,
    ._count = -1, ._length = 0};
    if (NULL == file->_file) return false;
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        ++i;
        my_strctok(file, ';');
        if (my_exist(FDATA, file->_parse[1]) && (!strcmp(FDATA, "name") ||
        !strcmp(FDATA, "uuid") || !strcmp(FDATA, "status"))) {
            file->_parse[1][strlen(file->_parse[1]) - 1] = '\0';
            res->append(res, file->_parse[1])->append(res, ";");
        }
        my_free_arr(file->_parse);
    }
    client_message("%s", res->_value);
    fclose(file->_file);
    my_free(file);
    return true;
}

bool users(list_serv *_sclient, int const _id, int const _length)
{
    if (!is_enought_arg(1, _length)) return false;
    else return cmd_users(_sclient, _id);
}