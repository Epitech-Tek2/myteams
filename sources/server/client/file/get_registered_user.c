/*
** EPITECH PROJECT, 2021
** teams
** File description:
** get_registered_user
*/

#include "server.h"

static void assign_data_user(list_serv *_sclient, int const _id,
int n, mstat_t *_stat)
{
    if (!strcmp(_stat->_parse[n], remove_quotes(CCLIENT->_commands[1]))) {
        if (_stat->_parse[n + 1][strlen(_stat->_parse[n + 1]) - 1] == '\n')
            _stat->_parse[n + 1][strlen(_stat->_parse[n + 1]) - 1] = '\0';
        server_event_user_logged_in(_stat->_parse[n + 1]);
        CCLIENT->_uuid = strdup(_stat->_parse[n + 1]);
        CCLIENT->_username = strdup(_stat->_parse[n]);
        CCLIENT->_is_logged = true;
        dprintf(CCLIENT->_socket_fd, "200;%s;%s", CCLIENT->_username,
        CCLIENT->_uuid);
        update_client_status(_sclient, _id, 1);
        send_logs_to_client(_sclient, _id);
    }
}

static int user_loaded(list_serv *_sclient, int const _id, int i,
mstat_t *_stat)
{
    if (2 == i && 1 < _stat->_length) {
        for (int n = 0; _stat->_length - 1 > n; n += 2)
            assign_data_user(_sclient, _id, n, _stat);
        return 1;
    }
    return 0;
}

static int load_registered_user_process(list_serv *_sclient,
int const _id, mstat_t *_stat)
{
    for (int i = 0; fgets(_stat->_line, sizeof(_stat->_line), _stat->_file);) {
        ++i;
        my_strctok(_stat, ';');
        if (NULL == _stat->_parse) {
            fclose(_stat->_file);
            free(_stat);
            return -1;
        }
        if (1 == user_loaded(_sclient, _id, i, _stat)) {
            my_free_arr(_stat->_parse);
            break;
        }
        my_free_arr(_stat->_parse);
    }
    return 0;
}

int get_registered_user(list_serv *_sclient, int const _id)
{
    mstat_t *stat = malloc(sizeof(mstat_t));
    int error = 0;

    if (NULL == stat) return -1;
    *stat = (mstat_t){._count = -1, ._length = 0, ._parse = NULL};
    stat->_file = fopen(SAVE_USER, "r");
    if (NULL == stat->_file) {
        free(stat);
        return -1;
    }
    if (-1 == load_registered_user_process(_sclient, _id, stat))
        return -1;
    fclose(stat->_file);
    free(stat);
    return 0;
}