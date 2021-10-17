/*
** EPITECH PROJECT, 2021
** teams
** File description:
** functions
*/

#pragma once

int recieving(client_t *_sclient);

int sending(client_t *_sclient, char *_command);

void my_strctok(mstat_t *_file, char _sep);

char **get_command_parsed(str_const_restrict _command, char const _sep);

void logging_user(client_t *_sclient, char *_command);

int handle_requested_command(client_t *_sclient, str_const_restrict _command);

bool logs(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool user(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool users(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool nop(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool logout(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool create_team(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool error_c(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool messages(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool message(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool create_channel(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool listt(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool sub(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

bool unsub(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

typedef bool (*commands)(client_t *_sclient, arr_const_restrict _commands,
str_const_restrict _message, int const _length);

/**
* @brief List of user command
*/
static const commands command[] = {
    &nop,
    &create_team,
    &create_channel,
    &listt,
    &listt,
    &sub,
    &unsub,
    &nop,
    &logout,
    &messages,
    &message,
    &user,
    &users,
    &logs,
    &error_c,
    &error_c,
    &error_c,
    &error_c,
    NULL
};