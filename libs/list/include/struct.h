/*
** EPITECH PROJECT, 2021
** teams
** File description:
** struct
*/

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;

typedef struct list list;
typedef struct list_serv list_serv;

typedef struct server_client_s server_client_t;

typedef struct metadata_s metadata_list;
typedef struct metadata_ss metadata_listl;

struct metadata_s {
    list *_next;
    list *_prev;
    list *_first;
    list *_last;
    bool _fnone;
};

struct metadata_ss {
    list_serv *_next;
    list_serv *_prev;
    list_serv *_first;
    list_serv *_last;
    bool _fnone;
};

struct list {
    char *_value;
    list *(*push_back)(list *_this, char *_value);
    size_t (*size)(list *_this);
    char *(*valueof)(list *_this, size_t const _i);
    void (*ldispose)(list *_this);
    list *(*end)(list *_this);
    char **(*copy)(list *_this);
    metadata_list __metadata;
};

struct list_serv {
    server_client_t *_value;
    list_serv *(*push_backl)(list_serv *_this, server_client_t *_value);
    size_t (*sizel)(list_serv *_this);
    server_client_t *(*valueofl)(list_serv *_this, size_t const _i);
    void (*disposel)(list_serv *_this);
    list_serv *(*endl)(list_serv *_this);
    metadata_listl __metadata;
};

struct server_client_s
{
    int _in_use;
    int _socket_fd;
    int _length_address;
    char *_message;
    char *_uuid;
    char *_team_uuid;
    char *_channel_uuid;
    char *_username;
    char **_commands;
    ssize_t _ip;
    sockaddr_in_t _address;
    bool _is_logged;
};