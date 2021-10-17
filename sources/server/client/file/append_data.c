/*
** EPITECH PROJECT, 2021
** teams
** File description:
** append_client_data_in_save_file
*/

#include "server.h"

int append_client_data_in_save_file(str_const_restrict _filepath,
int const _line, str_const_restrict _string)
{
    mstat_t *file = malloc(sizeof(mstat_t));
    FILE *file_tmp = fopen(REPLACE_FILE, "w");
    char buffer[5024];

    if (NULL == file || NULL == file_tmp) return -1;
    *file = (mstat_t){._file = fopen(_filepath, "r")};
    if (NULL == file->_file) return -1;
    for (int i = 0; fgets(buffer, 5024, file->_file);) {
        ++file->_count;
        if (file->_count == _line && strcmp(buffer, "\n") != 0)
            print_buf(fprintf(file_tmp, "%s;%s\n", buffer, _string));
        else if (file->_count == _line && !strcmp(buffer, "\n"))
            print_buf(fprintf(file_tmp, "%s\n", _string));
        else fputs(buffer, file_tmp);
    }
    my_fclose(file->_file, file_tmp);
    free(file);
    remove(_filepath);
    rename(REPLACE_FILE, _filepath);
    return 0;
}