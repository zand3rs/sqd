dnl
dnl    ____  |
dnl         /     Alexander A. Magtipon
dnl       /       zander - zand3rs@gmail.com
dnl     /         Copyright 2013
dnl  _______|
dnl
dnl

AC_INIT([sqd], [0.0.1])
AM_INIT_AUTOMAKE
AM_PATH_CPPUNIT(1.9.6)

COPYRIGHT="2013"
BUILD_DATE="$(date +%F)"
BUILD_YEAR="${BUILD_DATE%%-*}"

if test "$COPYRIGHT" -lt "$BUILD_YEAR"; then
  COPYRIGHT="$COPYRIGHT-$BUILD_YEAR"
fi

AC_CONFIG_HEADER([config.h])

AH_TEMPLATE([BUILD_DATE], [Build date])
AH_TEMPLATE([COPYRIGHT],  [Copyright])
AH_TEMPLATE([__DEBUG__],  [Debug flag])
AH_TEMPLATE([__DEVEL__],  [Development flag])

AC_DEFINE_UNQUOTED([BUILD_DATE], "$BUILD_DATE")
AC_DEFINE_UNQUOTED([COPYRIGHT],  "$COPYRIGHT")

AC_ARG_ENABLE([devel], 
              AC_HELP_STRING([--enable-devel], 
              [Enable development mode]), 
              [AC_DEFINE([__DEVEL__],[],[])])

dnl Checks for header files.
AC_HEADER_STDC

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_CC
AC_PROG_INSTALL

dnl Checks for libraries.
AC_CHECK_LIB(pthread, pthread_create, ,AC_MSG_ERROR([pthread_create not functioning]))
AC_CHECK_LIB(socket, socket)
AC_CHECK_LIB(nsl, main)
AC_CHECK_LIB(rt, main)
AC_CHECK_LIB(dl, main)

dnl Use -Wall if we have gcc.
changequote(,)dnl
if test "x$GCC" = "xyes"; then
  case " $CFLAGS " in
  *[\ \	]-Wall[\ \	]*) ;;
  *) CFLAGS="$CFLAGS -Wall" ;;
  esac
fi
changequote([,])dnl

AC_OUTPUT([
  Makefile 
  src/Makefile
  etc/Makefile
  test/Makefile
])

