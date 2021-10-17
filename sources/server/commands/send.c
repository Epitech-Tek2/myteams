/*
** EPITECH PROJECT, 2021
** teams
** File description:
** send
*/

#include "time.h"
#include "server.h"

static void check_uuid(server_client_t *_sclient, mstat_t *_file, int const _i)
{
    for (int i = 0; i != _file->_length; i++)
        if (!strcmp(_file->_parse[i], "uuid"))
            if (!strcmp(parse_uuid(_file->_parse[1]),
            remove_quotes(_sclient->_commands[1])))
                _file->_count = (_i + 3);
}

static int append_f(server_client_t *_sclient, mstat_t *_file)
{
    append_client_data_in_save_file(SAVE_USER, _file->_count, _sclient->_uuid);
    append_client_data_in_save_file(SAVE_USER, _file->_count,
    remove_quotes(_sclient->_commands[2]));
    append_client_data_in_save_file(SAVE_USER, _file->_count,
    my_itoa((int)time(NULL)));
    my_free_arr(_file->_parse);
    fclose(_file->_file);
    free(_file);
    return 0;
}

static int append_message_in_file(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r+"),
    ._count = -1});

    if (NULL == file || NULL == file->_file) return false;
    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        if (i == file->_count) return append_f(_sclient, file);
        check_uuid(_sclient, file, i);
    }
    return 1;
}

static int send_message(list_serv *_sclient, int const _id)
{
    server_event_private_message_sent(CCLIENT->_uuid,
    remove_quotes(CCLIENT->_commands[1]), remove_quotes(CCLIENT->_commands[2]));
    for (int i = 0; i != MAX_CLIENT; i++) {
        if (i != _id && ICCLIENT->_is_logged &&
        !strcmp(remove_quotes(CCLIENT->_commands[1]), ICCLIENT->_uuid)) {
            dprintf(ICCLIENT->_socket_fd, "301;%s;%s", CCLIENT->_uuid,
            remove_quotes(CCLIENT->_commands[2]));
        }
    }
}

bool sender(list_serv *_sclient, int const _id, int const _length)
{
    if (!is_enought_arg(3, _length)) return false;
    if (!user_exist(_sclient, _id)) {
        error_user();
        return false;
    }
    if (check_send_data_validity(CCLIENT)) return error_unauthorize();
    send_message(_sclient, _id);
    return append_message_in_file(CCLIENT);
}