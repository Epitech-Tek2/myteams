/*
** EPITECH PROJECT, 2021
** teams
** File description:
** end
*/

#include "include/list.h"

list *end(list *_this)
{
    return _this->__metadata._last;
}

list_serv *endl(list_serv *_this)
{
    return _this->__metadata._last;
}