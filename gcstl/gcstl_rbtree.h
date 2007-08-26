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

#ifndef GCSTL_RBTREE_H
#define GCSTL_RBTREE_H

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef enum gcstl_rbtree_element_color gcstl_rbtree_element_color;
typedef struct gcstl_rbtree_element gcstl_rbtree_element;
typedef struct gcstl_rbtree gcstl_rbtree;

/* red-black tree color enumeration */
enum gcstl_rbtree_element_color
{
   CSTL_RBTREE_RED,
   CSTL_RBTREE_BLACK
};

/* a red-black tree element */
struct gcstl_rbtree_element
{
   gcstl_rbtree *rbtree;
   gcstl_rbtree_element *parent;
   gcstl_rbtree_element *left;
   gcstl_rbtree_element *right;
   gcstl_rbtree_element_color color;
   void *data;
};

/* a red-black tree */
struct gcstl_rbtree
{
   gcstl_rbtree_element *root;
   gcstl_rbtree_element *end;
   unsigned long int size;
   short int validator;
   int (*comparator)(void *, void *, int (*)(void *, void *));
   int (*sub_comparator)(void *, void *);
   void (*destroy)(void *, void *);
   void *destroy_arg;
};

/* initialize a red-black tree */
extern int gcstl_rbtree_initialize(
                      gcstl_rbtree *rbtree,
                      int (*comparator)(void *,
                                        void *,
                                        int (*sub_comparator)(void *, void *)),
                      int (*sub_comparator)(void *, void *),
                      void (*destroy)(void *, void *),
                      void *destroy_arg);

/* destroy a red-black tree */
extern int gcstl_rbtree_destroy(gcstl_rbtree *rbtree);

/* retrieve the number of elements in an rbtree */
extern int gcstl_rbtree_size(gcstl_rbtree *rbtree);

/* retrieve the data from an rbtree element */
extern void *gcstl_rbtree_data(gcstl_rbtree_element *element);

/* retrieve the element at the beginning of the linked rbtree */
extern gcstl_rbtree_element *gcstl_rbtree_begin(gcstl_rbtree *rbtree);

/* retrieve the element at the end of the linked rbtree */
extern gcstl_rbtree_element *gcstl_rbtree_end(gcstl_rbtree *rbtree);

/* retrieve the next rbtree element */
extern gcstl_rbtree_element *gcstl_rbtree_next(gcstl_rbtree_element *element);

/* retrieve the previous rbtree element */
extern gcstl_rbtree_element *gcstl_rbtree_prev(gcstl_rbtree_element *element);

/* insert data into rbtree */
extern int gcstl_rbtree_insert(gcstl_rbtree *rbtree,
                              void *data);

/* retrieve data from rbtree */
extern gcstl_rbtree_element *gcstl_rbtree_find(gcstl_rbtree *rbtree,
                                             void *data);

/* remove the element from the rbtree while calling the destroy method */
extern int gcstl_rbtree_remove(gcstl_rbtree *rbtree,
                              void *data);

/* remove the element from the rbtree while calling the destroy method */
extern int gcstl_rbtree_remove_element(gcstl_rbtree_element *element);

/* remove the element from the rbtree while not calling the destroy method */
extern int gcstl_rbtree_unlink(gcstl_rbtree *rbtree,
                              void *data,
                              void **retData);

/* remove the element from the rbtree while not calling the destroy method */
extern int gcstl_rbtree_unlink_element(gcstl_rbtree_element *element,
                                      void **retData);

#ifdef __cplusplus
}
#endif

#endif
