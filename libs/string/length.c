/*
** EPITECH PROJECT, 2021
** teams
** File description:
** length
*/

#include "include/string.h"

size_t (length)(string_const_restrict _string)
{
    return strlen(_string->_value);
}