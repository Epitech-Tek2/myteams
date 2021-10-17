/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** struct
*/

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef char const *restrict const *restrict arr_const_restrict;
typedef char const *restrict str_const_restrict;

typedef struct sockaddr_in sockaddr_in_t;
typedef struct sockaddr sockaddr_t;
typedef struct stat stat_t;

typedef struct save_file_s save_file_t;
typedef struct mstat_s mstat_t;
typedef struct tuple tuple;

struct save_file_s
{
    FILE *_file;
    bool _check;
    char _pass[255];
    stat_t _stat;
};

struct mstat_s
{
    FILE *_file;
    char *_str;
    int _count;
    int _length;
    char **_parse;
    char _line[2024];
};

struct tuple
{
    char _state;
    char _sep;
};