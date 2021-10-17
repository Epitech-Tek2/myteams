/*
** EPITECH PROJECT, 2021
** teams
** File description:
** macro
*/

#pragma once

#define handle_select_error() ({ \
    if (errno == EINTR) return -1; \
    else eraise(_sclient); \
})

#define my_select(nfds, readfds) select(nfds + 1, &readfds, NULL, NULL, NULL)
#define my_fd_set(rds) FD_SET(STDIN_FILENO, &rds);

#define check_strctok() \
    if (NULL == stuple || !strcmp(str, "")) {free(stuple); \
    list_l->ldispose(list_l);return;}

#define get_status(command) ({ \
    int status = atoi(command); \
    if (status > 1) \
        status = 1; \
    status; \
})
