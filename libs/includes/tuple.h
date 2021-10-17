/*
** EPITECH PROJECT, 2021
** teams
** File description:
** tuple
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "generics.h"

typedef struct typename typename;

struct typename
{
    char *_type;
    char *_ftp;
    char *_stp;
};

#define __metadata(T, Y, name) char *__ftp = T; char *__stp = Y; \
    char *__type = name;

/* Public macro */
#define tuple(name, T, Tname, Y, Yname) \
    __metadata(#Tname, #Yname, #name); typedef struct name { T Tname;Y Yname; \
        typename __typename; } name; name *

#define __create_tuple(t, s, v, l) ({ \
    s = malloc(sizeof(t)); \
    s->__typename._ftp = __ftp; \
    s->__typename._stp = __stp; \
    s->__typename._type = __type; \
    s->v; \
    s->l; \
    s; \
})

#define create_tuple(t, s, v, l) __create_tuple(t, s, v, l)

/**
* @brief Returns a variable that can be passed as a parameter.
*
* @param _tuple Tuple to pass as parameter.
*/
#define make_tuple(_tuple) (void *)_tuple

#define tuple_t(T, Tname, Y, Yname) struct _ { T Tname; \
    Y Yname; typename __typename; } *
