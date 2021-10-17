/*
** EPITECH PROJECT, 2021
** teams
** File description:
** string
*/

#pragma once

#include <stdnoreturn.h>
#include <stdbool.h>
#include "macro.h"
#include "struct.h"

noreturn bool helper(int const _output);

char *my_itoa(int number);

bool issdigit(char const *restrict string);

char *my_getline(int const _fd);

char **my_strtok(str_const_restrict _string, str_const_restrict _delim);

void printa(char **_arr);

char *my_ngetline(int const _fd);