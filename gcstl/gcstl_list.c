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

#include <gcstl/gcstl_list.h>
#include <gcstl/gcstl_destroy.h>

#include <stdlib.h>

/* list validator value */
#define CSTL_LIST_VALIDATOR 0x1

int gcstl_list_initialize(gcstl_list *list,
                         void (*destroy)(void *))
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* set list->head to null initially and
      attempt to allocate the list head */
   list->head = NULL;
   list->head = (gcstl_list_element *) malloc(sizeof(gcstl_list_element));
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
      list->destroy = gcstl_destroy_default;

   return 0;
}

int gcstl_list_destroy(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* iterate through the list, starting at list->head->next and stopping
    * at list->head with list->head intact */
   gcstl_list_element *iter = list->head->next;
   while (iter != list->head)
   {
      /* free the list element data */
      list->destroy(iter->data);

      /* free the element */
      gcstl_list_element *tmp = iter->next;
      free(iter);
      iter = tmp;
   }

   /* free the list head and reset the list statistics */
   free(list->head);
   list->size = 0;
   list->validator = 0;

   return 0;
}

gcstl_list_element *gcstl_list_begin(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return NULL;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return NULL;

   return list->head->next;
}

gcstl_list_element *gcstl_list_end(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return NULL;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return NULL;

   return list->head;
}

int gcstl_list_size(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   return list->size;
}

void *gcstl_list_data(gcstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->data;
}

void *gcstl_list_newdata(gcstl_list_element *element,
                     void *data)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   void *oldData = element->data;
   element->data = data;

   return oldData;
}

gcstl_list_element *gcstl_list_next(gcstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->next;
}

gcstl_list_element *gcstl_list_prev(gcstl_list_element *element)
{
   /* ensure that element is not null */
   if (!element)
      return NULL;

   return element->prev;
}

int gcstl_list_insert_before(gcstl_list_element *element,
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
   gcstl_list_element *newElement = NULL;
   newElement = (gcstl_list_element *) malloc(sizeof(gcstl_list_element));
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

int gcstl_list_insert_after(gcstl_list_element *element,
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
   gcstl_list_element *newElement = NULL;
   newElement = (gcstl_list_element *) malloc(sizeof(gcstl_list_element));
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

int gcstl_list_remove(gcstl_list_element *element)
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

   /* ensure that the element is not the list head */
   if (element == element->list->head)
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

int gcstl_list_unlink(gcstl_list_element *element,
                     void **retData)
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

   /* ensure that the element is not the list head */
   if (element == element->list->head)
      return -1;

   /* unlink the element from the list */
   element->next->prev = element->prev;
   element->prev->next = element->next;

   /* decrement the list size */
   element->list->size--;

   /* retData can be NULL, but this indicates that the developer
    * already has a poiner to the item and just wants it removed
    * from the list */
   if (NULL != retData)
   {
      /* point data to the element data */
      (*retData) = element->data;
   }

   /* free the element */
   free(element);

   return 0;
}

int gcstl_list_push_back(gcstl_list *list,
                        void *data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* attempt to allocate a new list element */
   gcstl_list_element *newElement = NULL;
   newElement = (gcstl_list_element *) malloc(sizeof(gcstl_list_element));
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

int gcstl_list_pop_back(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   gcstl_list_element *element = list->head->prev;

   /* ensure that the element is not the list head */
   if (element->list->head->prev == element->list->head)
      return -1;

   /* unlink the element from the list */
   element->next->prev = element->prev;
   element->prev->next = element->next;

   /* decrement the list size */
   list->size--;

   /* call the list destroy method to free the element data */
   list->destroy(element->data);

   /* free the element */
   free(element);

   return 0;
}

int gcstl_list_unlink_back(gcstl_list *list,
                          void **retData)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   gcstl_list_element *element = list->head->prev;

   /* ensure that the element is not the list head */
   if (element->list->head->prev == element->list->head)
      return -1;

   /* unlink the element from the list */
   element->next->prev = element->prev;
   element->prev->next = element->next;

   /* decrement the list size */
   list->size--;

   /* retData can be NULL, and this indicates that the developer
    * already has a poiner to the item and just wants it removed
    * from the list */
   if (NULL != retData)
   {
      /* point data to the element data */
      (*retData) = element->data;
   }

   /* free the element */
   free(element);

   return 0;
}

int gcstl_list_push_front(gcstl_list *list,
                         void *data)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* attempt to allocate a new list element */
   gcstl_list_element *newElement = NULL;
   newElement = (gcstl_list_element *) malloc(sizeof(gcstl_list_element));
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

int gcstl_list_pop_front(gcstl_list *list)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   gcstl_list_element *element = list->head->next;

   /* ensure that the element is not the list head */
   if (element->list->head->next == element->list->head)
      return -1;

   /* call the list destroy method to free the element data */
   list->destroy(element->data);

   /* unlink the element from the list */
   element->prev->next = element->next;
   element->next->prev = element->prev;

   /* decrement the list size */
   list->size--;

   /* free the element */
   free(element);

   return 0;
}

int gcstl_list_unlink_front(gcstl_list *list,
                        void **retData)
{
   /* ensure that list is not null */
   if (!list)
      return -1;

   /* ensure that the list is valid */
   if (CSTL_LIST_VALIDATOR != list->validator)
      return -1;

   /* get a handle to the list element */
   gcstl_list_element *element = list->head->next;

   /* ensure that the element is not the list head */
   if (element->list->head->next == element->list->head)
      return -1;

   /* unlink the element from the list */
   element->prev->next = element->next;
   element->next->prev = element->prev;

   /* decrement the list size */
   list->size--;

   /* retData can be NULL, and this indicates that the developer
    * already has a poiner to the item and just wants it removed
    * from the list */
   if (NULL != retData)
   {
      /* point data to the element data */
      (*retData) = element->data;
   }

   /* free the element */
   free(element);

   return 0;
}
