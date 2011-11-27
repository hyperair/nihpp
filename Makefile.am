AM_CXXFLAGS = -std=c++0x
include_HEADERS =				\
	nihpp/ptrcreator.hh			\
	nihpp/sharedptrcreator.hh		\
	nihpp/glib/refptrcreator.hh

TESTS = tests/testptrcreator
check_PROGRAMS = tests/testptrcreator
tests_testptrcreator_SOURCES = tests/testptrcreator.cc
tests_testptrcreator_CXXFLAGS = $(GLIBMM_CFLAGS) $(AM_CXXFLAGS)
tests_testptrcreator_LDADD = $(GLIBMM_LIBS)
