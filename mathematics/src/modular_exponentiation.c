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

#ifndef XLIBS_INTERNAL
#define XLIBS_INTERNAL
#endif

#include "mathematics.h"

/**
 * Modular Exponentiation
 *
 * This function uses the binary representation of \f$b\f$
 * to efficiently perform exponentiation. The method relies
 * on repeated squaring, as described by Cormen, et. al., in
 * <I>Introduction to Algorithms</I>. The result of this
 * function is equal to the following equation.
 * \f[d = a^b \text{mod }d\f]
 *
 *
 * @param[in] a Number to raise to a power.
 * @param[in] b The power to raise \f$a\f$ to.
 * @param[in] d The modulus to reduce \f$a^b\f$ by.
 *
 * @returns The result of the above equation.
 *
 * @cite cormen_introduction_2009
 *
 */
int modular_exponentiation(int a, int b, int n) {
    int c = 0;
    int d = 1;

    for (size_t i = sizeof (int) - 1; i != (size_t) -1; --i) {
        c *= 2;
        d = (d * d) % n;

        if ((b >> i) & 1) {
            ++c;
            d = (d * a) % n;
        }
    }

    return d;
}
