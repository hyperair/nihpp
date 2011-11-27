#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([nih++], [0.1], [hyperair@ubuntu.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([tests/testptrcreator.cc])
AC_CONFIG_HEADERS([config.h])

AC_PROG_CXX
PKG_CHECK_MODULES([GLIBMM], [glibmm-2.4])

AC_CONFIG_FILES([
    Makefile
])

AC_OUTPUT
