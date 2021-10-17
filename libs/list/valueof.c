/*
** EPITECH PROJECT, 2021
** teams
** File description:
** valueof
*/

#include "include/list.h"

server_client_t *valueofl(list_serv *_this, size_t const _i)
{
    list_serv *current = _this;
    size_t size = current->sizel(current);

    for (size_t i = 0; i < size; i++) {
        if (_i == i) return current->_value;
        current = current->__metadata._next;
    }
    return NULL;
}

char *valueof(list *_this, size_t const _i)
{
    list *current = _this;
    size_t size = current->size(current);

    for (size_t i = 0; i < size; i++) {
        if (_i == i) return current->_value;
        current = current->__metadata._next;
    }
    return NULL;
}