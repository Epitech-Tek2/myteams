/*
** EPITECH PROJECT, 2021
** teams
** File description:
** check_user_already_register
*/

#include "server.h"
#include "../libs/includes/string.h"

static bool check_user_already_register_file(mstat_t *_file, string *_username)
{
    for (int i = 0; _file->_length != i; ++i) {
        if (!_username->compare(_username, _file->_parse[i])) {
            fclose(_file->_file);
            my_free_arr(_file->_parse);
            free(_file);
            return true;
        }
    }
    return false;
}

int check_user_already_register(int const _line, string *_username)
{
    mstat_t *file = malloc(sizeof(mstat_t));

    if (NULL == file) return -1;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r+"), ._parse = NULL,
    ._count = -1, ._length = 0};
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        i++;
        if (_line != i) continue;
        my_strctok(file, ';');
        if (check_user_already_register_file(file, _username)) return 0;
    }
    fclose(file->_file);
    my_free_arr(file->_parse);
    free(file);
    return 1;
}