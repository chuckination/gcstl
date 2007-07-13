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

#ifndef CSTL_LIST_H
#define CSTL_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * struct declarations
 */

/* a doubly linked list element */
typedef struct cstl_list_element cstl_list_element;

/* a doubly linked list */
typedef struct cstl_list cstl_list;

/*
 * initialization and cleanup
 */

/* initialize a doubly linked list */
extern int cstl_list_initialize(cstl_list *list,
                                void (*destroy)(void *));

/* destroy a doubly linked list */
extern int cstl_list_destroy(cstl_list *list);

/*
 * data structure methods
 */

/* retrieve the number of elements in a list */
extern int cstl_list_size(cstl_list *list);

/* retrieve the data from a list element */
extern void *cstl_list_data(cstl_list_element *cstl_list_element);

/* change the elment data without calling the destroy method */
extern void *cstl_list_newdata(cstl_list_element *cstl_list_element,
                               void *data);

/* retrieve the element at the beginning of the linked list */
extern cstl_list_element *cstl_list_begin(cstl_list *list);

/* retrieve the element at the end of the linked list */
extern cstl_list_element *cstl_list_end(cstl_list *list);

/* retrieve the next list element */
extern cstl_list_element *cstl_list_next(cstl_list_element *element);

/* retrieve the previous list element */
extern cstl_list_element *cstl_list_prev(cstl_list_element *element);

/* insert a new list element before element */
extern int cstl_list_insert_before(cstl_list_element *element,
                                   void *data);

/* insert a new list element before element */
extern int cstl_list_insert_after(cstl_list_element *element,
                                  void *data);

/* remove the element from the list while calling the destroy method */
extern int cstl_list_remove(cstl_list_element *element);

/* remove the element from the list while not calling the destroy method */
extern int cstl_list_unlink(cstl_list_element *element,
                            void **data);

/* insert the data at the end of the linked list */
extern int cstl_list_push_back(cstl_list *list,
                               void *data);

/* remove the element from the end of the linked list while calling the
 * destroy method */
extern int cstl_list_pop_back(cstl_list *list);

/* remove the element from the end of the linked list while not calling
 * the destroy method */
extern int cstl_list_unlink_back(cstl_list *list,
                                 void **data);

/* insert the data at the beginning of the linked list */
extern int cstl_list_push_front(cstl_list *list,
                                void *data);

/* remove the element from the beginning of the linked list while calling the
 * destroy method */
extern int cstl_list_pop_front(cstl_list *list);

/* remove the element from the beginning of the linked list while not calling
 * the destroy method */
extern int cstl_list_unlink_front(cstl_list *list,
                                  void **data);

#ifdef __cplusplus
}
#endif

#endif
