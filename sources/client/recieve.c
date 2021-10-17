/*
** EPITECH PROJECT, 2021
** teams
** File description:
** recieve
*/

#include "client.h"

void logging_user(client_t *_sclient, char *_command)
{
    char **commands = my_strtok(_command, ";");
    char *username = commands[1];
    char *uuid = commands[2];

    client_event_logged_in(uuid, username);
    _sclient->_is_logged = true;
    _sclient->_uuid = uuid;
    _sclient->_username = username;
}

int recieving(client_t *_sclient)
{
    char buf[5024];
    size_t length = recv(_sclient->_socket_fd, buf, 1024 - 1, 0);

    if (-1 == length) eraise(_sclient);
    if (0 == length) {
        close(_sclient->_socket_fd);
        exit(0);
    }
    buf[length] = '\0';
    if (!strcmp(buf, "client logout.")) {
        if (_sclient->_is_logged)
            client_event_logged_out(_sclient->_uuid, _sclient->_username);
        close(_sclient->_socket_fd);
        free(_sclient);
        exit(0);
    }
    return handle_requested_command(_sclient, buf);
}