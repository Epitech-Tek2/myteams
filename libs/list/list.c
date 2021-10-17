/*
** EPITECH PROJECT, 2021
** teams
** File description:
** list
*/

#include "include/list.h"
#include "include/functions.h"

list_serv *new_listl(server_client_t *_sclient)
{
    list_serv *new_tlist = malloc(sizeof(list_serv));

    if (NULL == new_tlist) return NULL;
    *new_tlist = (list_serv){.push_backl = push_backl, .sizel = sizel,
    .valueofl = valueofl, .disposel = disposel, .endl = endl,
    ._value = _sclient ? _sclient : NULL};
    new_tlist->__metadata._next = NULL;
    new_tlist->__metadata._prev = NULL;
    new_tlist->__metadata._last = new_tlist;
    new_tlist->__metadata._first = new_tlist;
    new_tlist->__metadata._fnone = _sclient ? true : false;
    return new_tlist;
}

list *new_list(char const *restrict _value)
{
    list *new_tlist = malloc(sizeof(list));

    if (NULL == new_tlist) return NULL;
    *new_tlist = (list){.push_back = push_back, .size = size,
    .valueof = valueof, .ldispose = ldispose, .end = end, .copy = copy,
    ._value = _value ? strdup(_value) : NULL};
    new_tlist->__metadata._next = NULL;
    new_tlist->__metadata._prev = NULL;
    new_tlist->__metadata._last = new_tlist;
    new_tlist->__metadata._first = new_tlist;
    new_tlist->__metadata._fnone = _value ? true : false;
    return new_tlist;
}