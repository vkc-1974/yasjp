AC_PREREQ([2.69])
AC_INIT([yasjp],
        [0.1.0],
        [vkc1974@gmail.com],
        [yasjp])
AC_CONFIG_HEADERS([include/yasjp-config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([tar-pax -Wno-portability])
AX_CHECK_ENABLE_DEBUG([no])
AX_IS_RELEASE(always)
LT_INIT

AC_DEFUN([AX_SET_LIBRARY_VERSION],[
   CURRENT=$1
   RELEASE=$2
   AGE=$3
   AS_IF([test -z $CURRENT], [CURRENT=0])
   AS_IF([test -z $RELEASE], [RELEASE=0])
   AS_IF([test -z $AGE], [AGE=0])
   AC_SUBST(LIBRARY_VERSION_CURRENT, $CURRENT)
   AC_SUBST(LIBRARY_VERSION_RELEASE, $RELEASE)
   AC_SUBST(LIBRARY_VERSION_AGE, $AGE)
   AC_SUBST(LIBTOOL_LIBRARY_VERSION_FLAGS, "-version-info $CURRENT:$RELEASE:$AGE")
   AC_MSG_NOTICE([Libraries version (c:r:a): $CURRENT:$RELEASE:$AGE])
])

AX_SET_LIBRARY_VERSION(0, 0, 0)
AC_PROG_CC
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_17(noext, mandatory)
dnl AC_PROG_LIBTOOL
AM_PROG_LIBTOOL
AC_PATH_PROG([FLEX],[flex])
AX_PROG_FLEX_VERSION([2.6.4])
AC_PATH_PROG([BISON],[bison])
AX_PROG_BISON_VERSION([3.2])
dnl AC_PROG_YACC
dnl AC_PROG_LEX
AX_CXX_HAVE_STL
AX_CFLAGS_WARN_ALL
AX_CXXFLAGS_WARN_ALL

m4_ifndef([PKG_PREREQ],
          [m4_fatal([must install pkg-config 0.29 or later before running autoconf/autogen])])

PKG_CHECK_MODULES(CATCH2, catch2)
AC_MSG_NOTICE([catch2 CFLAGS: $CATCH2_CFLAGS])
AC_MSG_NOTICE([catch2 LIBS: $CATCH_LIBS])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    include/Makefile
    test/Makefile])
AC_OUTPUT
