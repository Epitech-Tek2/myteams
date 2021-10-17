/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** issdigit
*/

#include <stdbool.h>
#include <ctype.h>

bool issdigit(char const *restrict string)
{
    for (int i = 0; string[i]; i++)
        if (!isdigit(string[i]) && string[i] != '.')
            return false;
    return true;
}
