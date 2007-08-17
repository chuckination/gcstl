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
 * $URL: https://gcstl.svn.sourceforge.net/svnroot/gcstl/trunk/src/list/cstl_list.h $
 * $Id: cstl_list.h 56 2007-07-31 05:10:01Z chuck_s $
 *
 ******************************************************************************/

#ifndef CSTL_STACK_H
#define CSTL_STACK_H

#include "cstl_list.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef cstl_list_element cstl_stack_element;
typedef cstl_list cstl_stack;

/* initialize a doubly linked stack */
extern int cstl_stack_initialize(cstl_stack *stack,
                                 void (*destroy)(void *));

/* destroy a doubly linked stack */
extern int cstl_stack_destroy(cstl_stack *stack);

/* retrieve the number of elements in a stack */
extern int cstl_stack_size(cstl_stack *stack);

/* retrieve the data from a stack element */
extern void *cstl_stack_data(cstl_stack_element *element);

/* insert the data at the beginning of the linked stack */
extern int cstl_stack_push_front(cstl_stack *stack,
                                 void *data);

/* remove the element from the beginning of the linked stack while calling the
 * destroy method */
extern int cstl_stack_pop_front(cstl_stack *stack);

/* remove the element from the beginning of the linked stack while not calling
 * the destroy method */
extern int cstl_stack_unlink_front(cstl_stack *stack,
                                   void **retData);

#ifdef __cplusplus
}
#endif

#endif
