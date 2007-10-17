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

#ifndef GCSTL_SET_H
#define GCSTL_SET_H

#include <gcstl/gcstl_rbtree.h>

/**
 * @defgroup gcstl gcstl
 * @defgroup set set
 *
 * @ingroup gcstl
 * @ingroup gcstl set
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* typedef wrappers */
typedef gcstl_rbtree_element gcstl_set_element;
typedef gcstl_rbtree gcstl_set;

/* initialize a set */
extern int gcstl_set_initialize(gcstl_set *set,
                               int (*comparator)(void *, void *),
                               void (*destroy)(void *));

/* destroy a set */
extern int gcstl_set_destroy(gcstl_set *set);

/* retrieve the number of elements in an set */
extern int gcstl_set_size(gcstl_set *set);

/* retrieve the data from an set element */
extern void *gcstl_set_data(gcstl_set_element *element);

/* retrieve the element at the beginning of the linked set */
extern gcstl_set_element *gcstl_set_begin(gcstl_set *set);

/* retrieve the element at the end of the linked set */
extern gcstl_set_element *gcstl_set_end(gcstl_set *set);

/* retrieve the next set element */
extern gcstl_set_element *gcstl_set_next(gcstl_set_element *element);

/* retrieve the previous set element */
extern gcstl_set_element *gcstl_set_prev(gcstl_set_element *element);

/* insert data into set */
extern int gcstl_set_insert(gcstl_set *set,
                           void *data);

/* retrieve data from set */
extern gcstl_set_element *gcstl_set_find(gcstl_set *set,
                                       void *data);

/* remove the element from the set while calling the destroy method */
extern int gcstl_set_remove(gcstl_set *set,
                           void *data);

/* remove the element from the set while calling the destroy method */
extern int gcstl_set_remove_element(gcstl_set_element *element);

/* remove the element from the set while not calling the destroy method */
extern int gcstl_set_unlink(gcstl_set *set,
                           void *data,
                           void **retData);

/* remove the element from the set while not calling the destroy method */
extern int gcstl_set_unlink_element(gcstl_set_element *element,
                                   void **retData);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif
