/*
** EPITECH PROJECT, 2021
** teams
** File description:
** push
*/

#include <stdbool.h>
#include "include/list.h"

static list_serv *push_next(list_serv *_this, server_client_t *_value)
{
    list_serv *last = _this->__metadata._last;
    list_serv *new = NULL;

    last->__metadata._next = malloc(sizeof(list_serv));
    new = last->__metadata._next;
    new->__metadata._prev = last;
    new->__metadata._next = NULL;
    new->_value = malloc(sizeof(server_client_t));
    new->_value = memcpy(new->_value, _value, sizeof(server_client_t));
    _this->__metadata._last = new;
    return new;
}

static list_serv *push_current(list_serv *_this, server_client_t *_value)
{
    _this->_value = malloc(sizeof(server_client_t));
    _this->_value = memcpy(_this->_value, _value, sizeof(server_client_t));
    _this->__metadata._fnone = true;
    return _this;
}

list_serv *push_backl(list_serv *_this, server_client_t *_value)
{
    return (_this->__metadata._fnone) ?
    push_next(_this, _value) : push_current(_this, _value);
}