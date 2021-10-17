/*
** EPITECH PROJECT, 2021
** teams
** File description:
** dispose
*/

#include "include/list.h"

void disposel(list_serv *_this)
{
    list_serv *tmp;

    for (int i = 0; _this != NULL;) {
        tmp = _this->__metadata._next;
        free(_this->_value->_username), _this->_value->_username = NULL;
        free(_this->_value->_uuid), _this->_value->_uuid = NULL;
        free(_this->_value), _this->_value = NULL;
        free(_this), _this = tmp;
    }
    _this = NULL;
}

void ldispose(list *_this)
{
    list *tmp;

    for (int i = 0; _this != NULL;) {
        tmp = _this->__metadata._next;
        free(_this->_value);
        free(_this);
        _this = tmp;
    }
    _this = NULL;
}