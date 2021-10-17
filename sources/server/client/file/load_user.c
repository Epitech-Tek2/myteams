/*
** EPITECH PROJECT, 2021
** teams
** File description:
** load_user
*/

#include "server.h"

static int user_loaded(int i, mstat_t *_stat)
{
    if (2 == i && 1 < _stat->_length) {
        for (int n = 0; _stat->_length - 1 > n; n += 2)
            server_event_user_loaded(parse_uuid(_stat->_parse[n + 1]),
            _stat->_parse[n]);
        return 1;
    }
    return 0;
}

static int load_registered_user_process(mstat_t *_stat)
{
    for (int i = 0; fgets(_stat->_line, sizeof(_stat->_line), _stat->_file);) {
        ++i;
        my_strctok(_stat, ';');
        if (NULL == _stat->_parse) {
            fclose(_stat->_file);
            free(_stat);
            return -1;
        }
        if (1 == user_loaded(i, _stat)) {
            my_free_arr(_stat->_parse);
            break;
        }
        my_free_arr(_stat->_parse);
    }
    return 0;
}

int load_registered_user(void)
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
    if (-1 == load_registered_user_process(stat)) return -1;
    fclose(stat->_file);
    free(stat);
    return 0;
}