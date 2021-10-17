/*
** EPITECH PROJECT, 2021
** teams
** File description:
** handle
*/

#include <assert.h>
#include "server.h"
#include "../libs/includes/vector.h"

int get_client_command(list_serv *_sclient, int const _id)
{
    CCLIENT->_message = my_getline(CCLIENT->_socket_fd);
    if (NULL == CCLIENT->_message || !strcmp(CCLIENT->_message, "\r")) {
        free(CCLIENT->_message);
        return 1;
    }
    if (NULL == CCLIENT->_message) {
        if (CCLIENT->_is_logged) return logout(_sclient, _id);
        return clean_client_instance(_sclient, _id);
    }
    return 0;
}

void client_connection(list_serv *_sclient, server_t *_server)
{
    sockaddr_in_t client = {0};
    int new_socket = 0;
    socklen_t size = sizeof(client);

    if (!FD_ISSET(_server->_socket_fd, &_server->_readfds)) return;
    new_socket = accept(_server->_socket_fd, (sockaddr_t *)&client, &size);
    if (-1 == new_socket) {
        free(_server);
        eraise();
    }
    for (int _id = 0; MAX_CLIENT > _id; ++_id) {
        CCLIENT->_ip = client.sin_addr.s_addr;
        CCLIENT->_address = client;
        CCLIENT->_length_address = sizeof(client);
        if (0 == CCLIENT->_socket_fd) {
            _sclient->valueofl(_sclient, _id)->_socket_fd = new_socket;
            break;
        }
    }
}

int init_client(list_serv *_sclient, server_t *_server)
{
    FD_ZERO(&_server->_readfds);
    my_fd_set((*_server))
    _server->_max_sd = _server->_socket_fd;
    for (int i = 0; MAX_CLIENT > i; ++i) {
        if (_sclient->valueofl(_sclient, i)->_socket_fd)
            FD_SET(_sclient->valueofl(_sclient, i)->_socket_fd,
            &_server->_readfds);
        if (_sclient->valueofl(_sclient, i)->_socket_fd > _server->_max_sd)
            _server->_max_sd = _sclient->valueofl(_sclient, i)->_socket_fd;
    }
    if (-1 == my_select(_server->_max_sd + 1, &_server->_readfds))
        handle_select_error();
    return 0;
}