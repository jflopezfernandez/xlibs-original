AC_PREREQ([2.69])
AC_INIT([xlibs], [0.1.0], [jflopezfernandez@gmail.com])
AM_INIT_AUTOMAKE([foreign -Wall])

 # Configure Source and Header Files
AC_CONFIG_SRCDIR([README.md])
AC_CONFIG_HEADER([config.h])

# Check for necessary programs.
AM_PROG_AR
AC_PROG_AWK
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL

# Initialize Libtool.
LT_INIT

# Check for libraries.
#

# Check for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])

# Check for types.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Check for library functions.
AC_CONFIG_FILES([
    Makefile
    mathematics/Makefile
    mathematics/include/Makefile
    mathematics/src/Makefile
    strings/Makefile
    strings/include/Makefile
    strings/src/Makefile
])

# Output configuration-specific build files.
AC_OUTPUT
