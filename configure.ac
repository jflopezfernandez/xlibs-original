AC_PREREQ([2.69])
AC_INIT([xlibs], [0.1.0], [jflopezfernandez@gmail.com])
AM_INIT_AUTOMAKE([foreign -Wall])
AM_PROG_AR

# Initialize Libtool.
LT_PREREQ([2.4.6])
LT_INIT

# Define the project language.
AC_LANG([C])

# Configure configuration macros directory.
AC_CONFIG_MACRO_DIRS([m4])

 # Configure Source and Header Files
AC_CONFIG_SRCDIR([README.md])
AC_CONFIG_HEADER([config.h])

# Check for necessary programs.
AC_PROG_AWK
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_INSTALL

# Check for compiler attributes.
#AX_C__ATTRIBUTE__
#AC_LANG_C
#AC_PROG_CC_C99
#AC_PROG_CC_STDC
#AX_C99_INLINE
#AX_CHECK_X86_FEATURES
#AX_INSTALL_FILES

# Check for command-line options specified by the user.
AC_ARG_ENABLE([debug],
    [AS_HELP_STRING([--enable-debug],
        [enable debug code (default is no)])],
    [debug="$withval"],
    [debug=no])

AC_ARG_ENABLE([mathematics],
    [  --disable-mathematics   don't build the math library],
    [mathematics_enabled=${enableval}], [mathematics_enabled=yes])

AC_MSG_CHECKING([Checking whether to build mathematics library])

if test "x${mathematics_enabled}" = xno
then
    AC_MSG_RESULT([no])
else
    AC_MSG_RESULT([yes])
    #AC_DEFINE([MATHEMATICS], [1], [])
fi

AC_ARG_ENABLE([strings],
    [  --disable-strings       don't build the strings library],
    [strings_enabled=${enabledval}], [strings_enabled=yes])

AC_MSG_CHECKING([Checking whether to build strings library])

if test "x${strings_enabled}" = xno
then
    AC_MSG_RESULT([no])
else
    AC_MSG_RESULT([yes])
    #AC_DEFINE([STRINGS], [1], [])
fi

# Create Automake conditional based on the DOXYGEN variable.
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])
#AS_IF([test -n "$DOXYGEN"], [AC_CONFIG_FILES([docs/Doxyfile])])
AS_IF([test -n "$DOXYGEN"], [AC_MSG_NOTICE([Doxygen found])])

# Check for libraries.
#

# Check for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])

# Check for types.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
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
