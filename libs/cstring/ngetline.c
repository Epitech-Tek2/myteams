/*
** EPITECH PROJECT, 2021
** teams
** File description:
** ngetline
*/

#include <unistd.h>
#include <stdio.h>
#include "include/cstring.h"

static int init_str(char **str, char *buffer)
{
    int i = 0;

    *str = malloc(100 + 1);
    if (NULL == *str) return -1;
    *str = memset(*str, '\0', 100 + 1);
    for (; *buffer && (!i || '\n' != *(buffer - 1)); i++, (buffer)++)
        (*str)[i] = *buffer;
    return i;
}

static char *init_buffer(const int fd)
{
    char *buffer = malloc(100 + 1);
    int val = 0;

    if (NULL == buffer) return NULL;
    buffer = memset(buffer, '\0', 100 + 1);
    if ((val = read(fd, buffer, 100)) == -1)
        return NULL;
    buffer[val] = '\0';
    return buffer;
}

char *my_ngetline(const int fd)
{
    char *buffer = init_buffer(fd);
    char *str = NULL;
    int nb = 0;

    if (NULL == buffer || !buffer[0]) return NULL;
    nb = init_str(&str, buffer);
    free(buffer), buffer = NULL;
    if (nb == -1) return NULL;
    str[nb] = '\0';
    if (nb != 0 && str[nb - 1] == '\n') str[nb - 1] = '\0';
    else str = strcat(str, my_ngetline(fd));
    return str;
}