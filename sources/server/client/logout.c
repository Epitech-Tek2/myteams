/*
** EPITECH PROJECT, 2021
** teams
** File description:
** logout
*/

#include "server.h"

int logout(list_serv *_sclient, int const _id)
{
    server_event_user_logged_out(CCLIENT->_uuid);
    share_client_logout(_sclient, _id);
    update_client_status(_sclient, _id, 0);
    CCLIENT->_is_logged = false;
    CCLIENT->_uuid = NULL;
    CCLIENT->_username = NULL;
    clean_client_instance(_sclient, _id);
    return 1;
}