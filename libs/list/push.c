/*
** EPITECH PROJECT, 2021
** teams
** File description:
** push
*/

#include <stdbool.h>
#include "include/list.h"

static list *push_next(list *_this, char *_value)
{
    list *last = _this->__metadata._last;

    last->__metadata._prev = last;
    last->__metadata._next = malloc(sizeof(list));
    last->__metadata._next->_value = strdup(_value);
    last->__metadata._next->__metadata._next = NULL;
    _this->__metadata._last = last->__metadata._next;
    return last->__metadata._next;
}

static list *push_current(list *_this, char *_value)
{
    _this->_value = strdup(_value);
    _this->__metadata._fnone = true;
    return _this;
}

list *push_back(list *_this, char *_value)
{
    return (_this->__metadata._fnone) ?
    push_next(_this, _value) : push_current(_this, _value);
}