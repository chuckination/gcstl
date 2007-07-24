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
 * $URL$
 * $Id$
 *
 ******************************************************************************/

#ifndef CSTL_RBTREE_H
#define CSTL_RBTREE_H

#ifdef __cplusplus
extern "C"
{
#endif

/* red-black tree color enumeration */
typedef enum cstl_rbtree_element_color
{
   RED,
   BLACK
} cstl_rbtree_element_color;

/* forward declarations */
typedef struct cstl_rbtree_element cstl_rbtree_element;
typedef struct cstl_rbtree cstl_rbtree;

/* a red-black tree element */
struct cstl_rbtree_element
{
   cstl_rbtree *rbtree;
   cstl_rbtree_element *parent;
   cstl_rbtree_element *left;
   cstl_rbtree_element *right;
   cstl_rbtree_element_color color;
   void *data;
};

/* a red-black tree */
struct cstl_rbtree
{
   cstl_rbtree_element *root;
   cstl_rbtree_element *end;
   unsigned long int size;
   short int validator;
   int (*comparator)(void *, void *, void *);
   void (*destroy)(void *, void *);
};

/* initialize a red-black tree */
extern int cstl_rbtree_initialize(cstl_rbtree *rbtree,
                                  int (*comparator)(void *, void *, void *),
                                  void (*destroy)(void *, void *));

/* destroy a red-black tree */
extern int cstl_rbtree_destroy(cstl_rbtree *rbtree);

/* retrieve the number of elements in an rbtree */
extern int cstl_rbtree_size(cstl_rbtree *rbtree);

/* retrieve the data from an rbtree element */
extern void *cstl_rbtree_data(cstl_rbtree_element *element);

/* retrieve the element at the beginning of the linked rbtree */
extern cstl_rbtree_element *cstl_rbtree_begin(cstl_rbtree *rbtree);

/* retrieve the element at the end of the linked rbtree */
extern cstl_rbtree_element *cstl_rbtree_end(cstl_rbtree *rbtree);

/* retrieve the next rbtree element */
extern cstl_rbtree_element *cstl_rbtree_next(cstl_rbtree_element *element);

/* retrieve the previous rbtree element */
extern cstl_rbtree_element *cstl_rbtree_prev(cstl_rbtree_element *element);

/* insert data into rbtree */
extern int cstl_rbtree_insert(cstl_rbtree *rbtree,
                              void *data);

/* retrieve data from rbtree */
extern cstl_rbtree_element *cstl_rbtree_find(cstl_rbtree *rbtree,
                                             void *data);

/* remove the element from the rbtree while calling the destroy method */
extern int cstl_rbtree_remove(cstl_rbtree *rbtree,
                              void *data);

/* remove the element from the rbtree while calling the destroy method */
extern int cstl_rbtree_remove_element(cstl_rbtree_element *element);

/* remove the element from the rbtree while not calling the destroy method */
extern int cstl_rbtree_unlink(cstl_rbtree *rbtree,
                              void *data,
                              void **retData);

/* remove the element from the rbtree while not calling the destroy method */
extern int cstl_rbtree_unlink_element(cstl_rbtree_element *element,
                                      void **retData);

#ifdef __cplusplus
}
#endif

#endif
