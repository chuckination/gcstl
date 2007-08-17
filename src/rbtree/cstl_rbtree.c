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

#include "cstl_rbtree.h"
#include "cstl_destroy.h"

#include <stdlib.h>

#define CSTL_RBTREE_VALIDATOR 0x1

int cstl_rbtree_initialize(
                     cstl_rbtree *rbtree,
                     int (*comparator)(void *,
                                       void *,
                                       int (*sub_comparator)(void *, void *)),
                     int (*sub_comparator)(void *, void *),
                     void (*destroy)(void *, void *),
                     void *destroy_arg)
{
   /* ensure that rbtree is not null */
   if (!rbtree)
      return -1;

   /* ensure that comparator is not null,
    * sub_comparator may be NULL */
   if (!comparator)
      return -1;

   /* ensure that destroy is not null,
    * destroy_arg may be NULL */
   if (!destroy)
      return -1;

   /* allocate the end pointer */
   rbtree->end = NULL;
   rbtree->end = (cstl_rbtree_element *) malloc(sizeof(cstl_rbtree_element));
   if (!rbtree->end)
      return -1;

   /* the end element should only point to the tree,
    * and the color is arbitrary */
   rbtree->end->rbtree = rbtree;
   rbtree->end->parent = NULL;
   rbtree->end->left = NULL;
   rbtree->end->right = NULL;
   rbtree->end->data = NULL;

   /* there should be no elements in an empty tree,
    * so the root node is null */
   rbtree->root = NULL;

   /* set the size and tree validator */
   rbtree->size = 0;
   rbtree->validator = CSTL_RBTREE_VALIDATOR;

   /* register the comparator function */
   rbtree->comparator = comparator;
   rbtree->sub_comparator = sub_comparator;

   /* register the data destroy function */
   rbtree->destroy_arg = destroy_arg;
   rbtree->destroy = destroy;

   return 0;
}

void cstl_rbtree_destroy_element(cstl_rbtree_element *element);

int cstl_rbtree_destroy(cstl_rbtree *rbtree)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return -1;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return -1;

   cstl_rbtree_destroy_element(rbtree->root);
   rbtree->root = NULL;
   cstl_rbtree_destroy_element(rbtree->end);
   rbtree->end = NULL;
   rbtree->destroy = NULL;
   rbtree->comparator = NULL;
   rbtree->sub_comparator = NULL;
   rbtree->size = 0;
   rbtree->validator = 0;

   return 0;
}

void cstl_rbtree_destroy_element(cstl_rbtree_element *element)
{
   if (element->left)
      cstl_rbtree_destroy_element(element->left);

   if (element->right)
      cstl_rbtree_destroy_element(element->right);

   if (element->data)
      element->rbtree->destroy(element->data,
                               element->rbtree->destroy_arg);

   free(element);
}

int cstl_rbtree_size(cstl_rbtree *rbtree)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return -1;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return -1;

   return rbtree->size;
}

void *cstl_rbtree_data(cstl_rbtree_element *element)
{
   /* ensure that the element is not null */
   if (!element)
      return NULL;

   return element->data;
}

cstl_rbtree_element *cstl_rbtree_begin(cstl_rbtree *rbtree)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return NULL;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return NULL;

   // get some iterators for the tree
   cstl_rbtree_element *iter = rbtree->root;
   cstl_rbtree_element *element = NULL;

   // the iterator is not NULL
   if (NULL != iter)
   {
      // find the farthest left element of the tree
      while (NULL != iter)
      {
         element = iter;
         iter = iter->left;
      }

      return element;
   }
   // the iterator is NULL
   else
   {
      // get the end of the tree
      return rbtree->end;
   }
}

cstl_rbtree_element *cstl_rbtree_end(cstl_rbtree *rbtree)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return NULL;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return NULL;

   return rbtree->end;
}

cstl_rbtree_element *cstl_rbtree_next(cstl_rbtree_element *element)
{
   /* ensure that the rbtree is not null */
   if (!element)
      return NULL;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != element->rbtree->validator)
      return NULL;

   if (element == element->rbtree->end)
      return cstl_rbtree_begin(element->rbtree);

   for (;;)
   {
      if (element->right)
      {
         element = element->right;

         while (element->left)
         {
            element = element->left;
         }

         return element;
      }
      else
      {
         while (element->parent)
         {
            if (element == element->parent->left)
            {
               return element->parent;
            }
            else
            {
               element = element->parent;
            }
         }

         return element->rbtree->end;
      }
   }
}

cstl_rbtree_element *cstl_rbtree_prev(cstl_rbtree_element *element)
{
   /* ensure that the rbtree is not null */
   if (!element)
      return NULL;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != element->rbtree->validator)
      return NULL;

   if (element == element->rbtree->end)
      return cstl_rbtree_end(element->rbtree);

   for (;;)
   {
      if (element->left)
      {
         element = element->left;

         while (element->right)
         {
            element = element->right;
         }

         return element;
      }
      else
      {
         while (element->parent)
         {
            if (element == element->parent->right)
            {
               return element->parent;
            }
            else
            {
               element = element->parent;
            }
         }

         return element->rbtree->end;
      }
   }
}

cstl_rbtree_element *cstl_rbtree_find(cstl_rbtree *rbtree,
                                      void *data)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return NULL;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return NULL;

   /* ensure that the search data is not NULL */
   if (!data)
      return NULL;

   /* ensure that atleast one element is in the tree */
   if (!rbtree->root)
      return NULL;

   /* pointers for parent and the element iterator */
   cstl_rbtree_element *element = rbtree->root;

   /* comparator result value */
   int compareResult = 0;

   /* until the element iterator is NULL */
   while (NULL != element)
   {
      /* compare the data to be inserted with
       * the data of the element iterator */
      compareResult =
         rbtree->comparator(data, element->data, rbtree->sub_comparator);

      if (0 > compareResult)
      {
         /* the search data would be before the element */
         element = element->left;
      }
      else if (0 < compareResult)
      {
         /* the search data would be after the element */
         element = element->right;
      }
      else
      {
         /* we found the search data */
         break;
      }
   }

   return element;
}

/* general balancing helper functions */
cstl_rbtree_element_color cstl_rbtree_color(cstl_rbtree_element *element);
void cstl_rbtree_rotate_left(cstl_rbtree_element *element);
void cstl_rbtree_rotate_right(cstl_rbtree_element *element);

/* insert helper functions */
void cstl_rbtree_insert_rebalance(cstl_rbtree_element *element);

int cstl_rbtree_insert(cstl_rbtree *rbtree,
                       void *data)
{
   /* ensure that the rbtree is not null */
   if (!rbtree)
      return -1;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != rbtree->validator)
      return -1;

   /* ensure that the inserted data is not NULL */
   if (!data)
      return -1;

   /* pointers for parent and the element iterator */
   cstl_rbtree_element *parent = NULL;
   cstl_rbtree_element *element = rbtree->root;

   /* comparator result value */
   int compareResult = 0;

   /* until the element iterator is NULL */
   while (NULL != element)
   {
      /* compare the data to be inserted with
       * the data of the element iterator */
      compareResult =
         rbtree->comparator(data, element->data, rbtree->sub_comparator);

      if (0 > compareResult)
      {
         /* the inserted data goes before the element */
         parent = element;
         element = parent->left;
      }
      else if (0 < compareResult)
      {
         /* the inserted data goes after the element */
         parent = element;
         element = parent->right;
      }
      else
      {
         /* the inserted data is a duplicate of previously inserted value, and
          * inserting duplicate data is not allowed */
         return -1;
      }
   }

   element = (cstl_rbtree_element *) malloc(sizeof(cstl_rbtree_element));
   if (!element)
      return -1;

   /* the parent pointer is NULL, this is the new root element */
   if (!parent)
      rbtree->root = element;
   else
   {
      /* the new element is the parent's left element */
      if (0 > compareResult)
         parent->left = element;
      /* the new element is the parent's right element */
      else
         parent->right = element;
   }

   /* set the field values for the element */
   element->rbtree = rbtree;
   element->parent = parent;
   element->left = NULL;
   element->right = NULL;
   element->color = RED;
   element->data = data;

   /* increment the size of the rbtree */
   rbtree->size++;

   /* rebalance insert element */
   cstl_rbtree_insert_rebalance(element);

   return 0;
}

void cstl_rbtree_insert_case1(cstl_rbtree_element *element);
void cstl_rbtree_insert_case2(cstl_rbtree_element *element);
void cstl_rbtree_insert_case3_left(cstl_rbtree_element *element);
void cstl_rbtree_insert_case4_left(cstl_rbtree_element *element);
void cstl_rbtree_insert_case5_left(cstl_rbtree_element *element);
void cstl_rbtree_insert_case3_right(cstl_rbtree_element *element);
void cstl_rbtree_insert_case4_right(cstl_rbtree_element *element);
void cstl_rbtree_insert_case5_right(cstl_rbtree_element *element);

void cstl_rbtree_insert_rebalance(cstl_rbtree_element *element)
{
   /* do nothing to NULL elements */
   if (!element)
      return;

   cstl_rbtree_insert_case1(element);
}

void cstl_rbtree_insert_case1(cstl_rbtree_element *element)
{
   if (element->parent == NULL)
   {
      /* the element is the root */
      if (cstl_rbtree_color(element) == RED)
      {
         /* the element is a red root */
         element->color = BLACK;
      }
   }
   else
   {
      /* call case 2 on the element */
      cstl_rbtree_insert_case2(element);
   }
}

void cstl_rbtree_insert_case2(cstl_rbtree_element *element)
{
   /* the element's parent is red */
   if (cstl_rbtree_color(element->parent) == RED)
   {
      /* the parent is the left child of the grandparent */
      if (element->parent == element->parent->parent->left)
      {
         cstl_rbtree_insert_case3_left(element);
      }
      /* the parent is the right child of the grandparent */
      else
      {
         /* call case 3 on the element */
         cstl_rbtree_insert_case3_left(element);
      }
   }
}

void cstl_rbtree_insert_case3_left(cstl_rbtree_element *element)
{
   /* the element's uncle is red */
   if (cstl_rbtree_color(element->parent->parent->right) == RED)
   {
      /* flip the color of the parent, uncle, and grandparent */
      element->parent->color = BLACK;
      element->parent->parent->right->color = BLACK;
      element->parent->parent->color = RED;

      /* the color change could break the red rule for the grandparent,
       * so rebalance starting at the grandparent */
      cstl_rbtree_insert_case1(element->parent->parent);
   }
   /* the element's uncle is black */
   else
   {
      /* call case 4 on the element */
      cstl_rbtree_insert_case4_left(element);
   }
}

void cstl_rbtree_insert_case4_left(cstl_rbtree_element *element)
{
   /* the element is the parent's right child */
   if (element == element->parent->right)
   {
      /* rotate the element's parent to the left */
      cstl_rbtree_rotate_left(element->parent);

      /* call case 5 on the element's left child */
      cstl_rbtree_insert_case5_left(element->left);
   }
   else
   {
      /* call case 5 on the element */
      cstl_rbtree_insert_case5_left(element);
   }
}

void cstl_rbtree_insert_case5_left(cstl_rbtree_element *element)
{
   /* rotate the element's parent to the right */
   cstl_rbtree_rotate_right(element->parent);

   /* recolor the element and the elements right child */
   element->color = BLACK;
   element->right->color = RED;
}

void cstl_rbtree_insert_case3_right(cstl_rbtree_element *element)
{
   /* the element's uncle is red */
   if (cstl_rbtree_color(element->parent->parent->left) == RED)
   {
      /* flip the color of the parent, uncle, and grandparent */
      element->parent->color = BLACK;
      element->parent->parent->left->color = BLACK;
      element->parent->parent->color = RED;

      /* the color change could break the red rule for the grandparent,
       * so rebalance starting at the grandparent */
      cstl_rbtree_insert_case1(element->parent->parent);
   }
   /* the element's uncle is black */
   else
   {
      /* call case 4 on the element */
      cstl_rbtree_insert_case4_right(element);
   }
}

void cstl_rbtree_insert_case4_right(cstl_rbtree_element *element)
{
   /* the element is the parent's left child */
   if (element == element->parent->left)
   {
      /* rotate the element's parent to the right */
      cstl_rbtree_rotate_right(element->parent);

      /* call case 5 on the element's right child */
      cstl_rbtree_insert_case5_right(element->right);
   }
   else
   {
      /* call case 5 on the element */
      cstl_rbtree_insert_case5_right(element);
   }
}

void cstl_rbtree_insert_case5_right(cstl_rbtree_element *element)
{
   /* rotate the element's parent to the left */
   cstl_rbtree_rotate_left(element->parent);

   /* recolor the element and the elements left child */
   element->color = BLACK;
   element->left->color = RED;
}

int cstl_rbtree_remove(cstl_rbtree *rbtree,
                       void *data)
{
   return cstl_rbtree_remove_element(cstl_rbtree_find(rbtree, data));
}

/* remove helper methods */
void cstl_rbtree_remove_rebalance(cstl_rbtree_element *replacement,
                                  cstl_rbtree_element *parent);

int cstl_rbtree_remove_element(cstl_rbtree_element *element)
{
   /* ensure that the rbtree is not null */
   if (!element)
      return -1;

   /* ensure that the rbtree is not null */
   if (!element->rbtree)
      return -1;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != element->rbtree->validator)
      return -1;

   /* find the predecessor */
   if ((NULL != element->left) && (NULL != element->right))
   {
      /* find the predecessor */
      cstl_rbtree_element *deleted = element;
      cstl_rbtree_element *iter = element->left;

      while (NULL != iter)
      {
         deleted = iter;
         iter = iter->right;
      }

      /* swap the data of the two elements */
      void *tmp = deleted->data;
      deleted->data = element->data;
      element->data = tmp;
      element = deleted;
   }

   /* parent and sibling pointers */
   cstl_rbtree_element *replacement = NULL;
   cstl_rbtree_element *parent = NULL;

   if (!element->parent)
   {
      /* element is the root and only element of the tree
       * therefore, we simply remove it, and we're done */
      element->rbtree->root = NULL;
   }
   else
   {
      /* get a pointer to the parent */
      parent = element->parent;

      /* element is the parents right child */

      if (element->left)
      {
         replacement = element->left;
         parent->right = replacement;
         replacement->parent = parent;
      }
      else if (element->right)
      {
         replacement = element->right;
         parent->right = replacement;
         replacement->parent = parent;
      }
      else
      {
         parent->right = NULL;
      }
   }

   /* remove the element and its data from the tree */
   element->rbtree->destroy(element->data,
                            element->rbtree->destroy_arg);
   free(element);

   cstl_rbtree_remove_rebalance(replacement,
                                parent);

   return 0;
}

int cstl_rbtree_unlink(cstl_rbtree *rbtree,
                       void *data,
                       void **retData)
{
   return cstl_rbtree_unlink_element(cstl_rbtree_find(rbtree, data), retData);
}

int cstl_rbtree_unlink_element(cstl_rbtree_element *element,
                               void **retData)
{
   /* ensure that the rbtree is not null */
   if (!element)
      return -1;

   /* ensure that the rbtree is not null */
   if (!element->rbtree)
      return -1;

   /* ensure that the rbtree is valid */
   if (CSTL_RBTREE_VALIDATOR != element->rbtree->validator)
      return -1;

   /* find the predecessor */
   if ((NULL != element->left) && (NULL != element->right))
   {
      /* find the predecessor */
      cstl_rbtree_element *deleted = element;
      cstl_rbtree_element *iter = element->left;

      while (NULL != iter)
      {
         deleted = iter;
         iter = iter->right;
      }

      /* swap the data of the two elements */
      void *tmp = deleted->data;
      deleted->data = element->data;
      element->data = tmp;
      element = deleted;
   }

   /* parent and sibling pointers */
   cstl_rbtree_element *replacement = NULL;
   cstl_rbtree_element *parent = NULL;

   if (!element->parent)
   {
      /* element is the root and only element of the tree
       * therefore, we simply remove it, and we're done */
      element->rbtree->root = NULL;
   }
   else
   {
      /* get a pointer to the parent */
      parent = element->parent;

      /* element is the parents right child */

      if (element->left)
      {
         replacement = element->left;
         parent->right = replacement;
         replacement->parent = parent;
      }
      else if (element->right)
      {
         replacement = element->right;
         parent->right = replacement;
         replacement->parent = parent;
      }
      else
      {
         parent->right = NULL;
      }
   }


   /* retData can be NULL, and this indicates that the developer
    * already has a poiner to the item and just wants it removed
    * from the tree */
   if (NULL != retData)
   {
      /* point retData to the element data */
      (*retData) = element->data;
   }

   /* remove the element from the tree */
   free(element);

   cstl_rbtree_remove_rebalance(replacement,
                                parent);

   return 0;
}

void cstl_rbtree_remove_case1(cstl_rbtree_element *replacement,
                                  cstl_rbtree_element *parent);
void cstl_rbtree_remove_case2_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent);
void cstl_rbtree_remove_case2_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent);
void cstl_rbtree_remove_case3_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent);
void cstl_rbtree_remove_case3_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent);
void cstl_rbtree_remove_case4_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent);
void cstl_rbtree_remove_case4_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent);
void cstl_rbtree_remove_case5_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent);
void cstl_rbtree_remove_case5_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent);
void cstl_rbtree_remove_case6_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent);
void cstl_rbtree_remove_case6_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent);

void cstl_rbtree_remove_rebalance(cstl_rbtree_element *replacement,
                                  cstl_rbtree_element *parent)
{
   if (cstl_rbtree_color(replacement) == RED)
   {
      replacement->color = BLACK;
   }
   else
   {
      cstl_rbtree_remove_case1(replacement,
                               parent);
   }
}


void cstl_rbtree_remove_case1(cstl_rbtree_element *replacement,
                              cstl_rbtree_element *parent)
{
   if (parent);
   {
      if (replacement == parent->left)
      {
         cstl_rbtree_remove_case2_left(replacement,
                                       parent);
      }
      else
      {
         cstl_rbtree_remove_case2_right(replacement,
                                        parent);
      }
   }
}

void cstl_rbtree_remove_case2_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent)
{
   cstl_rbtree_element *sibling = parent->right;

   if (cstl_rbtree_color(sibling) == RED)
   {
      parent->color = RED;
      sibling->color = BLACK;

      cstl_rbtree_rotate_left(parent);
      sibling = parent->right;

      cstl_rbtree_remove_case4_left(replacement,
                                    parent);
   }
   else
   {
      cstl_rbtree_remove_case3_left(replacement,
                                    parent);
   }
}

void cstl_rbtree_remove_case2_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent)
{
   cstl_rbtree_element *sibling = parent->left;

   if (cstl_rbtree_color(sibling) == RED)
   {
      parent->color = RED;
      sibling->color = BLACK;

      cstl_rbtree_rotate_right(parent);
      sibling = parent->left;

      cstl_rbtree_remove_case4_right(replacement,
                                     parent);
   }
   else
   {
      cstl_rbtree_remove_case3_right(replacement,
                                     parent);
   }
}

void cstl_rbtree_remove_case3_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent) == BLACK) &&
       (cstl_rbtree_color(parent->right) == BLACK) &&
       (cstl_rbtree_color(parent->right->left) == BLACK) &&
       (cstl_rbtree_color(parent->right->right) == BLACK))
   {
      parent->right->color = RED;

      cstl_rbtree_remove_case1(parent,
                               parent->parent);
   }
   else
   {
      cstl_rbtree_remove_case4_left(replacement,
                                    parent);
   }
}

void cstl_rbtree_remove_case3_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent) == BLACK) &&
       (cstl_rbtree_color(parent->left) == BLACK) &&
       (cstl_rbtree_color(parent->left->left) == BLACK) &&
       (cstl_rbtree_color(parent->left->right) == BLACK))
   {
      parent->left->color = RED;

      cstl_rbtree_remove_case1(parent,
                               parent->parent);
   }
   else
   {
      cstl_rbtree_remove_case4_right(replacement,
                                     parent);
   }
}

void cstl_rbtree_remove_case4_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent) == RED) &&
       (cstl_rbtree_color(parent->right) == BLACK) &&
       (cstl_rbtree_color(parent->right->left) == BLACK) &&
       (cstl_rbtree_color(parent->right->right) == BLACK))
   {
      parent->right->color = RED;
      parent->color = BLACK;
   }
   else
   {
      cstl_rbtree_remove_case5_left(replacement,
                                    parent);
   }
}

void cstl_rbtree_remove_case4_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent) == RED) &&
       (cstl_rbtree_color(parent->left) == BLACK) &&
       (cstl_rbtree_color(parent->left->left) == BLACK) &&
       (cstl_rbtree_color(parent->left->right) == BLACK))
   {
      parent->left->color = RED;
      parent->color = BLACK;
   }
   else
   {
      cstl_rbtree_remove_case5_right(replacement,
                                     parent);
   }
}


void cstl_rbtree_remove_case5_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent->right) == BLACK) &&
       (cstl_rbtree_color(parent->right->left) == RED) &&
       (cstl_rbtree_color(parent->right->right) == BLACK))
   {
      parent->right->color = RED;
      parent->right->left->color = BLACK;
      cstl_rbtree_rotate_right(parent->right);
      parent->right = parent->right->parent;
   }

   cstl_rbtree_remove_case6_left(replacement,
                                 parent);
}

void cstl_rbtree_remove_case5_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent)
{
   if ((cstl_rbtree_color(parent->left) == BLACK) &&
       (cstl_rbtree_color(parent->left->right) == RED) &&
       (cstl_rbtree_color(parent->left->left) == BLACK))
   {
      parent->left->color = RED;
      parent->left->right->color = BLACK;
      cstl_rbtree_rotate_left(parent->left);
      parent->left = parent->left->parent;
   }

   cstl_rbtree_remove_case6_right(replacement,
                                  parent);
}

void cstl_rbtree_remove_case6_left(cstl_rbtree_element *replacement,
                                   cstl_rbtree_element *parent)
{
   parent->right->color = parent->color;
   parent->color = BLACK;
   parent->right->right->color = BLACK;
   cstl_rbtree_rotate_left(parent);
}

void cstl_rbtree_remove_case6_right(cstl_rbtree_element *replacement,
                                    cstl_rbtree_element *parent)
{
   parent->left->color = parent->color;
   parent->color = BLACK;
   parent->left->left->color = BLACK;
   cstl_rbtree_rotate_right(parent);
}

cstl_rbtree_element_color cstl_rbtree_color(cstl_rbtree_element *element)
{
   /* NULL elements are black */
   if (!element)
      return BLACK;
   else
      return element->color;
}

void cstl_rbtree_rotate_left(cstl_rbtree_element *element)
{
   /* don't attempt to rotate a NULL element */
   if (!element)
      return;

   /* don't attempt to rotate an element with a NULL right child */
   if (!element->right)
      return;

   /* get a pointer to element's right child */
   cstl_rbtree_element *right;
   right = element->right;

   /* reparent right's left child to be element's right child */
   element->right = right->left;
   right->left->parent = element;

   /* reparent element to be right's left child */
   right->left = element;
   element->parent = right;
}

void cstl_rbtree_rotate_right(cstl_rbtree_element *element)
{
   /* don't attempt to rotate a NULL element */
   if (!element)
      return;

   /* don't attempt to rotate an element with a NULL left child */
   if (!element->left)
      return;

   /* get a pointer to element's left child */
   cstl_rbtree_element *left;
   left = element->left;

   /* reparent right's left child to be element's right child */
   element->left = left->right;
   left->right->parent = element;

   /* reparent element to be right's left child */
   left->right = element;
   element->parent = left;
}
