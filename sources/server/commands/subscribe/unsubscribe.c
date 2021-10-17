/*
** EPITECH PROJECT, 2021
** teams
** File description:
** unsubscribe
*/

#include "server.h"

static bool process_deletion(server_client_t *_sclient, mstat_t *_file,
string *team, int const _length)
{
    bool is_removed = false;

    for (int i = 1; i != _length; i++)
        if (strcmp(parse_uuid(_file->_parse[i]),
        remove_quotes(_sclient->_commands[1])))
            team->append(team, ";", _file->_parse[i]);
        else is_removed = true;
    return is_removed;
}

static bool delete_uuid_team(server_client_t *_sclient, int const _count,
int _length)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r")});
    FILE *file_tmp = fopen(REPLACE_FILE, "w");
    string *team = new_string("team");
    bool is_removed = false;

    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        _length += file->_length;
        if (i != _count) {
            fputs(file->_line, file_tmp);
            continue;
        }
        my_strctok(file, ';');
        is_removed = process_deletion(_sclient, file, team, _length);
        fprintf(file_tmp, "%s\n", team->_value);
    }
    my_fclose(file->_file, file_tmp);
    remove(SAVE_USER);
    rename(REPLACE_FILE, SAVE_USER);
    return is_removed;
}

static int process_unsubscribment(server_client_t *_sclient, mstat_t *_file,
int const _i, int _length)
{
    for (int i = 0; i != _length; i++)
        if (!strcmp(_file->_parse[i], "name") &&
        !strcmp(parse_uuid(_file->_parse[1]), _sclient->_username)) {
            fclose(_file->_file);
            return delete_uuid_team(_sclient, _i + 3, _length);
        }
    return 3;
}

static bool unsubscribe_client(server_client_t *_sclient)
{
    mstat_t *file = new_mstat(&(mstat_t){._file = fopen(SAVE_USER, "r")});
    int length = 0;

    for (int i = 1; fgets(file->_line, sizeof(file->_line), file->_file); i++) {
        my_strctok(file, ';');
        length = file->_length;
        if (3 != process_unsubscribment(_sclient, file, i, length)) return true;
    }
    fclose(file->_file);
    return false;
}

bool unsubscribe(list_serv *_sclient, int const _id, int const _length)
{
    if (2 != _length) {
        client_message("invalid command");
        return false;
    } else if (!unsubscribe_client(CCLIENT))
        client_message("503;%s",
        remove_quotes(CCLIENT->_commands[1]));
    else {
    client_message("105;%s;%s", CCLIENT->_uuid,
    remove_quotes(CCLIENT->_commands[1]));
    server_event_user_unsubscribed(remove_quotes(CCLIENT->_commands[1]),
    CCLIENT->_uuid);
    }
}