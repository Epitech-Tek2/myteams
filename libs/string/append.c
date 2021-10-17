/*
** EPITECH PROJECT, 2021
** teams
** File description:
** append
*/

#include "include/string.h"

static string *process_append(string *_this, str_const_restrict _str)
{
    char *tmp = NULL;
    char *str = NULL;

    tmp = malloc(_this->length(_this) + strlen(_str) + 1);
    str = strdup(_this->_value);
    if (!tmp || !str) NULL;
    memset(tmp, '\0', _this->length(_this) + strlen(_str) + 1);
    tmp = strcat(tmp, str);
    tmp = strcat(tmp, _str);
    free(_this->_value);
    _this->_value = strdup(tmp);
    my_free(str, tmp);
    return (_this);
}

string *(append)(string *_this, str_const_restrict _str, int _count, ...)
{
    va_list list_str;

    if (NULL == _str || !check_this()) return _this;
    if (!_count) return process_append(_this, _str);
    for (va_start(list_str, _count); _count; --_count)
        _this = process_append(_this, va_arg(list_str, char *));
    return _this;
}