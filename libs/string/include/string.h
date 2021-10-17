/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cstring
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../includes/cstring.h"
#include "../../includes/lambda.h"
#include "struct.h"
#include "macro.h"

#define append(_this, _str, ...) \
    append(_this, _str, _N__ARG(__VA_ARGS__), ##__VA_ARGS__)

/**
* @brief Create a new string.
*
* @param value - Value of the string.
* @param new - Don't allocate memory for the new string.
*/
#define new_string(value, ...) \
    new_string(value, _N__ARG(__VA_ARGS__), ##__VA_ARGS__)

string *(new_string)(char *_value, int const _count, ...);

/**
* @brief Find position of a C substring.
*
* @param _this Current instance.
* @param _s C string to locate.
* @param _pos Index of character to search from.
* @param _n Number of characters from s to search for.
*/
#define find(_this, _s, _pos, ...) find(_this, _s, _pos, ##__VA_ARGS__)

int (find)(string_const_restrict _this, char const *str, size_t const pos, ...);

/**
* @brief Returns the number of characters in the string, not including any
* null-termination.
*/
#define length(str) length(str)

size_t (length)(string_const_restrict _string);

/**
* @brief Returns true if the %string is empty. Equivalent to.
*
* @param _this Current instance.
*/
bool empty(string_const_restrict _this);

/**
* @brief Compare to a C string.
*
* @param _this Current instance.
* @param _s C string to compare against.
*/
int compare(string_const_restrict _this, str_const_restrict _s);

/**
* @brief Append a string to this string.
*
* @param _this Current instance.
* @param _str The string to append.
*/
string *(append)(string *_this, str_const_restrict _str, int _count, ...);

void dispose(string *_this);

/**
* @brief Set the value of the object.
*
* @param _this Current instance.
* @param _value Value to assign.
* @return Pointer to new object.
*/
string *set(string *_this, str_const_restrict _value);