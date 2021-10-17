/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** getline
*/

#include <unistd.h>
#include <stdio.h>
#include "include/cstring.h"

bool check_line(getline_t *_getline)
{
    if (0 == _getline->_comp && 0 == _getline->_read) {
        my_free(_getline->_line);
        return false;
    }
    _getline->_size++;
    _getline->_line[_getline->_comp] = '\0';
    return true;
}

static void getline_process(getline_t *getline)
{
    for (; getline->_read > getline->_size && '\n' !=
    getline->_save[getline->_size]; getline->_comp++, getline->_size++)
        getline->_line[getline->_comp] = getline->_save[getline->_size];
}

char *my_getline(int const _fd)
{
    static getline_t getline = (getline_t){._comp = 0, ._line = NULL,
    ._read = 1, ._save = {0}, ._size = 1};

    if (-1 == _fd) return NULL;
    getline._comp = 0;
    getline._line = malloc(100);
    if (NULL == getline._line)
        return NULL;
    while (0 != getline._read && '\n' != getline._save[getline._size]) {
        if (getline._read <= getline._size) {
            getline._read = read(_fd, getline._save, 4);
            getline._size = 0;
        }
        getline_process(&getline);
    }
    return !check_line(&getline) ? NULL : getline._line;
}