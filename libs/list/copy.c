/*
** EPITECH PROJECT, 2021
** teams
** File description:
** copy
*/

#include "include/list.h"

char **copy(list *_this)
{
    size_t size = _this->size(_this);
    char **arr = malloc(sizeof(char *) * (size + 1));

    for (size_t i = 0; i < size; i++) arr[i] =
    strdup(_this->valueof(_this, i));
    arr[size] = NULL;
    return arr;
}