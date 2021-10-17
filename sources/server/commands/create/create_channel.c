/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create_channel
*/

#include <uuid/uuid.h>
#include "server.h"

static int append_channel(list_serv *_sclient, int const _id)
{
    uuid_t binuuid = {0};
    char *uuid = malloc(37);
    FILE *file = NULL;
    char *channel_name = remove_quotes(CCLIENT->_commands[1]);
    char *channel_desc = remove_quotes(CCLIENT->_commands[2]);

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    append_client_data_in_save_file(SAVE_CHANNEL, 2, channel_name);
    append_client_data_in_save_file(SAVE_CHANNEL, 2, uuid);
    file = fopen(SAVE_CHANNEL, "a");
    fprintf(file, CHANNEL_DATA_LOG, channel_name, uuid, channel_desc,
    CCLIENT->_username);
    client_message("101;%s;%s;%s", uuid, channel_name,
    channel_desc);
    server_event_channel_created(uuid, channel_name, CCLIENT->_uuid);
    CCLIENT->_channel_uuid = strdup(uuid);
    free(uuid);
    fclose(file);
}

static bool split_data_channel(list_serv *_sclient, int const _id, int const _i,
mstat_t *_file)
{
    my_strctok(_file, ';');
    for (int i = 0; _file->_length != i; i++) {
        if (!strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(CCLIENT->_commands[1]))) {
            client_message("501");
            return false;
        }
    }
    return true;
}

static int check_channel_exist(list_serv *_sclient, int const _id,
int const _length)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    char line[5024];

    *file = (mstat_t){._file = fopen(SAVE_CHANNEL , "r"), ._length = 0};
    if (NULL == file) return -1;
    for (int i = 1; fgets(line, sizeof(line), file->_file); i++) {
        if (2 != i) continue;
        strcpy(file->_line, line);
        if (!split_data_channel(_sclient, _id, i, file)) return true;
    }
    fclose(file->_file);
    free(file);
    return 0;
}

int create_channel(list_serv *_sclient, int const _id, int const _length)
{
    int is_channel_exist = 0;

    if (check_channel_data_validity(CCLIENT)) {
        client_message(INVALID_ARG_CREATE);
        return 0;
    }
    is_channel_exist = check_channel_exist(_sclient, _id, _length);
    if (-1 == is_channel_exist) return -1;
    if (!is_channel_exist) append_channel(_sclient, _id);
}