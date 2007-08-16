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

#include "cstl_set.h"
#include "cstl_destroy.h"

#include <stdlib.h>

int cstl_set_comparator(void *first,
                        void *second,
                        int (*comparator)(void *, void *))
{
   return comparator(first, second);
}

void cstl_set_destroy_default(void *data,
                              void *arg)
{
   void (*destroy)(void *) = arg;
   destroy(data);
}

/* initialize a set */
int cstl_set_initialize(cstl_set *set,
                        int (*comparator)(void *, void *),
                        void (*destroy)(void *))
{
   return cstl_rbtree_initialize(set,
                                 cstl_set_comparator,
                                 comparator,
                                 cstl_set_destroy_default,
                                 destroy ? destroy : cstl_destroy_default);
}

/* destroy a set */
int cstl_set_destroy(cstl_set *set)
{
   return cstl_rbtree_destroy(set);
}

/* retrieve the number of elements in an set */
int cstl_set_size(cstl_set *set)
{
   return cstl_rbtree_size(set);
}

/* retrieve the data from an set element */
void *cstl_set_data(cstl_set_element *element)
{
   return cstl_set_data(element);
}

/* retrieve the element at the beginning of the linked set */
cstl_set_element *cstl_set_begin(cstl_set *set)
{
   return cstl_rbtree_begin(set);
}

/* retrieve the element at the end of the linked set */
cstl_set_element *cstl_set_end(cstl_set *set)
{
   return cstl_rbtree_end(set);
}

/* retrieve the next set element */
cstl_set_element *cstl_set_next(cstl_set_element *element)
{
   return cstl_rbtree_next(element);
}

/* retrieve the previous set element */
cstl_set_element *cstl_set_prev(cstl_set_element *element)
{
   return cstl_rbtree_next(element);
}

/* insert data into set */
int cstl_set_insert(cstl_set *set,
                    void *data)
{
   return cstl_rbtree_insert(set,
                             data);
}

/* retrieve data from set */
cstl_set_element *cstl_set_find(cstl_set *set,
                                void *data)
{
}

/* remove the element from the set while calling the destroy method */
int cstl_set_remove(cstl_set *set,
                    void *data)
{
   return cstl_rbtree_remove(set,
                             data);
}

/* remove the element from the set while calling the destroy method */
int cstl_set_remove_element(cstl_set_element *element)
{
   return cstl_rbtree_remove_element(element);
}

/* remove the element from the set while not calling the destroy method */
int cstl_set_unlink(cstl_set *set,
                    void *data,
                    void **retData)
{
   return cstl_rbtree_unlink(set,
                             data,
                             retData);
}

/* remove the element from the set while not calling the destroy method */
int cstl_set_unlink_element(cstl_set_element *element,
                            void **retData)
{
   return cstl_rbtree_unlink_element(element,
                                     retData);
}
