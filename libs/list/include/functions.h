/*
** EPITECH PROJECT, 2021
** teams
** File description:
** functions
*/

#pragma once

#include "struct.h"

list *push_back(list *_this, char *_value);
list_serv *push_backl(list_serv *_this, server_client_t *_value);

size_t size(list *_this);
size_t sizel(list_serv *_this);

char *valueof(list *_this, size_t const _i);
server_client_t *valueofl(list_serv *_this, size_t const _i);

void ldispose(list *_this);
void disposel(list_serv *_this);

list *end(list *_this);
list_serv *endl(list_serv *_this);

char **copy(list *_this);