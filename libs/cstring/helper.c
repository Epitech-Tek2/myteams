/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** utils
*/

#include <stdnoreturn.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "include/cstring.h"

noreturn bool helper(int const _output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = fopen("./help.txt", "r");

    errno = 0;
    if (NULL == stream) eraise();
    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(_output);
}