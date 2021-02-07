CXXFLAGS_COMMON = \
	-I../include \
	@CATCH2_CFLAGS@

LDFLAGS_COMMON = \
	@CATCH2_LIBS@ \
	-static-libtool-libs ../src/libyasjp.la

DEPENDENCIES_COMMON = \
	../src/libyasjp.la

noinst_PROGRAMS = \
	unit-test-1

unit_test_1_SOURCES = \
	UnitTest-1.cpp

unit_test_1_CXXFLAGS = \
	${CXXFLAGS_COMMON}

unit_test_1_LDFLAGS = \
	${LDFLAGS_COMMON}

unit_test_1_DEPENDENCIES = \
	${DEPENDENCIES_COMMON}
