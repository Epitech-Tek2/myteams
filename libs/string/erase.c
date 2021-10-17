/*
** EPITECH PROJECT, 2021
** teams
** File description:
** erase
*/

#include "include/string.h"

static char *process_pos(string *_this, size_t _pos)
{
    size_t n = 0;
    char *tmp = malloc(_this->length(_this));

    for (size_t i = 0; _this->_value[i]; ++i)
        if (i != _pos) tmp[n++] = _this->_value[i];
    tmp[n] = '\0';
    return tmp;
}

string *erase(string *_this, size_t _pos, ...)
{
    if (!check_this()) return _this;
    if (_pos >= _this->length(_this)) return _this;
    _this->_value = process_pos(_this, _pos);
    return _this;
}