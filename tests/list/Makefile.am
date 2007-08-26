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

## Process this file with automake to produce Makefile.in -*-Makefile-*-

#TESTS = test_gcstl_list

INCLUDES = -I$(top_srcdir)

#check_PROGRAMS = test_gcstl_list

EXTRA_PROGRAMS = test_gcstl_list
test_gcstl_list_LDADD = $(top_builddir)/gcstl/libgcstl.la
test_gcstl_list_LDFLAGS = -lcunit
test_gcstl_list_SOURCES = main.c \
                          test_gcstl_list.h test_gcstl_list.c
