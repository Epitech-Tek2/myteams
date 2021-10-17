/*
** EPITECH PROJECT, 2021
** teams
** File description:
** find
*/

#include "include/string.h"

int (find)(string const *_this, char const *_s, size_t const _pos, ...)
{
    char *tmp = NULL;
    int n = get_first_valist(int, ...);

    if (!_this || !_s || !_this->_value) return (-1);
    if (_pos > _this->length(_this) - 1) return (-1);
    tmp = strstr(_this->_value + _pos, _s);
    if (!tmp) return (-1);
    (void)n;
    return (tmp - _this->_value);
}