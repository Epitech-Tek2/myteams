/*
** EPITECH PROJECT, 2021
** teams
** File description:
** struct
*/

#pragma once

#include <signal.h>
#include "../../libs/includes/vector.h"
#include "../struct.h"

static volatile sig_atomic_t run = 1;

typedef struct server_s server_t;

typedef enum { FDS, READFDS } fds_t;

typedef bool (*commands)(list_serv *_sclient,
    int const _id, int const _length);

typedef enum cmd {
    NOP,
    USERS,
    USER,
    CREATE,
    MESSAGES,
    SEND,
    USE,
    LIST,
    INFO,
    SUBSCRIBE,
    SUBSCRIBED,
    UNSUBSCRIBE
} cmd_e;

static const char *commands_name[] = {
    "/users",
    "/user",
    "/create",
    "/messages",
    "/send",
    "/use",
    "/list",
    "/info",
    "/subscribe",
    "/subscribed",
    "/unsubscribe",
    NULL
};

struct server_s
{
    int _socket_fd;
    int _max_sd;
    fd_set _fds;
    fd_set _readfds;
};
