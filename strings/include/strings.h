/*
 * Xlibs - C Programming Language Extensions Library
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
__attributes_string_length
string_length(const char* string);

#endif /** PROJECT_INCLUDES_XLIBS_STRINGS_H */
