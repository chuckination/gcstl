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

#include "test_cstl_rbtree.h"
#include "cstl_rbtree.h"

#include <stdlib.h>
#include <stdio.h>

#include <CUnit/CUnit.h>

int basicNumericCompare(void *data1,
                        void *data2,
                        int (*sub_comparator)(void *, void *))
{
   int *int1 = (int *) data1;
   int *int2 = (int *) data2;

   if ((*int1) < (*int2))
   {
      return -1;
   }
   else if ((*int1) > (*int2))
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int basicDestroy(void *data, void *arg)
{
   free(data);
}

void test_cstl_rbtree_insert()
{
   /* initialize an rbtree */
   cstl_rbtree myRbtree;
   int initVal = cstl_rbtree_initialize(&myRbtree,
                                        basicNumericCompare,
                                        NULL,
                                        basicDestroy,
                                        NULL);
   CU_ASSERT_EQUAL(0, initVal);

   /* allocate some items to insert into the tree */
   int *myIntp1 = NULL;
   myIntp1 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp1);
   *myIntp1 = 1;

   cstl_rbtree_element *myElement = cstl_rbtree_find(&myRbtree, myIntp1);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp2 = NULL;
   myIntp2 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp2);
   *myIntp2 = 2;

   myElement = cstl_rbtree_find(&myRbtree, myIntp2);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp3 = NULL;
   myIntp3 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp3);
   *myIntp3 = 3;

   myElement = cstl_rbtree_find(&myRbtree, myIntp3);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp4 = NULL;
   myIntp4 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp4);
   *myIntp4 = 4;

   /* verify that an item cannot be found in the tree */
   myElement = cstl_rbtree_find(&myRbtree, myIntp4);
   CU_ASSERT_EQUAL(NULL, myElement);

   /* insert the items into the tree */
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp1));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp2));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp3));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp4));

   /* no verify that the items can be found in the tree */
   int myInt1 = 1;
   myElement = cstl_rbtree_find(&myRbtree, &myInt1);
   CU_ASSERT_EQUAL(myIntp1, cstl_rbtree_data(myElement));

   int myInt2 = 2;
   myElement = cstl_rbtree_find(&myRbtree, &myInt2);
   CU_ASSERT_EQUAL(myIntp2, cstl_rbtree_data(myElement));

   int myInt3 = 3;
   myElement = cstl_rbtree_find(&myRbtree, &myInt3);
   CU_ASSERT_EQUAL(myIntp3, cstl_rbtree_data(myElement));

   int myInt4 = 4;
   myElement = cstl_rbtree_find(&myRbtree, &myInt4);
   CU_ASSERT_EQUAL(myIntp4, cstl_rbtree_data(myElement));

   /* clean up the tree */
   cstl_rbtree_destroy(&myRbtree);
}

void test_cstl_rbtree_remove()
{
   /* initialize an rbtree */
   cstl_rbtree myRbtree;
   int initVal = cstl_rbtree_initialize(&myRbtree,
                                        basicNumericCompare,
                                        NULL,
                                        basicDestroy,
                                        NULL);
   CU_ASSERT_EQUAL(0, initVal);

   /* allocate some items to insert into the tree */
   int *myIntp1 = NULL;
   myIntp1 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp1);
   *myIntp1 = 1;

   cstl_rbtree_element *myElement = cstl_rbtree_find(&myRbtree, myIntp1);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp2 = NULL;
   myIntp2 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp2);
   *myIntp2 = 2;

   myElement = cstl_rbtree_find(&myRbtree, myIntp2);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp3 = NULL;
   myIntp3 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp3);
   *myIntp3 = 3;

   myElement = cstl_rbtree_find(&myRbtree, myIntp3);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp4 = NULL;
   myIntp4 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp4);
   *myIntp4 = 4;

   /* verify that an item cannot be found in the tree */
   myElement = cstl_rbtree_find(&myRbtree, myIntp4);
   CU_ASSERT_EQUAL(NULL, myElement);

   /* insert the items into the tree */
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp1));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp2));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp3));
   CU_ASSERT_EQUAL(0, cstl_rbtree_insert(&myRbtree, myIntp4));

   /* no verify that the items can be found in the tree */
   int myInt1 = 1;
   myElement = cstl_rbtree_find(&myRbtree, &myInt1);
   CU_ASSERT_EQUAL(myIntp1, cstl_rbtree_data(myElement));

   int myInt2 = 2;
   myElement = cstl_rbtree_find(&myRbtree, &myInt2);
   CU_ASSERT_EQUAL(myIntp2, cstl_rbtree_data(myElement));

   int myInt3 = 3;
   myElement = cstl_rbtree_find(&myRbtree, &myInt3);
   CU_ASSERT_EQUAL(myIntp3, cstl_rbtree_data(myElement));

   int myInt4 = 4;
   myElement = cstl_rbtree_find(&myRbtree, &myInt4);
   CU_ASSERT_EQUAL(myIntp4, cstl_rbtree_data(myElement));

   /* remove a single item from the tree */
   CU_ASSERT_EQUAL(0, cstl_rbtree_remove_element(myElement));
   CU_ASSERT_EQUAL(NULL, cstl_rbtree_find(&myRbtree, &myInt4));

   /* clean up the tree */
   cstl_rbtree_destroy(&myRbtree);
}
