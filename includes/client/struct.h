/*
** EPITECH PROJECT, 2021
** teams
** File description:
** struct
*/

#pragma once

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>

static volatile sig_atomic_t run = 1;

typedef struct client_s client_t;

typedef struct hostent hostent_t;

struct client_s
{
    int _in_use;
    int _socket_fd;
    int _length_address;
    char *_message;
    char *_uuid;
    char *_username;
    char **_commands;
    ssize_t _ip;
    sockaddr_in_t _address;
    bool _is_logged;
};

typedef enum cmd {
    NOP,
    CREATE_TEAM,
    CREATE_CHANNEL,
    LIST_TEAM,
    LIST_CHANNEL,
    SUB,
    UNSUB,
    SUBED,
    LOGOUT,
    MESSAGES,
    MESSAGE,
    USER,
    USERS,
    LOG,
    ERROR_500,
    ERROR_501,
    ERROR_502,
    ERROR_503
} cmd_e;

static const char *commands_name[] = {
    "100",
    "101",
    "102",
    "103",
    "104",
    "105",
    "106",
    "201",
    "300",
    "301",
    "302",
    "303",
    "304",
    "500",
    "501",
    "502",
    "503",
    NULL
};
