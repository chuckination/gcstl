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

#include <gcstl/gcstl_map.h>
#include <gcstl/gcstl_destroy.h>

#include <stdlib.h>

int gcstl_map_comparator(void *first,
                        void *second,
                        int (*comparator)(void *, void *))
{
   return comparator(((gcstl_map_pair *)first)->key,
                     ((gcstl_map_pair *)second)->key);
}

void gcstl_map_destroy_default(void *data, void *destroy_arg)
{
   /* cleanup the element's key */
   ((gcstl_map_destroy_arg *)destroy_arg)->destroy_key(
                                             ((gcstl_map_pair *)data)->key);

   /* only cleanup the element's data if it is non-NULL */
   if (((gcstl_map_pair *)data)->value)
   {
      ((gcstl_map_destroy_arg *)destroy_arg)->destroy_value(
                                               ((gcstl_map_pair *)data)->value);
   }

   free(data);
}

/* initialize a map */
int gcstl_map_initialize(gcstl_map *map,
                        int (*comparator)(void *, void *),
                        void (*destroy_key)(void *),
                        void (*destroy_value)(void *))
{
   /* ensure that map is not NULL */
   if (!map)
      return -1;

   /* ensure comparator is not NULL */
   if (!comparator)
      return -1;

   /* allocate a destroy_arg structure */
   gcstl_map_destroy_arg *destroy_arg = NULL;
   destroy_arg = (gcstl_map_destroy_arg *)malloc(sizeof(gcstl_map_destroy_arg));
   if (!destroy_arg)
      return -1;

   /* assign the appropriate values to the destroy_arg fields */
   destroy_arg->destroy_key =
      destroy_key ? destroy_key : gcstl_destroy_default;
   destroy_arg->destroy_value =
      destroy_value ? destroy_value : gcstl_destroy_default;

   return gcstl_rbtree_initialize(map->rbtree,
                                 gcstl_map_comparator,
                                 comparator,
                                 gcstl_map_destroy_default,
                                 (void *)destroy_arg);
}

/* destroy a map */
int gcstl_map_destroy(gcstl_map *map)
{
   /* attempt to destroy the red-black tree part of the map */
   int return_value = gcstl_rbtree_destroy(map->rbtree);
   if (0 != return_value)
      return return_value;

   /* free the map destroy argument */
   free(map->destroy_arg);
   map->destroy_arg = NULL;
}

/* retrieve the number of elements in an map */
int gcstl_map_size(gcstl_map *map)
{
   /* return the map size */
   return gcstl_rbtree_size(map->rbtree);
}

/* retrieve the data from an map element */
void *gcstl_map_key(gcstl_map_element *element)
{
   /* ensure that the element is not NULL */
   if (!element)
      return NULL;

   /* attempt to retrieve the data from the map element */
   gcstl_map_pair *data = (gcstl_map_pair *)gcstl_rbtree_data(element);
   if (!data)
      return NULL;

   /* return the element's key */
   return data->key;
}

/* retrieve the data from an map element */
void *gcstl_map_value(gcstl_map_element *element)
{
   /* ensure that the element is not NULL */
   if (!element)
      return NULL;

   /* attempt to retrieve the data from the map element */
   gcstl_map_pair *data = (gcstl_map_pair *)gcstl_rbtree_data(element);
   if (!data)
      return NULL;

   /* return the element's key */
   return data->value;
}

/* retrieve the element at the beginning of the linked map */
gcstl_map_element *gcstl_map_begin(gcstl_map *map)
{
   return gcstl_rbtree_begin(map->rbtree);
}

/* retrieve the element at the end of the linked map */
gcstl_map_element *gcstl_map_end(gcstl_map *map)
{
   return gcstl_rbtree_end(map->rbtree);
}

/* retrieve the next map element */
gcstl_map_element *gcstl_map_next(gcstl_map_element *element)
{
   return gcstl_rbtree_next(element);
}

/* retrieve the previous map element */
gcstl_map_element *gcstl_map_prev(gcstl_map_element *element)
{
   return gcstl_rbtree_next(element);
}

/* insert data into map */
int gcstl_map_insert(gcstl_map *map,
                    void *key,
                    void *value)
{
   /* ensure that the key is not null */
   if (!key)
      return -1;

   /* attempt to allocate a map pair to hold the key and the data */
   gcstl_map_pair *data = (gcstl_map_pair *)malloc(sizeof(gcstl_map_pair));
   if (!data)
      return -1;

   /* attempt to insert the pair into the map */
   data->key = key;
   data->value = value;
   int return_value = gcstl_rbtree_insert(map->rbtree,
                                         data);

   if (0 != return_value)
   {
      free(data);
      return -1;
   }
   else
   {
      return return_value;
   }
}

/* retrieve data from map */
gcstl_map_element *gcstl_map_find(gcstl_map *map,
                                void *key)
{
   if ((NULL == map) ||
        NULL == key)
   {
      return NULL;
   }
   else
   {
      /* create a search key */
      gcstl_map_pair search;
      search.key = key;

      return gcstl_rbtree_find(map->rbtree,
                              &search);
   }
}

/* remove the element from the map while calling the destroy method */
int gcstl_map_remove(gcstl_map *map,
                    void *key)
{
   if ((NULL == map) ||
       (NULL == key))
   {
      return -1;
   }
   else
   {
      /* create a search key */
      gcstl_map_pair search;
      search.key = key;

      return gcstl_rbtree_remove(map->rbtree,
                                &search);
   }
}

/* remove the element from the map while calling the destroy method */
int gcstl_map_remove_element(gcstl_map_element *element)
{
   return gcstl_rbtree_remove_element(element);
}

/* remove the element from the map while not calling the destroy method */
int gcstl_map_unlink(gcstl_map *map,
                    void *key,
                    void **retData)
{
   if ((NULL == map) ||
       (NULL == key))
   {
      return -1;
   }
   else
   {
      int return_value;
      gcstl_map_pair *tmp = NULL;

      /* create a search key */
      gcstl_map_pair search;
      search.key = key;

      return_value = gcstl_rbtree_unlink(map,
                                        &search,
                                        (void **) &tmp);

      /* only assign the value in tmp to retData is we successfully
       * removed that element from the map */
      if (0 == return_value)
      {
         /* always call destroy_key on the element's key */
         map->destroy_arg->destroy_key(tmp->key);

         /* retData can be NULL, and this indicates that the developer
          * already has a poiner to the item and just wants it removed
          * from the tree */
         if (retData)
         {
            /* point retData to the pair's value */
            (*retData) = tmp->value;
         }

         /* free the temporary map pair item */
         free(tmp);
      }

      return return_value;
   }
}

/* remove the element from the map while not calling the destroy method */
int gcstl_map_unlink_element(gcstl_map_element *element,
                            void **retData)
{
   /* ensure that element is not null */
   if (!element)
      return -1;

   /* get a pointer to the rbtree */
   gcstl_rbtree *rbtree = element->rbtree;

   int return_value;
   gcstl_map_pair *tmp = NULL;

   return_value = gcstl_rbtree_unlink_element(element,
                                             (void **) &tmp);

   /* only assign the value in tmp to retData is we successfully
    * removed that element from the map */
   if (0 == return_value)
   {
      /* always call destroy_key on the element's key */
      ((gcstl_map_destroy_arg *)rbtree->destroy_arg)->destroy_key(tmp->key);

      /* retData can be NULL, and this indicates that the developer
       * already has a poiner to the item and just wants it removed
       * from the tree */
      if (retData)
      {
         /* point retData to the pair's value */
         (*retData) = tmp->value;
      }

      /* free the temporary map pair item */
      free(tmp);
   }

   return return_value;
}
