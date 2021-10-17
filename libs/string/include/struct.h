/*
** EPITECH PROJECT, 2021
** teams
** File description:
** struct
*/

#pragma once

#include "../../cstring/include/struct.h"

typedef struct string_s string;
typedef string const *restrict string_const_restrict;

struct string_s
{
    char *_value;
    size_t (*length)(string_const_restrict _this);
    int (*find)(string_const_restrict _this, char const *_s, size_t const _pos,
    ...);
    bool (*empty)(string_const_restrict _this);
    int (*compare)(string_const_restrict _this, str_const_restrict _s);
    string *(*append)(string *_this, str_const_restrict _str, int _count, ...);
    void (*dispose)(string *_this);
    string *(*set)(string *_this, str_const_restrict _value);
};