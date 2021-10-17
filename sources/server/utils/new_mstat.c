/*
** EPITECH PROJECT, 2021
** teams
** File description:
** new_mstat
*/

#include "server.h"

mstat_t *new_mstat(mstat_t *_default_data)
{
    mstat_t *file = malloc(sizeof *file);

    if (NULL == file) return NULL;
    *file = _default_data != NULL ? *_default_data :
    (mstat_t){._parse = NULL, ._length = 0};
    return file;
}