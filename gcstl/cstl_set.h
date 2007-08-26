/* Copyright (C) 2007, Charles Stewart */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

/*******************************************************************************
 *
 * $URL: svn+ssh://hades/var/svn/cstl/trunk/src/rbtree/cstl_rbtree.h $
 * $Id: cstl_rbtree.h 46 2007-07-22 00:11:23Z chucks $
 *
 ******************************************************************************/

#ifndef CSTL_SET_H
#define CSTL_SET_H

#include "gcstl/cstl_rbtree.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* typedef wrappers */
typedef cstl_rbtree_element cstl_set_element;
typedef cstl_rbtree cstl_set;

/* initialize a set */
extern int cstl_set_initialize(cstl_set *set,
                               int (*comparator)(void *, void *),
                               void (*destroy)(void *));

/* destroy a set */
extern int cstl_set_destroy(cstl_set *set);

/* retrieve the number of elements in an set */
extern int cstl_set_size(cstl_set *set);

/* retrieve the data from an set element */
extern void *cstl_set_data(cstl_set_element *element);

/* retrieve the element at the beginning of the linked set */
extern cstl_set_element *cstl_set_begin(cstl_set *set);

/* retrieve the element at the end of the linked set */
extern cstl_set_element *cstl_set_end(cstl_set *set);

/* retrieve the next set element */
extern cstl_set_element *cstl_set_next(cstl_set_element *element);

/* retrieve the previous set element */
extern cstl_set_element *cstl_set_prev(cstl_set_element *element);

/* insert data into set */
extern int cstl_set_insert(cstl_set *set,
                           void *data);

/* retrieve data from set */
extern cstl_set_element *cstl_set_find(cstl_set *set,
                                       void *data);

/* remove the element from the set while calling the destroy method */
extern int cstl_set_remove(cstl_set *set,
                           void *data);

/* remove the element from the set while calling the destroy method */
extern int cstl_set_remove_element(cstl_set_element *element);

/* remove the element from the set while not calling the destroy method */
extern int cstl_set_unlink(cstl_set *set,
                           void *data,
                           void **retData);

/* remove the element from the set while not calling the destroy method */
extern int cstl_set_unlink_element(cstl_set_element *element,
                                   void **retData);

#ifdef __cplusplus
}
#endif

#endif
