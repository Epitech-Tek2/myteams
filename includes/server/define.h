/*
** EPITECH PROJECT, 2021
** teams
** File description:
** define
*/

#pragma once

#define MIN_PORT 1
#define MAX_PORT 65534
#define MAX_CLIENT 10

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

#define INVALID_PORT "Please specify a valid port [1, 65534].\n"
#define INVALID_LOGIN \
    "Invalid login, please enter a login between [1, 31] characters.\n"
#define ERROR_COMMAND "An error occured with your command.\n"
#define INVALID_ARG_CREATE "Invalid argument for create command."

#define SAVE_FILE "./.tmp"
#define SAVE_TEAM "./.tmp/save_team.txt"
#define SAVE_USER "./.tmp/save_user.txt"
#define SAVE_CHANNEL "./.tmp/save_channel.txt"
#define REPLACE_FILE "replace.txt"
#define TEAM_PSSWD "My Big Team Password"
#define USER_PSSWD "My Big User Password"
#define CHANNEL_PSSWD "My Big Channel Password"

#define SERVER_CLIENT_INIT ((server_client_t){._in_use = false, \
    ._message = NULL, ._uuid = NULL, ._is_logged = false, ._socket_fd = 0})

/* Current client instance */
#define CCLIENT _sclient->valueofl(_sclient, _id)
#define ICCLIENT _sclient->valueofl(_sclient, i)

#define LOG_CREATED_USER \
    "name;%s\nuuid;%s\nstatus;1\nteam\nmessage\nchannel\n\n"
#define TEAM_DATA_LOG \
    "name_team;%s\nuuid;%s\ndescription;%s\npeople;%s\nthread\nchannel\n\n"
#define CHANNEL_DATA_LOG \
    "name_channel;%s\nuuid;%s\ndescription;%s\nteam;%s\nthread\n\n"
#define MESSAGES_DATA_LOG \
    "300;%s;%s;%s"

/* Define for users.c */
#define FDATA file->_parse[0]

/* Temporary shitty tricks to avoid style error */
#define check_strctok() \
    if (NULL == stuple || !strcmp(str, "")) {free(stuple); \
    list_l->ldispose(list_l);return;}
