#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([nihpp], [0.1], [hyperair@ubuntu.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([tests/testptrcreator.cc])
AC_CONFIG_HEADERS([config.h])

AC_PROG_CXX
AC_COMPILE_STDCXX_0X
if test "$ac_cv_cxx_compile_cxx0x_native" = yes; then
    CXX0X_FLAG=""
elif test "$ac_cv_cxx_compile_cxx0x_cxx" = yes; then
    CXX0X_FLAG="-std=c++0x"
else
    AC_MSG_ERROR([C++0x support needed for $PACKAGE])
fi
AC_SUBST([CXX0X_FLAG])

AC_HEADER_STDCXX_0X
if test "$ac_cv_cxx_stdcxx_0x" = no; then
    AC_MSG_ERROR([C++0x headers needed to build $PACKAGE])
fi

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4])
PKG_CHECK_MODULES([SIGC], [sigc++-2.0])

AC_CONFIG_FILES([
    Makefile
    nihpp.pc
])

AC_OUTPUT
