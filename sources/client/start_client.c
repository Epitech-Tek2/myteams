/*
** EPITECH PROJECT, 2021
** teams
** File description:
** start_client.c
*/

#include <signal.h>
#include "client.h"

static client_t *init_client()
{
    client_t *client = malloc(sizeof *client);

    if (NULL == client) return NULL;
    *client = (client_t){._is_logged = false, ._username = NULL, ._uuid = NULL};
    return client;
}

static int client_process(client_t *_sclient)
{
    fd_set fds = {0};

    signal(SIGINT, sig_action);
    while (run) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(_sclient->_socket_fd, &fds);
        if (-1 == my_select(_sclient->_socket_fd, fds)) handle_select_error();
        if (FD_ISSET(STDIN_FILENO, &fds)) sending(_sclient, my_ngetline(0));
        else if (FD_ISSET(_sclient->_socket_fd, &fds)) recieving(_sclient);
    }
}

void start_client(char const *_av[])
{
    client_t *sclient = init_client();
    hostent_t *info = gethostbyname(*_av);
    sockaddr_in_t s_addr = {0};
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    int error = 0;

    if (NULL == info) eraise(sclient);
    s_addr = (sockaddr_in_t){.sin_addr.s_addr = inet_addr(_av[0]),
    .sin_family = AF_INET, .sin_port = htons(atoi(_av[1]))};
    if (0 != connect(socket_fd, (sockaddr_t *)&s_addr, sizeof(s_addr)))
        eraise(sclient, info);
    sclient->_socket_fd = socket_fd;
    error = client_process(sclient);
    free(sclient);
    return;
}
