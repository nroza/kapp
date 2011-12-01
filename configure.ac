#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT( kapp, 0.0.1, andy.cap@nowhere.com )
AC_PROG_LIBTOOL
AM_INIT_AUTOMAKE
dnl LT_PREREQ([2.2])
dnl LT_INIT([dlopen])
AC_LANG([C++])
AC_CONFIG_SRCDIR([kapp_common.am])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AM_PROG_CC_C_O

# Checks for libraries.
dnl AC_CHECK_LIB([boost_system])

# Checks for header files.
AC_CHECK_HEADERS([string iomanip iostream])
AC_CHECK_HEADERS([boost/asio.hpp])
AC_CHECK_HEADERS([boost/phoenix.hpp])
AC_CHECK_HEADERS([boost/preprocessor.hpp])
AC_CHECK_HEADERS([boost/lexical_cast.hpp])
AC_CHECK_HEADERS([boost/preprocessor.hpp])
AC_CHECK_HEADERS([boost/date_time.hpp])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
dnl AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

AC_CONFIG_FILES([Makefile
                 jupiter/Makefile
                 cutil/Makefile])

AC_OUTPUT
