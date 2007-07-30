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

#ifndef CSTL_MAP_H
#define CSTL_MAP_H

#include "cstl_rbtree.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* typedef wrappers */
typedef struct cstl_map_element cstl_map_element;
typedef struct cstl_map cstl_map;

/* a map element */
struct cstl_map_element
{
   cstl_rbtree_element *rbtree_element;
   void *first;
   void *second;
};

/* a map */
struct cstl_map
{
   cstl_rbtree *rbtree;
};

/* initialize a map */
extern int cstl_map_initialize(cstl_map *map,
                               int (*comparator)(void *, void *),
                               void (*destroy)(void *));

/* destroy a map */
extern int cstl_map_destroy(cstl_map *map);

/* retrieve the number of elements in an map */
extern int cstl_map_size(cstl_map *map);

/* retrieve the data from an map element */
extern void *cstl_map_data(cstl_map_element *element);

/* retrieve the element at the beginning of the linked map */
extern cstl_map_element *cstl_map_begin(cstl_map *map);

/* retrieve the element at the end of the linked map */
extern cstl_map_element *cstl_map_end(cstl_map *map);

/* retrieve the next map element */
extern cstl_map_element *cstl_map_next(cstl_map_element *element);

/* retrieve the previous map element */
extern cstl_map_element *cstl_map_prev(cstl_map_element *element);

/* insert data into map */
extern int cstl_map_insert(cstl_map *map,
                           void *data);

/* retrieve data from map */
extern cstl_map_element *cstl_map_find(cstl_map *map,
                                       void *data);

/* remove the element from the map while calling the destroy method */
extern int cstl_map_remove(cstl_map *map,
                           void *data);

/* remove the element from the map while calling the destroy method */
extern int cstl_map_remove_element(cstl_map_element *element);

/* remove the element from the map while not calling the destroy method */
extern int cstl_map_unlink(cstl_map *map,
                           void *data,
                           void **retData);

/* remove the element from the map while not calling the destroy method */
extern int cstl_map_unlink_element(cstl_map_element *element,
                                   void **retData);

#ifdef __cplusplus
}
#endif

#endif
