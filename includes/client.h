/*
** EPITECH PROJECT, 2021
** teams
** File description:
** client
*/

#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../libs/string/include/string.h"
#include "../libs/cstring/include/cstring.h"
#include "../libs/includes/foreach.h"
#include "../libs/myteams/logging_client.h"
#include "macro.h"
#include "struct.h"
#include "client/struct.h"
#include "client/inline.h"
#include "client/macro.h"
#include "client/functions.h"

void start_client(char const *_av[]);