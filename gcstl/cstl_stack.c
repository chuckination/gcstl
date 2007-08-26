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
 * $URL: https://gcstl.svn.sourceforge.net/svnroot/gcstl/trunk/src/list/cstl_list.c $
 * $Id: cstl_list.c 56 2007-07-31 05:10:01Z chuck_s $
 *
 ******************************************************************************/

#include "gcstl/cstl_stack.h"

void cstl_stack_destroy_null(void *data)
{
   /* do nothing */
}

int cstl_stack_initialize(cstl_stack *stack)
{
   return cstl_list_initialize(stack, cstl_stack_destroy_null);
}

int cstl_stack_destroy(cstl_stack *stack)
{
   return cstl_list_destroy(stack);
}

int cstl_stack_size(cstl_stack *stack)
{
   return cstl_list_size(stack);
}

void *cstl_stack_top(cstl_stack *stack)
{
   return cstl_list_data(cstl_list_begin(stack));
}

int cstl_stack_push(cstl_stack *stack,
                    void *data)
{
   return cstl_list_push_front(stack, data);
}

int cstl_stack_pop(cstl_stack *stack)
{
   return cstl_list_pop_front(stack);
}
