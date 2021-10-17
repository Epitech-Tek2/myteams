/*
** EPITECH PROJECT, 2021
** teams
** File description:
** help
*/

#include "server.h"

int help(list_serv *_sclient, int const _id)
{
    client_message("HELP :\n\t/login [\"username\"] : login with your id\n");
    return 0;
}