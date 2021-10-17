/*
** EPITECH PROJECT, 2021
** teams
** File description:
** macro
*/

#pragma once

#include <errno.h>
#include <string.h>
#include "../../includes/generics.h"

#define findc(fc, c, ...) findc(fc, c, _N__ARG(__VA_ARGS__), ##__VA_ARGS__)

#include "inline.h"

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#define my_fclose(ptr, ...) my_fclose(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#define my_exist(ptr, ...) my_exist(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#define eraise(...) ({ \
    fprintf(stderr, "%s:%s:%d %s\n", __FILE__, __func__, \
        __LINE__, strerror(errno)); \
    my_free(NULL, ##__VA_ARGS__); \
    exit(84); \
})

#define eraise_with_help(message) ({ \
    cErr(message); \
    helper(84); \
})

#define uraise(error, ...) ({ \
    cErr(error); \
    my_free(NULL, ##__VA_ARGS__); \
    exit(84); \
})
