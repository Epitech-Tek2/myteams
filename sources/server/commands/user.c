/*
** EPITECH PROJECT, 2021
** teams
** File description:
** user
*/

#include "server.h"

static void check_uuid(list_serv *_sclient, int const _id, mstat_t *_file,
bool *_check)
{
    for (int i = 0; i != _file->_length; i++)
        if (!strcmp(_file->_parse[0], "uuid")) {
            _file->_parse[1][strlen(_file->_parse[1]) - 1] = '\0';
            !strcmp(_file->_parse[1], CCLIENT->_commands[1]) ? *_check = 1 : 0;
        }
}

static bool search_user(list_serv *_sclient, int const _id,
string *_name)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    bool check = false;

    if (NULL == file) return false;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r+"), ._parse = NULL,
    ._count = -1, ._length = 0};
    if (NULL == file->_file) return false;
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        my_strctok(file, ';');
        if (check == true) {
            file->_parse[1][strlen(file->_parse[1]) - 1] = '\0';
            dprintf(CCLIENT->_socket_fd, "302;%s;%s;%s",
            CCLIENT->_commands[1], _name->_value, file->_parse[1]);
            fclose(file->_file);
            my_free_arr(file->_parse);
            free(file);
            return true;
        }
        check_uuid(_sclient, _id, file, &check);
        my_free_arr(file->_parse);
    }
}

static bool process_cmd_user(list_serv *_sclient, mstat_t *_file,
int const _id, string **_name)
{
    for (int n = 0; _file->_parse[n]; n++)
        if (!strcmp(parse_uuid(_file->_parse[n]), CCLIENT->_commands[1])
        && strlen(CCLIENT->_commands[1]) == 36) {
            *_name = new_string(_file->_parse[n - 1]);
            break;
        }
}

static void user_process(mstat_t *file, string *name, list_serv *_sclient,
int const _id)
{
    fclose(file->_file);
    !name->empty(name) ? search_user(_sclient, _id, name) :
    error_user();
    name->dispose(name);
    free(file);
}

bool user(list_serv *_sclient, int const _id, int const _length)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    string *name = new_string("", true);

    if (NULL == file) return false;
    if (!is_enought_arg(2, _length)) return false;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r+")};
    if (NULL == file->_file) return false;
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        if (i++ && i == 2) {
            my_strctok(file, ';');
            process_cmd_user(_sclient, file, _id, &name);
            my_free_arr(file->_parse);
        }
    }
    user_process(file, name, _sclient, _id);
    return true;
}