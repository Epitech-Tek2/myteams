/*
** EPITECH PROJECT, 2021
** teams
** File description:
** set
*/

#include "include/string.h"

string *set(string *_this, str_const_restrict _value)
{
    _this->_value = strdup(_value);
}