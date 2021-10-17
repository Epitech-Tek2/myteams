/*
** EPITECH PROJECT, 2021
** teams
** File description:
** compare
*/

#include "include/string.h"

int compare(string_const_restrict _this, str_const_restrict _s)
{
    return strcmp(_this->_value, _s);
}