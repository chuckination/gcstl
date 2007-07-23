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

#TESTS = test_cstl_rbtree

INCLUDES = -I$(top_srcdir)/src/destroy \
           -I$(top_srcdir)/src/rbtree

#check_PROGRAMS = test_cstl_rbtree

EXTRA_PROGRAMS = test_cstl_rbtree
test_cstl_rbtree_LDADD = $(top_builddir)/src/destroy/libcstl_destroy.la \
                         $(top_builddir)/src/rbtree/libcstl_rbtree.la
test_cstl_rbtree_LDFLAGS = -lcunit
test_cstl_rbtree_SOURCES = main.c \
                           test_cstl_rbtree.h test_cstl_rbtree.c
