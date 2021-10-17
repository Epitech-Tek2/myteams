/*
** EPITECH PROJECT, 2021
** teams
** File description:
** file
*/

#include "server.h"

static int create_save_file(str_const_restrict _filepath,
str_const_restrict _psswd)
{
    save_file_t *file = malloc(sizeof(save_file_t));

    *file = (save_file_t){._check = false};
    if (NULL == file) return -1;
    file->_file = fopen(_filepath, "r");
    if (NULL != file->_file) {
        fscanf(file->_file, "%[^\n]", file->_pass);
        file->_check = (!strcmp(_psswd, file->_pass));
    }
    if (!file->_check) {
        file->_file = fopen(_filepath, "w+");
        fprintf(file->_file, "%s\n\n\n", _psswd);
    }
    fclose(file->_file);
    free(file);
    return 0;
}

int create_all_save_file(void)
{
    save_file_t *file = malloc(sizeof(save_file_t));

    if (NULL == file) return -1;
    if (-1 == stat(SAVE_FILE, &file->_stat)) mkdir(SAVE_FILE, 0777);
    if (-1 == create_save_file(SAVE_TEAM, TEAM_PSSWD)) return -1;
    if (-1 == create_save_file(SAVE_USER, USER_PSSWD)) return -1;
    if (-1 == create_save_file(SAVE_CHANNEL, CHANNEL_PSSWD)) return -1;
    free(file);
    return 0;
}