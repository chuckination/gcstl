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

library_includedir=$(includedir)/gcstl
library_include_HEADERS = \
                          gcstl_destroy.h \
                          gcstl_list.h \
                          gcstl_stack.h \
                          gcstl_queue.h \
                          gcstl_rbtree.h \
                          gcstl_set.h \
                          gcstl_map.h

INCLUDES = -I$(top_srcdir)
lib_LTLIBRARIES = libgcstl.la
libgcstl_la_SOURCES = \
                      gcstl_destroy.c \
                      gcstl_list.c \
                      gcstl_stack.c \
                      gcstl_queue.c \
                      gcstl_rbtree.c \
                      gcstl_set.c \
                      gcstl_map.c
libgcstl_la_LDFLAGS = -version-info $(GENERIC_LIBRARY_VERSION) -release $(GENERIC_RELEASE)
