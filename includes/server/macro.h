/*
** EPITECH PROJECT, 2021
** teams
** File description:
** macro
*/

#pragma once

#define handle_select_error() ({ \
    if (errno == EINTR) return -1; \
    else { \
        cvector_free(_sclient); \
        eraise(_server); \
    } \
})

#define my_fd_set(s) FD_SET(s._socket_fd, &_server->_readfds);
#define my_select(nfds, readfds) select(nfds, readfds, NULL, NULL, NULL)

#define server_client_init() (server_client_t){._message = NULL, \
._socket_fd = 0, ._is_logged = false, ._uuid = NULL, ._username = NULL}

#define check_cmd(cmd) ((!strcmp(CCLIENT->_message, cmd)) ? \
true : false)

#define check_team_data_validity(current_client) \
(MAX_NAME_LENGTH < strlen(current_client->_commands[1]) || \
MAX_DESCRIPTION_LENGTH < strlen(current_client->_commands[2]))

#define check_channel_data_validity(current_client) \
(MAX_NAME_LENGTH < strlen(current_client->_commands[1]) || \
MAX_DESCRIPTION_LENGTH < strlen(current_client->_commands[2]))

#define check_send_data_validity(current_client) \
(!strcmp(current_client->_commands[1], current_client->_uuid) || \
strlen(current_client->_commands[1]) > MAX_BODY_LENGTH)

#define set_default_use(clt) clt->_username = NULL; \
    clt->_channel_uuid = NULL; clt->_in_use = false;

#define error_user() ({ \
    client_message("501;%s", CCLIENT->_commands[1]); \
    false; \
})

#define error_unauthorize() ({ \
    client_message("500;%s", \
    remove_quotes(CCLIENT->_commands[1])); \
    false; \
})

#define is_enought_arg(nbr_needed, nbr) ({ \
    bool is_enought = false; \
    if (nbr_needed != nbr) { \
        client_message("Invalid number of arguments."); \
        is_enought = false; \
    } else is_enought = true; \
    is_enought; \
})
