/*
** EPITECH PROJECT, 2021
** teams
** File description:
** file
*/

#include "server.h"

static int replace_status(char *_number, int const _line, int const _status)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    FILE *file_tmp = fopen(REPLACE_FILE, "w");
    int new_status = 0;

    if (NULL == file || NULL == file_tmp) return -1;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r")};
    if (NULL == file->_file) return -1;
    if (-1 != _status) _number[strlen(_number) - 1] = '\0';
    new_status = atoi(_number);
    new_status = (1 == _status) ? new_status + 1 : (-1 != _status) ?
    new_status - 1 : new_status;
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        i++;
        _line == i ? fprintf(file_tmp, "status;%d\n", new_status) :
        fputs(file->_line, file_tmp);
    }
    my_fclose(file->_file, file_tmp);
    free(file);
    remove(SAVE_USER);
    rename(REPLACE_FILE, SAVE_USER);
}

static int check_status(mstat_t *_file, int const _status, int const _i)
{
    if (_file->_count == _i) {
        if (-1 == replace_status(_file->_parse[1], _file->_count, _status))
            return -1;
        my_free_arr(_file->_parse);
        fclose(_file->_file);
        return 1;
    }
    return 0;
}

static void set_status(mstat_t *_file, list_serv *_sclient, int const _id,
int const _i)
{
    for (int i = 0; i != _file->_length; ++i) {
        if (!strcmp(_file->_parse[i], "name") &&
        !strcmp(parse_uuid(_file->_parse[1]), CCLIENT->_username))
            _file->_count = _i + 2;
    }
    my_free_arr(_file->_parse);
}

int update_client_status(list_serv *_sclient, int const _id, int const _status)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    int error = 0;

    if (NULL == file) return -1;
    *file = (mstat_t){._file = fopen(SAVE_USER, "r+"), ._parse = NULL,
    ._count = -1, ._length = 0};
    if (NULL == file->_file) return -1;
    for (int i = 0; fgets(file->_line, sizeof(file->_line), file->_file);) {
        i++;
        my_strctok(file, ';');
        error = check_status(file, _status, i);
        if (-1 == error) return -1;
        if (1 == error) return 0;
        set_status(file, _sclient, _id, i);
    }
    return 0;
}