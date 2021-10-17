/*
** EPITECH PROJECT, 2021
** teams
** File description:
** foreach
*/

#pragma once

#include "lambda.h"

#pragma GCC diagnostic ignored "-Wformat"

#define lambda(type, name, function_body) ({ \
    void __fn__ (type name) function_body; \
    __fn__; \
})

#define __foreach_arr(arr, fn) ({ \
    void (*func)(char **) = lambda(char **, arr, { \
        for (int i = 0; arr[i]; i++) { fn(arr[i]); } \
    }); \
    func(arr); \
})

#define __foreach_int(arr, fn) ({ \
    void (*func)(int *) = lambda(int *, arr, { \
        for (int i = 0; arr[i] != -1; i++) { fn(arr[i]); } \
    }); \
    func(arr); \
})

#define __foreach_list(arr, fn) ({ \
    void (*func)(list *) = lambda(list *, arr, { \
        for (int i = 0; ((list *)arr)->size(arr) != i; i++) \
        { fn(((list *)arr)->valueof(arr, i)); } \
    }); \
    func((list *)arr); \
})

#define foreach(__list, fn) \
    _Generic((__list), \
        char **: __foreach_arr(__list, fn), \
        int *: __foreach_int(__list, fn), \
        list *: __foreach_list(__list, fn) \
    )

#pragma GCC diagnostic pop