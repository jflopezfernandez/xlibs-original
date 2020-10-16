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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef XLIBS_INTERNAL
#define XLIBS_INTERNAL
#endif

#include "strings.h"

static size_t calculate_levenshtein_distance(const char* a, const char* b) {
    return 0;
}

static size_t calculate_longest_common_subsequence_distance(const char* a, const char* b) {
    return 0;
}

static size_t calculate_hamming_distance(const char* a, const char* b) {
    return 0;
}

static size_t calculate_damerau_levenshtein_distance(const char* a, const char* b) {
    return 0;
}

static size_t calculate_jaro_distance(const char* a, const char* b) {
    return 0;
}

typedef size_t (*edit_distance_function_t)(const char*, const char*);

static edit_distance_function_t get_edit_distance_function(edit_distance_type_t edit_distance_type) {
    /**
     * @remark We initialize the edit distance function
     * pointer to Levenshtein distance here because it is
     * not possible to point a function pointer to NULL.
     *
     * @todo The default edit distance should probably be
     * configurable by the end-user during initial library
     * configuration.
     *
     */
    edit_distance_function_t edit_distance_function = NULL;

    switch (edit_distance_type) {
        case LEVENSHTEIN_DISTANCE: {
            edit_distance_function = calculate_levenshtein_distance;
        } break;

        case LONGEST_COMMON_SUBSEQUENCE: {
            edit_distance_function = calculate_longest_common_subsequence_distance;
        } break;

        case HAMMING_DISTANCE: {
            edit_distance_function = calculate_hamming_distance;
        } break;

        case DAMERAU_LEVENSHTEIN_DISTANCE: {
            edit_distance_function = calculate_damerau_levenshtein_distance;
        } break;

        case JARO_DISTANCE: {
            edit_distance_function = calculate_jaro_distance;
        } break;

        default: {
            /**
             * The default action here will be to let the user know
             * we were unable to recognize a valid edit distance
             * metric based on the value they specified. We then let
             * them know we will be reverting to the default, and we
             * return whatever the default function is configured to
             * be.
             *
             */
            fprintf(stderr, "[Error] %s\n", "Distance metric not recognized. Reverting to the default value.");
        } break;
    }

    /** Return the edit distance function pointer. */
    return edit_distance_function;
}

size_t calculate_edit_distance(edit_distance_type_t edit_distance_type, const char* a, const char* b) {
    return get_edit_distance_function(edit_distance_type)(a,b);
}
