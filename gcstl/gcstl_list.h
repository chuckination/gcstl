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

#ifndef GCSTL_LIST_H
#define GCSTL_LIST_H

/**
 * @defgroup gcstl gcstl
 * @defgroup list list
 *
 * @ingroup gcstl
 * @ingroup gcstl list
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef struct gcstl_list_element gcstl_list_element;
typedef struct gcstl_list gcstl_list;

/* a doubly linked list element */
struct gcstl_list_element
{
   gcstl_list *list;
   gcstl_list_element *next;
   gcstl_list_element *prev;
   void *data;
};

/* a doubly linked list */
struct gcstl_list
{
   gcstl_list_element *head;
   unsigned long int size;
   short int validator;
   void (*destroy)(void *);
};

/* initialize a doubly linked list */
extern int gcstl_list_initialize(gcstl_list *list,
                                void (*destroy)(void *));

/* destroy a doubly linked list */
extern int gcstl_list_destroy(gcstl_list *list);

/* retrieve the number of elements in a list */
extern int gcstl_list_size(gcstl_list *list);

/* retrieve the data from a list element */
extern void *gcstl_list_data(gcstl_list_element *element);

/* change the elment data without calling the destroy method */
extern void *gcstl_list_newdata(gcstl_list_element *gcstl_list_element,
                               void *data);

/* retrieve the element at the beginning of the linked list */
extern gcstl_list_element *gcstl_list_begin(gcstl_list *list);

/* retrieve the element at the end of the linked list */
extern gcstl_list_element *gcstl_list_end(gcstl_list *list);

/* retrieve the next list element */
extern gcstl_list_element *gcstl_list_next(gcstl_list_element *element);

/* retrieve the previous list element */
extern gcstl_list_element *gcstl_list_prev(gcstl_list_element *element);

/* insert a new list element before element */
extern int gcstl_list_insert_before(gcstl_list_element *element,
                                   void *data);

/* insert a new list element before element */
extern int gcstl_list_insert_after(gcstl_list_element *element,
                                  void *data);

/* remove the element from the list while calling the destroy method */
extern int gcstl_list_remove(gcstl_list_element *element);

/* remove the element from the list while not calling the destroy method */
extern int gcstl_list_unlink(gcstl_list_element *element,
                            void **retData);

/* insert the data at the end of the linked list */
extern int gcstl_list_push_back(gcstl_list *list,
                               void *data);

/* remove the element from the end of the linked list while calling the
 * destroy method */
extern int gcstl_list_pop_back(gcstl_list *list);

/* remove the element from the end of the linked list while not calling
 * the destroy method */
extern int gcstl_list_unlink_back(gcstl_list *list,
                                 void **retData);

/* insert the data at the beginning of the linked list */
extern int gcstl_list_push_front(gcstl_list *list,
                                void *data);

/* remove the element from the beginning of the linked list while calling the
 * destroy method */
extern int gcstl_list_pop_front(gcstl_list *list);

/* remove the element from the beginning of the linked list while not calling
 * the destroy method */
extern int gcstl_list_unlink_front(gcstl_list *list,
                                  void **retData);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif
