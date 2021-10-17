/*
** EPITECH PROJECT, 2021
** teams
** File description:
** add_new_client_to_save_file
*/

#include "server.h"

void add_new_client_to_save_file(list_serv *_sclient, int const _id)
{
    FILE *file = fopen(SAVE_USER, "a");

    fprintf(file, LOG_CREATED_USER, CCLIENT->_username, CCLIENT->_uuid);
    fclose(file);
}