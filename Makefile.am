ACLOCAL_AMFLAGS = -Im4

AM_CXXFLAGS = $(CXX0X_FLAG)
nihppdir = $(includedir)/nihpp
nihpp_glibdir = $(nihppdir)/glib
nihpp_sigcdir = $(nihppdir)/sigc++
nihpp_HEADERS =					\
	nihpp/ptrcreator.hh			\
	nihpp/sharedptrcreator.hh		\
	nihpp/singleton.hh

nihpp_glib_HEADERS =				\
	nihpp/glib/refptrcreator.hh

nihpp_sigc_HEADERS =				\
	nihpp/sigc++/fixfunctors.hh

TESTS = $(check_PROGRAMS)
check_PROGRAMS =				\
	tests/testptrcreator			\
	tests/testsingleton

tests_testptrcreator_SOURCES = tests/testptrcreator.cc
tests_testptrcreator_CXXFLAGS = $(GLIBMM_CFLAGS) $(AM_CXXFLAGS)
tests_testptrcreator_LDADD = $(GLIBMM_LIBS)

tests_testsingleton_SOURCES = tests/testsingleton.cc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = nihpp.pc
