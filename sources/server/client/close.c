/*
** EPITECH PROJECT, 2021
** teams
** File description:
** close
*/

#include "server.h"

int clean_client_instance(list_serv *_sclient, int const _id)
{
    client_message("client logout");
    close(CCLIENT->_socket_fd);
    _sclient->valueofl(_sclient, _id)->_socket_fd = 0;
    _sclient->valueofl(_sclient, _id)->_is_logged = false;
    memset(&CCLIENT->_address, 0, sizeof(CCLIENT->_address));
    return 1;
}

void share_client_logout(list_serv *_sclient, int const _id)
{
    for (int i = 0; i != MAX_CLIENT; ++i) {
        if (_id != i && _sclient->valueofl(_sclient, i)->_is_logged)
            dprintf(_sclient->valueofl(_sclient, i)->_socket_fd,
            "201;%s;%s", CCLIENT->_username, CCLIENT->_uuid);
    }
}