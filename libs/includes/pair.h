/*
** EPITECH PROJECT, 2021
** teams
** File description:
** pair
*/

#pragma once

#include <stdio.h>

/* Public macro */
#define pair(name, type1, type2) \
typedef struct name {type1 first;type2 second;} name; name

/**
* @brief Returns a variable that can be passed as a parameter.
*
* @param _pair Pair to pass as parameter.
*/
#define make_pair(_pair) (void *)&_pair

#define pair_t(type1, type2) struct _ { type1 first; type2 second; } *