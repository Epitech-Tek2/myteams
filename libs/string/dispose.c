/*
** EPITECH PROJECT, 2021
** teams
** File description:
** dispose
*/

#include "include/string.h"

void dispose(string *_this)
{
    my_free(_this->_value, _this);
}