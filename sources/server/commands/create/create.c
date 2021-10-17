/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create
*/

#include "server.h"

bool create(list_serv *_sclient, int const _id, int const _length)
{
    if (!CCLIENT->_in_use && 3 == _length) create_team(_sclient, _id, _length);
    else if (CCLIENT->_in_use && 3 == _length) create_channel(_sclient, _id,
    _length);
}