/*
** EPITECH PROJECT, 2021
** teams
** File description:
** user_exist
*/

#include "server.h"

bool check_user(list_serv *_sclient, int const _id, mstat_t *_file)
{
    my_strctok(_file, ';');
    for (int i = 0; i != _file->_length; i++) {
        if (!strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(CCLIENT->_commands[1])) &&
        36 == strlen(remove_quotes(CCLIENT->_commands[1]))) {
            fclose(_file->_file);
            my_free_arr(_file->_parse);
            return true;
        }
    }
    return false;
}

bool user_exist(list_serv *_sclient, int const _id)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r+")});
    char line[5024];

    for (int i = 1; fgets(line, sizeof(line), file->_file); i++) {
        if (2 != i) continue;
        strcpy(file->_line, line);
        if (check_user(_sclient, _id, file)) return true;
    }
    fclose(file->_file);
    free(file);
    return false;
}