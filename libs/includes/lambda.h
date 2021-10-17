/*
** EPITECH PROJECT, 2021
** teams
** File description:
** lambda
*/

#pragma once

#include "generics.h"

#define _N__ARG(...) _N__ARGS(, ##__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _N__ARGS(z, a, b, c, d, e, f, cnt, ...) cnt

#define get_first_valist_proccess(type, _, ...) ({ \
    va_list list_ptr; \
    va_start(list_ptr, _); \
    bool tmp = va_arg(list_ptr, type); \
    va_end(list_ptr); \
    tmp; \
})

#define get_first_valist(type, ...) get_first_valist_proccess(type, NULL, ...)