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

#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <tests/rbtree/test_gcstl_rbtree.h>

void gcstl_test_testStartPrint()
{
   fprintf(stderr, "\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "starting tests\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "\n");
}

void gcstl_test_testFailedToCompletePrint()
{
   fprintf(stderr, "\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "tests failed to complete\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "\n");
}

void gcstl_test_testCompleteWithFailuresPrint()
{
   fprintf(stderr, "\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "tests completed with failures\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "\n");
}

void gcstl_test_testCompleteSuccessfullyPrint()
{
   fprintf(stderr, "\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "tests completed successfully\n");
   fprintf(stderr, "========================================\n");
   fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
   CU_ErrorCode cuStatus = CU_initialize_registry();
   if (CUE_SUCCESS != cuStatus)
   {
      fprintf(stderr, "could not create CUnit test registry\n");
      return -1;
   }

   gcstl_test_testStartPrint();

   CU_TestInfo test_gcstl_rbtree[] =
      {
         { "test_gcstl_rbtree_insert", test_gcstl_rbtree_insert },
         { "test_gcstl_rbtree_remove", test_gcstl_rbtree_remove },
         CU_TEST_INFO_NULL
      };

   CU_SuiteInfo test_gcstl_suite[] =
      {
         { "test_gcstl_rbtree", NULL, NULL, test_gcstl_rbtree },
         CU_SUITE_INFO_NULL
      };

   cuStatus = CU_register_suites(test_gcstl_suite);
   if (CUE_SUCCESS != cuStatus)
   {
      fprintf(stderr, "could register CUnit test suites\n");
      return -1;
   }

   CU_basic_run_tests();
   if (CUE_SUCCESS != cuStatus)
   {
      gcstl_test_testFailedToCompletePrint();
      return -1;
   }
   else if (0 != CU_get_number_of_tests_failed())
   {
      gcstl_test_testCompleteWithFailuresPrint();
      return -1;
   }

   gcstl_test_testCompleteSuccessfullyPrint();

   CU_cleanup_registry();

   return 0;
}
