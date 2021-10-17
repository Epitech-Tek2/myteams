/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** macro
*/

#pragma once

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define cOut(message) printf("%s\n", message)
#define cErr(message) fprintf(stderr, "%s\n", message)

#define ip_get_size(arr) (strlen(arr[0]) + strlen(arr[1]) + \
    strlen(arr[2]) + strlen(arr[3]) + 5)

#define client_message(ftm, ...) \
    dprintf(CCLIENT->_socket_fd, ftm, ##__VA_ARGS__)

#define print_buf(value) ({ \
    buffer[strlen(buffer) - 1] = 0; \
    value; \
})

#define set_quote_state(state) ({ \
    *_start = _string; \
    _pair_sep->first = state; \
})
