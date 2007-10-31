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

/*!
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

/*! @brief creates a type name for gcstl_list_element */
typedef struct gcstl_list_element gcstl_list_element;

/*! @brief creates a type name for gcstl_list */
typedef struct gcstl_list gcstl_list;

/*! @brief a doubly linked list element */
struct gcstl_list_element
{
   gcstl_list *list; /*!< the associated list */
   gcstl_list_element *next; /*!< the next element in the list */
   gcstl_list_element *prev; /*!< the previous element in the list */
   void *data; /*!< the list element data */
};

/*! @brief a doubly linked list */
struct gcstl_list
{
   gcstl_list_element *head; /*!< the list head element */
   unsigned long int size; /*!< the number of elements in the list */
   short int validator; /*!< the list initialization validator */
   void (*destroy)(void *); /*!< the list data cleanup funtion */
};

/*! @brief initializes a doubly linked list
 *  @param[in] list the list
 *  @param[in] destroy the list data cleanup function to bind to the list
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_initialize(gcstl_list *list,
                                void (*destroy)(void *));

/*! @brief destroy a doubly linked list
 *  @details destroy a doubly linked list, calls the cleanup function on all
 *  element data in the list
 *  @param[in] list the list
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_destroy(gcstl_list *list);

/*! @brief returns the number of elements in a list
 *  @param[in] list the list
 *  @return size of the list, or -1 if list is invalid */
extern int gcstl_list_size(gcstl_list *list);

/*! @brief returns the data from a list element
 *  @param[in] element the list element
 *  @return the list element data, or NULL if list element is invalid */
extern void *gcstl_list_data(gcstl_list_element *element);

/*! @brief replaces the data in a list element, returning the old data
 *  @param[in] element the list element
 *  @param[in] data the new element data
 *  @return the old data, or NULL if the list element is invalid */
extern void *gcstl_list_newdata(gcstl_list_element *element,
                                void *data);

/*! @brief returns the first list element of the list
 *  @param[in] list the list
 *  @return the first element in the list, the list head if the list is empty,
 *  or NULL if the list is invalid */
extern gcstl_list_element *gcstl_list_begin(gcstl_list *list);

/*! @brief returns the list head of the list
 *  @param[in] list the list
 *  @return the list head if the list is empty, or NULL if the list is invalid
 */
extern gcstl_list_element *gcstl_list_end(gcstl_list *list);

/*! @brief returns the next element in a list
 *  @param[in] element the list element
 *  @return the next list element in the list, the list head if the specified
 *  element is the last element in the list, or NULL if the list is invalid */
extern gcstl_list_element *gcstl_list_next(gcstl_list_element *element);

/*! @brief returns the previous element in a list
 *  @param[in] element the list element
 *  @return the previous list element in the list, the list head if the
 *  specified element is the first element in the list, or NULL if the list
 *  is invalid */
extern gcstl_list_element *gcstl_list_prev(gcstl_list_element *element);

/*! @brief inserts data into a new list element after the specified list
 *  element
 *  @param[in] element the list element
 *  @param[in] data the new element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_insert_before(gcstl_list_element *element,
                                   void *data);

/*! @brief inserts data into a new list element before the specified list
 *  element
 *  @param[in] element the list element
 *  @param[in] data the new element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_insert_after(gcstl_list_element *element,
                                  void *data);

/*! @brief removes an existing list element
 *  @param[in] element the list element
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_remove(gcstl_list_element *element);

/*! @brief removes an existing list element while preserving that element's data
 *  @param[in] element the list element
 *  @param[out] retData pointer to the pointer to be set to the preserved
 *  element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_unlink(gcstl_list_element *element,
                            void **retData);

/*! @brief inserts data at the end of the list
 *  @param[in] list the list
 *  @param[in] data the new element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_push_back(gcstl_list *list,
                               void *data);

/*! @brief removes the element at the end of the list
 *  @param[in] list the list
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_pop_back(gcstl_list *list);

/*! @brief removes the element at the end of the list while preserving that
 *  element's data
 *  @param[in] list the list
 *  @param[out] retData pointer to the pointer to be set to the preserved
 *  element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_unlink_back(gcstl_list *list,
                                 void **retData);

/*! @brief inserts data at the beginning of the list
 *  @param[in] list the list
 *  @param[in] data the new element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_push_front(gcstl_list *list,
                                void *data);

/*! @brief removes the element at the beginning of the list
 *  @param[in] list the list
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_pop_front(gcstl_list *list);

/*! @brief removes the element at the beginning of the list while preserving
 *  that element's data
 *  @param[in] list the list
 *  @param[out] retData pointer to the pointer to be set to the preserved
 *  element data
 *  @return 0 on success, -1 on failure */
extern int gcstl_list_unlink_front(gcstl_list *list,
                                  void **retData);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif
