/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** str_to_quot
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functions.h>
#include "server.h"
#include "struct.h"
#include "../../../libs/includes/list.h"
#include "../../../libs/includes/tuple.h"

static void fill_list(const char *start, const char *end, list *_list)
{
    list *current = _list;
    char *str = malloc((strlen(start) - strlen(end)) * sizeof(char *));
    int i = 0;

    for (i = 0; start < end; i++) str[i] = *start++;
    str[i] = '\0';
    current->push_back(current, str);
    free(str);
}

static void t(const char *str, const char **start, tuple *stuple, list *list)
{
    if (*str == stuple->_sep || *str == '\"') {
        fill_list(*start, str, list);
        stuple->_state = *str == stuple->_sep ? stuple->_sep : '\"';
    }
}

static void quote(const char *str, const char **start, tuple *stuple)
{
    if (*str == '\"' || *str != stuple->_sep) {
        *start = str;
        stuple->_state = *str == '\"' ? '\"' : 'T';
    }
}

static void split(list *_list, mstat_t *_file)
{
    _file->_length = (int)_list->size(_list);
    if (_list->size(_list)) _file->_parse = _list->copy(_list);
    _list->ldispose(_list);
}

void my_strctok(mstat_t *_file, char _sep)
{
    list *list_l = new_list(NULL);
    char const *start = NULL;
    char *str = _file->_line;
    tuple *stuple = malloc(sizeof *stuple);

    check_strctok();
    *stuple = (tuple){._sep = _sep, ._state = _sep};
    for (; *str; str++) {
        if ('\n' == stuple->_state) continue;
        if (stuple->_sep == stuple->_state) {
            quote(str, &start, stuple);
            continue;
        }
        if ('T' == stuple->_state) t(str, &start, stuple, list_l);
        else if ('\"' == stuple->_state) *str == '\"' ? stuple->_state = 'T' :
        0;
    }
    (stuple->_state != stuple->_sep) ? fill_list(start, str, list_l) : 0;
    free(stuple);
    split(list_l, _file);
}