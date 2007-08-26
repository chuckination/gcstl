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
## $URL: https://gcstl.svn.sourceforge.net/svnroot/gcstl/trunk/src/queue/Makefile.am $
## $Id: Makefile.am 47 2007-07-22 02:12:41Z chucks $
##
################################################################################

## Process this file with automake to produce Makefile.in -*-Makefile-*-

library_includedir=$(includedir)
library_include_HEADERS = cstl_queue.h

INCLUDES = -I$(top_srcdir)/src/destroy \
           -I$(top_srcdir)/src/list

noinst_LTLIBRARIES = libcstl_queue.la
libcstl_queue_la_SOURCES = cstl_queue.c cstl_queue.h
