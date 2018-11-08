AC_PREREQ([2.69])
AC_INIT([yasjp],
        [0.1.0],
        [vkc1974@gmail.com],
        [yasjp])
AC_CONFIG_HEADERS([include/yasjp-config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([tar-pax -Wno-portability])
LT_INIT

AX_SET_LIBRARY_VERSION(0, 0, 0)
AX_ENABLE_DEBUG_BUILD
AC_PROG_CC
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_11(noext, mandatory)
AC_PROG_LIBTOOL
AM_PROG_LIBTOOL
AC_PROG_YACC
AC_PROG_LEX
AX_CXX_HAVE_STL
AX_CFLAGS_WARN_ALL
AX_CXXFLAGS_WARN_ALL

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    include/Makefile
    test/Makefile])
AC_OUTPUT
