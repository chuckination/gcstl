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

SUBDIRS =  destroy \
           list \
           rbtree

TESTS = test_cstl

INCLUDES = -I$(top_srcdir)

check_PROGRAMS = test_cstl
test_cstl_LDADD = $(top_builddir)/gcstl/libcstl.la
test_cstl_LDFLAGS = -lcunit
test_cstl_SOURCES = main.c \
                    destroy/test_cstl_destroy.h destroy/test_cstl_destroy.c \
                    list/test_cstl_list.h list/test_cstl_list.c \
                    rbtree/test_cstl_rbtree.h rbtree/test_cstl_rbtree.c
