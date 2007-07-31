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

#include "cstl_list.h"
#include "cstl_destroy.h"

#include <stdlib.h>

/* list validator value */
#define CSTL_LIST_VALIDATOR 0x1

int cstl_list_initialize(cstl_list *list,
                         void (*destroy)(void *))
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* set list->head to null initially and
      attempt to allocate the list head */
   list->head = NULL;
   list->head = (cstl_list_element *) malloc(sizeof(cstl_list_element));
   if (!list->head)
      return -1;

   /* the list head data is null and prev and next points to itself */
   list->head->list = list;
   list->head->next = list->head;
   list->head->prev = list->head;
   list->head->data = NULL;

   /* set size and the list validator */
   list->size = 0;
   list->validator = CSTL_LIST_VALIDATOR;

   /* register the data destroy function */
   if (destroy)
      list->destroy = destroy;
   else
      list->destroy = cstl_destroy_default;

   return 0;
}

int cstl_list_destroy(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* iterate through the list, starting at list->head->next and stopping
    * at list->head with list->head intact */
   cstl_list_element *iter = list->head->next;
   while (iter != list->head)
   {
      /* free the list element data */
      list->destroy(iter->data);

      /* free the element */
      cstl_list_element *tmp = iter->next;
      free(iter);
      iter = tmp;
   }

   /* free the list head and reset the list statistics */
   free(list->head);
   list->size = 0;
   list->validator = 0;

   return 0;
}

cstl_list_element *cstl_list_begin(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return NULL;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return NULL;

   return list->head->next;
}

cstl_list_element *cstl_list_end(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return NULL;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return NULL;

   return list->head;
}

int cstl_list_size(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   return list->size;
}

void *cstl_list_data(cstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->data;
}

void *cstl_list_newdata(cstl_list_element *element,
                     void *data)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   void *oldData = element->data;
   element->data = data;

   return oldData;
}

cstl_list_element *cstl_list_next(cstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->next;
}

cstl_list_element *cstl_list_prev(cstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->prev;
}

int cstl_list_insert_before(cstl_list_element *element,
                            void *data)
{
   /* ensure that element is not null */
   if (!element)
      return -1;

   /* ensure that list is not null */
   if (!element->list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != element->list->validator)
      return -1;

   /* attempt to allocate a new list element */
   cstl_list_element *newElement = NULL;
   newElement = (cstl_list_element *) malloc(sizeof(cstl_list_element));
   if (!newElement)
      return -1;

   /* link the list to the element */
   newElement->list = element->list;
   newElement->next = element;
   newElement->prev = element->prev;

   /* link the list to the element */
   element->prev->next = newElement;
   element->prev = newElement;

   /* increment the list size */
   element->list->size++;

   /* set the data pointer */
   newElement->data = data;

   return 0;
}

int cstl_list_insert_after(cstl_list_element *element,
                           void *data)
{
   /* ensure that element is not null */
   if (!element)
      return -1;

   /* ensure that list is not null */
   if (!element->list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != element->list->validator)
      return -1;

   /* attempt to allocate a new list element */
   cstl_list_element *newElement = NULL;
   newElement = (cstl_list_element *) malloc(sizeof(cstl_list_element));
   if (!newElement)
      return -1;

   /* link the list to the element */
   newElement->list = element->list;
   newElement->next = element->next;
   newElement->prev = element;

   /* link the list to the element */
   element->next->prev = newElement;
   element->next = newElement;

   /* increment the list size */
   element->list->size++;

   /* set the data pointer */
   newElement->data = data;

   return 0;
}

int cstl_list_remove(cstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return -1;

   /* ensure that list is not null */
   if (!element->list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != element->list->validator)
      return -1;

   /* unlink the element from the list */
   element->next->prev = element->prev;
   element->prev->next = element->next;

   /* decrement the list size */
   element->list->size--;

   /* call the list destroy method to free the element data */
   element->list->destroy(element->data);

   /* free the element */
   free(element);

   return 0;
}

int cstl_list_unlink(cstl_list_element *element,
                     void **data)
{
   /* ensure that element is not null */
   if (!element)
      return -1;

   /* ensure that list is not null */
   if (!element->list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != element->list->validator)
      return -1;

   /* unlink the element from the list */
   element->next->prev = element->prev;
   element->prev->next = element->next;

   /* decrement the list size */
   element->list->size--;

   /* point data to the element data */
   (*data) = element->data;

   /* free the element */
   free(element);

   return 0;
}

int cstl_list_push_back(cstl_list *list,
                        void *data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* attempt to allocate a new list element */
   cstl_list_element *newElement = NULL;
   newElement = (cstl_list_element *) malloc(sizeof(cstl_list_element));
   if (!newElement)
      return -1;

   /* link the list to the element */
   newElement->list = list;
   newElement->next = list->head;
   newElement->prev = list->head->prev;

   /* link the element to the end of the list */
   list->head->prev->next = newElement;
   list->head->prev = newElement;

   /* increment the list size */
   list->size++;

   /* set the data pointer */
   newElement->data = data;

   return 0;
}

int cstl_list_pop_back(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   cstl_list_element *oldElement = list->head->prev;

   /* unlink the element from the list */
   oldElement->next->prev = oldElement->prev;
   oldElement->prev->next = oldElement->next;

   /* decrement the list size */
   list->size--;

   /* call the list destroy method to free the element data */
   list->destroy(oldElement->data);

   /* free the element */
   free(oldElement);

   return 0;
}

int cstl_list_unlink_back(cstl_list *list,
                          void **data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   cstl_list_element *oldElement = list->head->prev;

   /* point data to the element data */
   (*data) = oldElement->data;

   /* unlink the element from the list */
   oldElement->next->prev = oldElement->prev;
   oldElement->prev->next = oldElement->next;

   /* decrement the list size */
   list->size--;

   /* free the element */
   free(oldElement);

   return 0;
}

int cstl_list_push_front(cstl_list *list,
                         void *data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* attempt to allocate a new list element */
   cstl_list_element *newElement = NULL;
   newElement = (cstl_list_element *) malloc(sizeof(cstl_list_element));
   if (!newElement)
      return -1;

   /* set the data pointer */
   newElement->data = data;

   /* link the list to the element */
   newElement->list = list;
   newElement->prev = list->head;
   newElement->next = list->head->next;

   /* link the element to the end of the list */
   list->head->next->prev = newElement;
   list->head->next = newElement;

   /* increment the list size */
   list->size++;

   return 0;
}

int cstl_list_pop_front(cstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   cstl_list_element *oldElement = list->head->next;

   /* call the list destroy method to free the element data */
   list->destroy(oldElement->data);

   /* unlink the element from the list */
   oldElement->prev->next = oldElement->next;
   oldElement->next->prev = oldElement->prev;

   /* decrement the list size */
   list->size--;

   /* free the element */
   free(oldElement);

   return 0;
}

int cstl_list_unlink_front(cstl_list *list,
                        void **data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   cstl_list_element *oldElement = list->head->next;

   /* point data at the element data */
   (*data) = oldElement->data;

   /* unlink the element from the list */
   oldElement->prev->next = oldElement->next;
   oldElement->next->prev = oldElement->prev;

   /* decrement the list size */
   list->size--;

   /* free the element */
   free(oldElement);

   return 0;
}
