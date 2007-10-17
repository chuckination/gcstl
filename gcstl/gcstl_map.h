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

#ifndef GCSTL_MAP_H
#define GCSTL_MAP_H

#include <gcstl/gcstl_rbtree.h>

/*!
 * @defgroup gcstl gcstl
 * @defgroup map map
 *
 * @ingroup gcstl
 * @ingroup gcstl map
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* typedef wrappers */
typedef struct gcstl_map_pair gcstl_map_pair;
typedef gcstl_rbtree_element gcstl_map_element;
typedef struct gcstl_map_destroy_arg gcstl_map_destroy_arg;
typedef struct gcstl_map gcstl_map;

/* a map element */
struct gcstl_map_pair
{
   void *key;
   void *value;
};

/* a map destroy collection */
struct gcstl_map_destroy_arg
{
   void (*destroy_key)(void *);
   void (*destroy_value)(void *);
};

/* a map */
struct gcstl_map
{
   gcstl_rbtree *rbtree;
   gcstl_map_destroy_arg *destroy_arg;
};

/* initialize a map */
extern int gcstl_map_initialize(gcstl_map *map,
                               int (*comparator)(void *, void *),
                               void (*destroy_key)(void *),
                               void (*destroy_value)(void *));

/* destroy a map */
extern int gcstl_map_destroy(gcstl_map *map);

/* retrieve the number of elements in an map */
extern int gcstl_map_size(gcstl_map *map);

/* retrieve the data from an map element */
extern void *gcstl_map_data(gcstl_map_element *element);

/* retrieve the element at the beginning of the linked map */
extern gcstl_map_element *gcstl_map_begin(gcstl_map *map);

/* retrieve the element at the end of the linked map */
extern gcstl_map_element *gcstl_map_end(gcstl_map *map);

/* retrieve the next map element */
extern gcstl_map_element *gcstl_map_next(gcstl_map_element *element);

/* retrieve the previous map element */
extern gcstl_map_element *gcstl_map_prev(gcstl_map_element *element);

/* insert data into map */
extern int gcstl_map_insert(gcstl_map *map,
                           void *key,
                           void *value);

/* retrieve data from map */
extern gcstl_map_element *gcstl_map_find(gcstl_map *map,
                                       void *key);

/* remove the element from the map while calling the destroy method */
extern int gcstl_map_remove(gcstl_map *map,
                           void *key);

/* remove the element from the map while calling the destroy method */
extern int gcstl_map_remove_element(gcstl_map_element *element);

/* remove the element from the map while not calling the destroy method */
extern int gcstl_map_unlink(gcstl_map *map,
                           void *key,
                           void **retData);

/* remove the element from the map while not calling the destroy method */
extern int gcstl_map_unlink_element(gcstl_map_element *element,
                                   void **retData);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif
