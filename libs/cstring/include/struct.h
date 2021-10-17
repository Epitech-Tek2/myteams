/*
** EPITECH PROJECT, 2021
** teams
** File description:
** struct
*/

#pragma once

typedef char const *restrict const *restrict arr_const_restrict;
typedef char const *restrict str_const_restrict;

typedef struct getline_s getline_t;

struct getline_s
{
    int _read;
    int _size;
    int _comp;
    char _save[6];
    char *_line;
};