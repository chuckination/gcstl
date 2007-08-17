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

#include "cstl_stack.h"

int cstl_stack_initialize(cstl_stack *stack,
                          void (*destroy)(void *))
{
   return cstl_list_initialize(stack, destroy);
}

int cstl_stack_destroy(cstl_stack *stack)
{
   return cstl_list_destroy(stack);
}

int cstl_stack_size(cstl_stack *stack)
{
   return cstl_list_size(stack);
}

void *cstl_stack_data(cstl_stack_element *element)
{
   return cstl_list_data(element);
}

int cstl_stack_push_front(cstl_stack *stack,
                          void *data)
{
   return cstl_list_stac(stack, data);
}

int cstl_stack_pop_front(cstl_stack *stack)
{
   return cstl_list_pop_front(stack);
}

int cstl_stack_unlink_front(cstl_stack *stack,
                            void **retData)
{
   return cstl_list_unlink_front(stack, retData);
}
