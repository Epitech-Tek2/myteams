/*
** EPITECH PROJECT, 2021
** teams
** File description:
** messages
*/

#include "server.h"

static void check_uuid(server_client_t *_sclient, int const _length,
mstat_t *_file, int const _i)
{
    for (int i = 0; i != _length; i++) {
        if (strcmp(_file->_parse[i], "uuid")) continue;
        if (!strcmp(parse_uuid(_file->_parse[1]), _sclient->_uuid))
            _file->_count = _i + 3;
    }
}

static void process_display(list_serv *_sclient, int const _id, mstat_t *_file)
{
    bool check = false;

    for (int i = 0; i != _file->_length; i++) {
        if (!strcmp(_file->_parse[i], remove_quotes(CCLIENT->_commands[1]))) {
            client_message(MESSAGES_DATA_LOG, _file->_parse[i],
            _file->_parse[i + 1], _file->_parse[i + 2]);
            check = true;
            i += 2;
        }
        usleep(200);
    }
    !check ? error_user() :
    0;
}

static int display_messages(list_serv *_sclient, int const _id,
int const _length)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r+"),
    ._count = -1});

    if (NULL == file || NULL == file->_file) return -1;
    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        if (i == file->_count) process_display(_sclient, _id, file);
        check_uuid(CCLIENT, file->_length, file, i);
    }
}

bool messages(list_serv *_sclient, int const _id, int const _length)
{
    if (!is_enought_arg(2, _length)) return false;
    if (!user_exist(_sclient, _id)) error_user();
    if (-1 == display_messages(_sclient, _id, _length)) return false;
    return true;
}