/*
** EPITECH PROJECT, 2021
** teams
** File description:
** functions
*/

#pragma once

#include "../../libs/includes/vector.h"
#include "../../libs/includes/string.h"

/**
* @brief Create a server object and start it.
*
* @param _port Server listening port.
*/
void create_server(int const _port);

/**
* @brief Create a all save file object
*
* @return -1 in case of error, otherwise 0.
*/
int create_all_save_file(void);

/**
* @brief Load registered client.
*
* @return -1 in case of error, otherwise 0.
*/
int load_registered_user(void);

/**
* @brief Parse the uuid.
*
* @param _uuid uuid to parse.
* @return Parsed uuid
*/
char *parse_uuid(char *_uuid);

/**
* @brief Initialize the client.
*
* @param _sclient Current server client instance.
* @param _server Instance of the server.
* @return -1 in case of error, otherwise 0.
*/
int init_client(list_serv *_sclient, server_t *_server);

/**
* @brief Get the client command object
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return 1 in case of error and then logout/clean_client_instance, otherwise 0
*/
int get_client_command(list_serv *_sclient, int const _id);

/**
* @brief Sharing with other clients that a client has disconnected.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
*/
void share_client_logout(list_serv *_sclient, int const _id);

/**
* @brief Update the current client's status
*
* @param _id Current client id.
* @param _status 0
* @return -1 in case of error, otherwise 0
*/
int update_client_status(list_serv *_sclient, int const _id,
int const _status);

/**
* @brief Handle the client connection.
*
* @param _sclient Current server client instance.
* @param _server Instance of the server
*/
void client_connection(list_serv *_sclient, server_t *_server);

/**
* @brief Reset the _id client metadata.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return 1
*/
int clean_client_instance(list_serv *_sclient, int const _id);

/**
* @brief Handle client command.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return -1 in case of error, otherwise 0
*/
int handle_client_command(list_serv *_sclient, int const _id);

/**
* @brief Check if _username client already exist in save user file.
*
* @param _line Line inside the user save file where data are.
* @param _username Requested username.
* @return -1 in case of error, otherwise 0 if user exist else 1
*/
int check_user_already_register(int const _line, string *_username);

/**
* @brief Handle login client
*
* @param _sclient Current server client instance.
* @param _id Current client id.
* @return -1 in case of error, otherwise 0.
*/
int login_client(list_serv *_sclient, int const _id);

/**
* @brief Function call to do nothing in function pointer array commands.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length
* @return true
*/
bool nop(list_serv *_sclient __attribute__((unused)),
int const _id __attribute__((unused)),
int const _length __attribute__((unused)));

/**
* @brief Display help information to client
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @return 0
*/
int help(list_serv *_sclient, int const _id);

/**
* @brief Display all users registered data.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length Number of line in save user file
* @return false in case of error, otherwise true
*/
bool users(list_serv *_sclient, int const _id,
int const _length);

/**
* @brief Search a user by uuid.
*
* @param _sclient Current server client instance.
* @param _id Id of the client.
* @param _length Number of line in save user file
* @return false in case of error, otherwise true
*/
bool user(list_serv *_sclient, int const _id, int const _length);

bool create(list_serv *_sclient, int const _id, int const _length);

bool messages(list_serv *_sclient, int const _id, int const _length);

bool sender(list_serv *_sclient, int const _id, int const _length);

bool use(list_serv *_sclient, int const _id, int const _length);

bool listt(list_serv *_sclient, int const _id, int const _length);

bool info(list_serv *_sclient, int const _id, int const _length);

bool subscribe(list_serv *_sclient, int const _id, int const _length);

bool subscribed(list_serv *_sclient, int const _id, int const _length);

bool unsubscribe(list_serv *_sclient, int const _id, int const _length);

/**
* @brief List of user command
*/
static const commands command[] = {
    &nop,
    &users,
    &user,
    &create,
    &messages,
    &sender,
    &use,
    &listt,
    &info,
    &subscribe,
    &subscribed,
    &unsubscribe,
    NULL
};

/**
* @brief Append _string in the user save file.
*
* @param _filepath File to modifie.
* @param _line N line where to append _string.
* @param _string String to append.
* @return -1 in case of error, otherwise 0.
*/
int append_client_data_in_save_file(str_const_restrict _filepath,
int const _line, str_const_restrict _string);

/**
* @brief Append new user logs into user save file.
*
* @param _sclient Current server client instance.
* @param _id Current client id.
*/
void add_new_client_to_save_file(list_serv *_sclient,
int const _id);

int get_registered_user(list_serv *_sclient, int const _id);

void send_logs_to_client(list_serv *_sclient, int const _id);

int logout(list_serv *_sclient, int const _id);

int create_team(list_serv *_sclient, int const _id, int const _length);

int create_channel(list_serv *_sclient, int const _id, int const _length);

mstat_t *new_mstat(mstat_t *_default_data);

bool user_exist(list_serv *_sclient, int const _id);

bool is_team(server_client_t *_sclient);

bool is_user_in_team(server_client_t *_sclient);