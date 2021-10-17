/*
** EPITECH PROJECT, 2021
** teams
** File description:
** login
*/

#include <uuid/uuid.h>
#include "server.h"
#include "../libs/includes/string.h"

static int create_new_client(list_serv *_sclient, int const _id,
string const *_username)
{
    uuid_t binuuid;
    char *uuid = malloc(37);

    if (NULL == uuid) return -1;
    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    append_client_data_in_save_file(SAVE_USER, 2, _username->_value);
    append_client_data_in_save_file(SAVE_USER, 2, uuid);
    server_event_user_created(uuid, _username->_value);
    server_event_user_logged_in(uuid);
    CCLIENT->_is_logged = true;
    CCLIENT->_uuid = strdup(uuid);
    CCLIENT->_username = strdup(_username->_value);
    dprintf(CCLIENT->_socket_fd, "200;%s;%s", _username->_value, uuid);
    free(uuid);
    send_logs_to_client(_sclient, _id);
    add_new_client_to_save_file(_sclient, _id);
}

int login_client(list_serv *_sclient, int const _id)
{
    int user_exist = 0;
    int error = 0;
    string *username = CCLIENT->_commands[1] ?
    new_string(remove_quotes(CCLIENT->_commands[1])) : NULL;

    if (NULL == username) return -1;
    if (username->length(username) > MAX_NAME_LENGTH ||
    username->empty(username)) {
        client_message(INVALID_LOGIN);
        return -1;
    }
    user_exist = check_user_already_register(2, username);
    if (-1 == user_exist) return -1;
    if (user_exist == 1) {
        error = create_new_client(_sclient, _id, username);
        if (-1 == error) return -1;
    } else get_registered_user(_sclient, _id);
    username->dispose(username);
    return 0;
}