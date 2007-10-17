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

#ifndef GCSTL_STACK_H
#define GCSTL_STACK_H

#include <gcstl/gcstl_list.h>

/**
 * @defgroup gcstl gcstl
 * @defgroup stack stack
 *
 * @ingroup gcstl
 * @ingroup gcstl stack
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef gcstl_list_element gcstl_stack_element;
typedef gcstl_list gcstl_stack;

/* initialize a doubly linked stack */
extern int gcstl_stack_initialize(gcstl_stack *stack);

/* destroy a doubly linked stack */
extern int gcstl_stack_destroy(gcstl_stack *stack);

/* retrieve the number of elements in a stack */
extern int gcstl_stack_size(gcstl_stack *stack);

/* retrieve the data from a stack element */
extern void *gcstl_stack_top(gcstl_stack *stack);

/* insert the data at the beginning of the linked stack */
extern int gcstl_stack_push(gcstl_stack *stack,
                           void *data);

/* remove the element from the beginning of the linked stack while calling the
 * destroy method */
extern int gcstl_stack_pop(gcstl_stack *stack);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif
