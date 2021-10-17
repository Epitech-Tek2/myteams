/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** strtok
*/

#include <stdio.h>
#include "include/cstring.h"

char **my_strtok(str_const_restrict _string, str_const_restrict _delim)
{
    char **arr = malloc(sizeof(char *));
    char *token = strtok((char *)_string, _delim);

    if (NULL == arr || NULL == token)
        return NULL;
    for (int i = 0; true;) {
        arr[i] = strdup(token);
        i++;
        arr = realloc(arr, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, _delim);
        if (NULL == token) {
            arr[i] = NULL;
            break;
        }
    }
    my_free(token);
    return arr;
}