ACLOCAL_AMFLAGS = -Im4

AM_CXXFLAGS = $(CXX0X_FLAG)
nihppdir = $(includedir)/nihpp
nihpp_glibdir = $(nihppdir)/glib
nihpp_HEADERS =					\
	nihpp/ptrcreator.hh			\
	nihpp/sharedptrcreator.hh

nihpp_glib_HEADERS =				\
	nihpp/glib/refptrcreator.hh

TESTS = tests/testptrcreator
check_PROGRAMS = tests/testptrcreator
tests_testptrcreator_SOURCES = tests/testptrcreator.cc
tests_testptrcreator_CXXFLAGS = $(GLIBMM_CFLAGS) $(AM_CXXFLAGS)
tests_testptrcreator_LDADD = $(GLIBMM_LIBS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = nihpp.pc
