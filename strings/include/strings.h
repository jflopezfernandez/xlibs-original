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

#ifndef PROJECT_INCLUDES_XLIBS_STRINGS_H
#define PROJECT_INCLUDES_XLIBS_STRINGS_H

typedef enum {
    LEVENSHTEIN_DISTANCE,
    LONGEST_COMMON_SUBSEQUENCE,
    HAMMING_DISTANCE,
    DAMERAU_LEVENSHTEIN_DISTANCE,
    JARO_DISTANCE
} edit_distance_type_t;

// size_t calculate_levenshtein_distance(const char* a, const char* b);
// size_t calculate_longest_common_subsequence_distance(const char* a, const char* b);
// size_t calculate_hamming_distance(const char* a, const char* b);
// size_t calculate_damerau_levenshtein_distance(const char* a, const char* b);
// size_t calculate_jaro_distance(const char* a, const char* b);

//typedef size_t (*edit_distance_function_t)(const char*, const char*);

//edit_distance_function_t get_edit_distance_function(edit_distance_type_t edit_distance_type);

size_t calculate_edit_distance(edit_distance_type_t edit_distance_type, const char* a, const char* b);

/*
 * Calculate the length of the given string.
 *
 * The function returns the length of the string pointed to
 * by <U>string</U>, excluding the null terminator.
 *
 * @param[in] string Pointer to null-terminated string.
 *
 * @returns Length of the given string, minus null terminator.
 *
 */
size_t
__attribute__((nonnull(1)))
string_length(const char* string);

#endif /** PROJECT_INCLUDES_XLIBS_STRINGS_H */
