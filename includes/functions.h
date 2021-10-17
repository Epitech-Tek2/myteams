/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** functions
*/

#pragma once

#include <stdbool.h>
#include <stdnoreturn.h>
#include "struct.h"

/**
* @brief Parse _stat->_line and return splited array by _sep.
*
* @param _stat Stat object.
* @param _sep Separator for parsing.
* @return Parsed array.
*/
void my_strctok(mstat_t *_file, char _sep);

/**
* @brief Remove '"' from _string
*
* @param _username String to parse.
* @return parsed string.
*/
char *remove_quotes(str_const_restrict _string);