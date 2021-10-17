/*
** EPITECH PROJECT, 2021
** teams
** File description:
** send
*/

#include "client.h"

int sending(client_t *_sclient, char *_command)
{
    char **commands = get_command_parsed(_command, ' ');

    if (NULL == _command || !strcmp(_command, "") || NULL == commands) return 0;
    if ((!_sclient->_is_logged && strcmp(commands[0], "/login")) &&
    (!_sclient->_is_logged && strcmp(_command, "/help")))
        return client_error_unauthorized();
    if (!strcmp(_command, "/logout")) {
        dprintf(_sclient->_socket_fd, "%s\r\n", _command);
        if (_sclient->_is_logged)
            client_event_logged_out(_sclient->_uuid, _sclient->_username);
        close(_sclient->_socket_fd);
        free(_sclient);
        exit(0);
    }
    dprintf(_sclient->_socket_fd, "%s\r\n", _command);
    free(_command), _command = NULL;
}