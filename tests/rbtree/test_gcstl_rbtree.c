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

#include <tests/rbtree/test_gcstl_rbtree.h>
#include <gcstl/gcstl_rbtree.h>

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

void test_gcstl_rbtree_insert()
{
   /* initialize an rbtree */
   gcstl_rbtree myRbtree;
   int initVal = gcstl_rbtree_initialize(&myRbtree,
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

   gcstl_rbtree_element *myElement = gcstl_rbtree_find(&myRbtree, myIntp1);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp2 = NULL;
   myIntp2 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp2);
   *myIntp2 = 2;

   myElement = gcstl_rbtree_find(&myRbtree, myIntp2);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp3 = NULL;
   myIntp3 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp3);
   *myIntp3 = 3;

   myElement = gcstl_rbtree_find(&myRbtree, myIntp3);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp4 = NULL;
   myIntp4 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp4);
   *myIntp4 = 4;

   int *myIntp5 = NULL;
   myIntp5 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp5);
   *myIntp5 = 5;

   int *myIntp6 = NULL;
   myIntp6 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp6);
   *myIntp6 = 6;

   int *myIntp7 = NULL;
   myIntp7 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp7);
   *myIntp7 = 7;

   int *myIntp8 = NULL;
   myIntp8 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp8);
   *myIntp8 = 8;

   int *myIntp9 = NULL;
   myIntp9 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp9);
   *myIntp9 = 9;

   int *myIntp10 = NULL;
   myIntp10 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp10);
   *myIntp10 = 10;

   /* verify that an item cannot be found in the tree */
   myElement = gcstl_rbtree_find(&myRbtree, myIntp4);
   CU_ASSERT_EQUAL(NULL, myElement);

   /* insert the items into the tree */
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp1));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp2));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp3));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp4));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp5));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp6));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp7));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp8));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp9));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp10));

   /* no verify that the items can be found in the tree */
   int myInt1 = 1;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt1);
   CU_ASSERT_EQUAL(myIntp1, gcstl_rbtree_data(myElement));

   int myInt2 = 2;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt2);
   CU_ASSERT_EQUAL(myIntp2, gcstl_rbtree_data(myElement));

   int myInt3 = 3;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt3);
   CU_ASSERT_EQUAL(myIntp3, gcstl_rbtree_data(myElement));

   int myInt4 = 4;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt4);
   CU_ASSERT_EQUAL(myIntp4, gcstl_rbtree_data(myElement));

   int myInt5 = 5;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt5);
   CU_ASSERT_EQUAL(myIntp5, gcstl_rbtree_data(myElement));

   int myInt6 = 6;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt6);
   CU_ASSERT_EQUAL(myIntp6, gcstl_rbtree_data(myElement));

   int myInt7 = 7;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt7);
   CU_ASSERT_EQUAL(myIntp7, gcstl_rbtree_data(myElement));

   int myInt8 = 8;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt8);
   CU_ASSERT_EQUAL(myIntp8, gcstl_rbtree_data(myElement));

   int myInt9 = 9;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt9);
   CU_ASSERT_EQUAL(myIntp9, gcstl_rbtree_data(myElement));

   int myInt10 = 10;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt10);
   CU_ASSERT_EQUAL(myIntp10, gcstl_rbtree_data(myElement));

   /* clean up the tree */
   gcstl_rbtree_destroy(&myRbtree);
}

void test_gcstl_rbtree_remove()
{
   /* initialize an rbtree */
   gcstl_rbtree myRbtree;
   int initVal = gcstl_rbtree_initialize(&myRbtree,
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

   gcstl_rbtree_element *myElement = gcstl_rbtree_find(&myRbtree, myIntp1);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp2 = NULL;
   myIntp2 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp2);
   *myIntp2 = 2;

   myElement = gcstl_rbtree_find(&myRbtree, myIntp2);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp3 = NULL;
   myIntp3 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp3);
   *myIntp3 = 3;

   myElement = gcstl_rbtree_find(&myRbtree, myIntp3);
   CU_ASSERT_EQUAL(NULL, myElement);

   int *myIntp4 = NULL;
   myIntp4 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp4);
   *myIntp4 = 4;

   int *myIntp5 = NULL;
   myIntp5 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp5);
   *myIntp5 = 5;

   int *myIntp6 = NULL;
   myIntp6 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp6);
   *myIntp6 = 6;

   int *myIntp7 = NULL;
   myIntp7 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp7);
   *myIntp7 = 7;

   int *myIntp8 = NULL;
   myIntp8 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp8);
   *myIntp8 = 8;

   int *myIntp9 = NULL;
   myIntp9 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp9);
   *myIntp9 = 9;

   int *myIntp10 = NULL;
   myIntp10 = (int *) malloc(sizeof(int));
   CU_ASSERT_NOT_EQUAL(NULL, myIntp10);
   *myIntp10 = 10;

   /* verify that an item cannot be found in the tree */
   myElement = gcstl_rbtree_find(&myRbtree, myIntp4);
   CU_ASSERT_EQUAL(NULL, myElement);

   /* insert the items into the tree */
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp1));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp2));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp3));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp4));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp5));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp6));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp7));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp8));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp9));
   CU_ASSERT_EQUAL(0, gcstl_rbtree_insert(&myRbtree, myIntp10));

   /* no verify that the items can be found in the tree */
   int myInt1 = 1;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt1);
   CU_ASSERT_EQUAL(myIntp1, gcstl_rbtree_data(myElement));

   int myInt2 = 2;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt2);
   CU_ASSERT_EQUAL(myIntp2, gcstl_rbtree_data(myElement));

   int myInt3 = 3;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt3);
   CU_ASSERT_EQUAL(myIntp3, gcstl_rbtree_data(myElement));

   int myInt4 = 4;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt4);
   CU_ASSERT_EQUAL(myIntp4, gcstl_rbtree_data(myElement));

   int myInt5 = 5;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt5);
   CU_ASSERT_EQUAL(myIntp5, gcstl_rbtree_data(myElement));

   int myInt6 = 6;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt6);
   CU_ASSERT_EQUAL(myIntp6, gcstl_rbtree_data(myElement));

   int myInt7 = 7;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt7);
   CU_ASSERT_EQUAL(myIntp7, gcstl_rbtree_data(myElement));

   int myInt8 = 8;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt8);
   CU_ASSERT_EQUAL(myIntp8, gcstl_rbtree_data(myElement));

   int myInt9 = 9;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt9);
   CU_ASSERT_EQUAL(myIntp9, gcstl_rbtree_data(myElement));

   int myInt10 = 10;
   myElement = gcstl_rbtree_find(&myRbtree, &myInt10);
   CU_ASSERT_EQUAL(myIntp10, gcstl_rbtree_data(myElement));

   /* remove a single item by pointer from the tree */
   CU_ASSERT_EQUAL(0, gcstl_rbtree_remove_element(myElement));
   CU_ASSERT_EQUAL(myIntp1,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt1)));
   CU_ASSERT_EQUAL(myIntp2,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt2)));
   CU_ASSERT_EQUAL(myIntp3,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt3)));
   CU_ASSERT_EQUAL(myIntp4,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt4)));
   CU_ASSERT_EQUAL(myIntp5,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt5)));
   CU_ASSERT_EQUAL(myIntp6,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt6)));
   CU_ASSERT_EQUAL(myIntp7,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt7)));
   CU_ASSERT_EQUAL(myIntp8,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt8)));
   CU_ASSERT_EQUAL(myIntp9,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt9)));
   CU_ASSERT_EQUAL(NULL, gcstl_rbtree_find(&myRbtree, &myInt10));

   /* remove a single item by value from the tree */
   CU_ASSERT_EQUAL(0, gcstl_rbtree_remove(&myRbtree, &myInt9));
   CU_ASSERT_EQUAL(myIntp1,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt1)));
   CU_ASSERT_EQUAL(myIntp2,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt2)));
   CU_ASSERT_EQUAL(myIntp3,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt3)));
   CU_ASSERT_EQUAL(myIntp4,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt4)));
   CU_ASSERT_EQUAL(myIntp5,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt5)));
   CU_ASSERT_EQUAL(myIntp6,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt6)));
   CU_ASSERT_EQUAL(myIntp7,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt7)));
   CU_ASSERT_EQUAL(myIntp8,
                   gcstl_rbtree_data(gcstl_rbtree_find(&myRbtree, &myInt8)));
   CU_ASSERT_EQUAL(NULL, gcstl_rbtree_find(&myRbtree, &myInt9));
   CU_ASSERT_EQUAL(NULL, gcstl_rbtree_find(&myRbtree, &myInt10));

   /* clean up the tree */
   int destroyVal = gcstl_rbtree_destroy(&myRbtree);
   CU_ASSERT_EQUAL(0, destroyVal);
}
