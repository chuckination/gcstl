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

library_includedir=$(includedir)
library_include_HEADERS = \
                          cstl.h \
                          cstl_destroy.h \
                          cstl_list.h \
                          cstl_stack.h \
                          cstl_queue.h \
                          cstl_rbtree.h \
                          cstl_set.h \
                          cstl_map.h

INCLUDES = -I$(top_srcdir)
lib_LTLIBRARIES = libcstl.la
libcstl_la_SOURCES = \
                     cstl_destroy.c \
                     cstl_list.c \
                     cstl_stack.c \
                     cstl_queue.c \
                     cstl_rbtree.c \
                     cstl_set.c \
                     cstl_map.c
libcstl_la_LDFLAGS = -version-info $(GENERIC_LIBRARY_VERSION) -release $(GENERIC_RELEASE)
