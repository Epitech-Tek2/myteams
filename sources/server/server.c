/*
** EPITECH PROJECT, 2021
** teams
** File description:
** server
*/

#include <signal.h>
#include "server.h"
#include "../libs/includes/vector.h"

static int client_handling_process(list_serv *_sclient, server_t *_server)
{
    for (int i = 0; MAX_CLIENT > i; ++i)
        if (FD_ISSET(_sclient->valueofl(_sclient, i)->_socket_fd,
        &_server->_readfds) && 0 == get_client_command(_sclient, i))
            handle_client_command(_sclient, i);
}

static int server_process(list_serv *_sclient, server_t *_server)
{
    if (-1 == create_all_save_file()) return -1;
    signal(SIGINT, sig_action);
    if (-1 == load_registered_user()) return -1;
    while (run) {
        if (-1 == init_client(_sclient, _server)) continue;
        client_connection(_sclient, _server);
        client_handling_process(_sclient, _server);
    }
    return 0;
}

static void start_server(int const _socket_fd, sockaddr_in_t _s_addr,
int const _port)
{
    server_t *server = malloc(sizeof(server_t));
    list_serv *server_client = new_listl(NULL);
    int const max_sd = _socket_fd;
    int error = 0;

    for (int i = 0; MAX_CLIENT > i; ++i)
        server_client->push_backl(server_client, &server_client_init());
    if (0 != listen(_socket_fd, MAX_CLIENT)) {
        server_client->disposel(server_client);
        free(server);
        eraise();
    }
    *server = ((server_t){._fds = {0}, ._max_sd = max_sd, ._readfds = {0},
        ._socket_fd = _socket_fd});
    signal(SIGPIPE, SIG_IGN);
    error = server_process(server_client, server);
    free(server);
    if (-1 == error) eraise();
}

void create_server(int const _port)
{
    int const socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in_t s_addr = {0};

    if (MIN_PORT > _port || MAX_PORT < _port) uraise(INVALID_PORT);
    if (-1 == socket_fd) eraise();
    s_addr = (sockaddr_in_t){.sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_family = AF_INET, .sin_port = htons(_port)};
    if (-1 == setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &s_addr,
        sizeof(int)))
        eraise();
    if (-1 == bind(socket_fd, (sockaddr_t *)&s_addr, sizeof(s_addr))) eraise();
    start_server(socket_fd, s_addr, _port);
}