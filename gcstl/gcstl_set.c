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

#include <gcstl/gcstl_set.h>
#include <gcstl/gcstl_destroy.h>

#include <stdlib.h>

int gcstl_set_comparator(void *first,
                        void *second,
                        int (*comparator)(void *, void *))
{
   return comparator(first, second);
}

void gcstl_set_destroy_default(void *data,
                              void *arg)
{
   void (*destroy)(void *) = arg;
   destroy(data);
}

/* initialize a set */
int gcstl_set_initialize(gcstl_set *set,
                        int (*comparator)(void *, void *),
                        void (*destroy)(void *))
{
   return gcstl_rbtree_initialize(set,
                                 gcstl_set_comparator,
                                 comparator,
                                 gcstl_set_destroy_default,
                                 destroy ? destroy : gcstl_destroy_default);
}

/* destroy a set */
int gcstl_set_destroy(gcstl_set *set)
{
   return gcstl_rbtree_destroy(set);
}

/* retrieve the number of elements in an set */
int gcstl_set_size(gcstl_set *set)
{
   return gcstl_rbtree_size(set);
}

/* retrieve the data from an set element */
void *gcstl_set_data(gcstl_set_element *element)
{
   return gcstl_set_data(element);
}

/* retrieve the element at the beginning of the linked set */
gcstl_set_element *gcstl_set_begin(gcstl_set *set)
{
   return gcstl_rbtree_begin(set);
}

/* retrieve the element at the end of the linked set */
gcstl_set_element *gcstl_set_end(gcstl_set *set)
{
   return gcstl_rbtree_end(set);
}

/* retrieve the next set element */
gcstl_set_element *gcstl_set_next(gcstl_set_element *element)
{
   return gcstl_rbtree_next(element);
}

/* retrieve the previous set element */
gcstl_set_element *gcstl_set_prev(gcstl_set_element *element)
{
   return gcstl_rbtree_next(element);
}

/* insert data into set */
int gcstl_set_insert(gcstl_set *set,
                    void *data)
{
   return gcstl_rbtree_insert(set,
                             data);
}

/* retrieve data from set */
gcstl_set_element *gcstl_set_find(gcstl_set *set,
                                void *data)
{
}

/* remove the element from the set while calling the destroy method */
int gcstl_set_remove(gcstl_set *set,
                    void *data)
{
   return gcstl_rbtree_remove(set,
                             data);
}

/* remove the element from the set while calling the destroy method */
int gcstl_set_remove_element(gcstl_set_element *element)
{
   return gcstl_rbtree_remove_element(element);
}

/* remove the element from the set while not calling the destroy method */
int gcstl_set_unlink(gcstl_set *set,
                    void *data,
                    void **retData)
{
   return gcstl_rbtree_unlink(set,
                             data,
                             retData);
}

/* remove the element from the set while not calling the destroy method */
int gcstl_set_unlink_element(gcstl_set_element *element,
                            void **retData)
{
   return gcstl_rbtree_unlink_element(element,
                                     retData);
}
