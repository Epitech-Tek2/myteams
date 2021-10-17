/*
** EPITECH PROJECT, 2021
** teams
** File description:
** string
*/

#include "include/string.h"

string *(new_string)(char *_value, int const _count, ...)
{
    string *new_value = malloc(sizeof(string));

    if (NULL == new_value) return NULL;
    *new_value = (string){._value = !_count || !get_first_valist(int, ...) ?
        strdup(_value) : _value, .length = length, .find = find,
        .empty = empty, .compare = compare, .append = append,
        .dispose = dispose, .set = set};
    return new_value;
}