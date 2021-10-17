/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** inline
*/

#pragma once

#include "cstring.h"
#include "../../includes/string.h"

static inline void (my_free)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    free(_ptr);
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        free(va_arg(list_ptr, void *));
    va_end(list_ptr);
}

static inline void (my_fclose)(int _count, FILE *_file, ...)
{
    va_list list_ptr;

    fclose(_file);
    for (va_start(list_ptr, _file); _count > 0; --_count)
        fclose(va_arg(list_ptr, FILE *));
    va_end(list_ptr);
}

static inline void my_free_arr(char **_ptr)
{
    for (int i = 0; _ptr[i]; i++)
        free(_ptr[i]);
    free(_ptr);
}

static inline bool (my_exist)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    if (!_ptr)
        return false;
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        if (!va_arg(list_ptr, void *))
            return false;
    va_end(list_ptr);
    return true;
}

static inline bool (findc)(char _fc, char _c, int _count, ...)
{
    va_list list_char;

    if (_fc == _c) return true;
    for (va_start(list_char, _count); _count > 0; --_count)
        if (va_arg(list_char, int) == _fc)
            return true;
    return false;
}