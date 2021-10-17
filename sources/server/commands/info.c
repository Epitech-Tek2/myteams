/*
** EPITECH PROJECT, 2021
** teams
** File description:
** info
*/

#include "server.h"

bool info(list_serv *_sclient, int const _id, int const _length)
{
    if (!is_enought_arg(1, _length)) return false;
    if (!CCLIENT->_in_use) return users(_sclient, _id, _length);
    return false;
}