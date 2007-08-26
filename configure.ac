## Copyright (C) 2007, Charles Stewart

## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.

## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.

## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software Foundation,
## Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */


################################################################################
##
## $URL$
## $Id$
##
################################################################################

## -*- autoconf -*-
## Process this file with autoconf to produce a configure script.

AC_INIT(gcstl/cstl.h)
AC_CONFIG_AUX_DIR(autoconf)
AM_CONFIG_HEADER(config.h)

GENERIC_LIBRARY_NAME=cstl
GENERIC_PACKAGE_DESCRIPTION="Standard Template Library for C"
GENERIC_MAJOR_VERSION=0
GENERIC_MINOR_VERSION=3
GENERIC_MICRO_VERSION=0
GENERIC_API_VERSION=0.3
GENERIC_LIBRARY_VERSION=0:3:0

GENERIC_VERSION=$GENERIC_MAJOR_VERSION.$GENERIC_MINOR_VERSION.$GENERIC_MICRO_VERSION
GENERIC_RELEASE=$GENERIC_MAJOR_VERSION.$GENERIC_MINOR_VERSION

AC_SUBST(GENERIC_LIBRARY_NAME)
AC_SUBST(GENERIC_PACKAGE_DESCRIPTION)
AC_SUBST(GENERIC_API_VERSION)
AC_SUBST(GENERIC_LIBRARY_VERSION)
AC_SUBST(GENERIC_VERSION)
AC_SUBST(GENERIC_RELEASE)

PACKAGE=$GENERIC_LIBRARY_NAME
VERSION=$GENERIC_VERSION

AM_INIT_AUTOMAKE($PACKAGE, $VERSION)

AC_PROG_CC
AC_PROG_LIBTOOL

AM_SANITY_CHECK
AC_FUNC_MALLOC

AC_OUTPUT(Makefile \
          cstl.pc \
          gcstl/Makefile \
			 tests/Makefile \
          tests/destroy/Makefile \
          tests/list/Makefile \
          tests/rbtree/Makefile)
