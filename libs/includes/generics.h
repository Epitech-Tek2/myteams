/*
** EPITECH PROJECT, 2021
** teams
** File description:
** generics
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Get the name of a type */
#define typename(x) _Generic((x), \
    _Bool: "_Bool", \
    unsigned char: "unsigned char", \
    char: "char", \
    signed char: "signed char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int",\
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "char *", \
    void *: "void *", \
    int *: "int *", \
    char **: "char **", \
    default: "other")

/* maybe can do some stuff like Template<T> in c++ */
#define printf_dec_format(x) _Generic((x), \
    char: "%c\n", \
    bool: "%d\n", \
    signed char: "%hhd\n", \
    unsigned char: "%hhu\n", \
    signed short: "%hd\n", \
    unsigned short: "%hu\n", \
    signed int: "%d\n", \
    unsigned int: "%u\n", \
    long int: "%ld\n", \
    unsigned long int: "%lu\n", \
    long long int: "%lld\n", \
    unsigned long long int: "%llu\n", \
    str_const_restrict: "%s\n", \
    const char *: "%s\n", \
    float: "%f\n", \
    double: "%f\n", \
    long double: "%Lf\n", \
    char *: "%s\n", \
    void *: "%p\n")

static __always_inline bool compare_cc(char a, char b)
{
    return a == b;
}

static __always_inline int compare_ss(char *a, char *b)
{
    return strcmp(a, b);
}

static __always_inline int compare_pp(void *a, void *b)
{
    return a > b ? a - b : b - a;
}

#define _G2_compare(ParamB,ParamA_Type, TypeB1) \
    ParamA_Type: _Generic((ParamB), \
        char *: compare_ss, \
        char: compare_cc, \
        void *: compare_pp, \
        int: compare_cc)

#define _compare(a, b) _Generic((a), \
    _G2_compare(b,char *,char *), \
    _G2_compare(b,char,char), \
    _G2_compare(b,void *,void *), \
    _G2_compare(b,int,int)) (a,b)

/**
* @brief Compare _T and _Y template<typename _T, typename _Y>
*
* @param numbers <int int> pair of numbers.
* @param char <char char> pair of char.
* @param strings <char * char *> pair of strings.
* @param pointers <void * void *> pair of pointers.
*
* @return Boolean or difference for strings
*/
#define ccompare(a, b) _compare(a, b)

#define _print(x) printf(printf_dec_format(x), x)

#define print(x, ...) _print(x)