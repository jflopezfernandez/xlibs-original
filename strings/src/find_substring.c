/*
 * xlibs - C Programming Language Extensions Libraries
 * Copyright (C) 2020 Jose Fernando Lopez Fernandez
 * 
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <https://www.gnu.org/licenses/>.
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef XLIBS_INTERNAL
#define XLIBS_INTERNAL
#endif

#include "strings.h"

static const char* naive_string_search(const char* needle, const char* haystack) {
    size_t n = strlen(needle);
    size_t h = strlen(haystack);

    for (size_t i = 0; i < h - n; ++i) {
        if (needle[0] == haystack[0 + i]) {
            for (size_t j = 1; j < n; ++j) {
                if (needle[j] != haystack[j + i]) {
                    break;
                }

                if (j == (n -1)) {
                    return haystack + i;
                }
            }
        }
    }
    
    return NULL;
}

static const char* knuth_morris_pratt_string_search(const char* needle, const char* haystack) {
    return NULL;
}

typedef char* (*string_search_function_t)(const char*, const char*);

string_search_function_t get_string_search_function(string_finding_algorithm_t algorithm) {
    switch (algorithm) {
        case NAIVE_STRING_SEARCH: return naive_string_search;
        case KNUTH_MORRIS_PRATT: return knuth_morris_pratt_string_search;
    }
    return naive_string_search;
}

/**
 * Find a string within a string.
 *
 * This function searches the haystack for an instance of
 * the needle.
 *
 * @param[in] algorithm The algorithm to use for the search.
 * @param[in] needle    The substring to look for.
 * @param[in] haystack  The string to look in.
 *
 * @returns Pointer to the located string. If the substring
 * is not found, the returned pointer is equal to NULL.
 *
 */
const char* find_substring(string_finding_algorithm_t algorithm, const char* needle, const char* haystack) {
    return get_string_search_function(algorithm)(needle, haystack);
}
