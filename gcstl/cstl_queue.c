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

#include "gcstl/cstl_queue.h"

void cstl_queue_destroy_null(void *data)
{
   /* do nothing */
}

int cstl_queue_initialize(cstl_queue *queue)
{
   return cstl_list_initialize(queue, cstl_queue_destroy_null);
}

int cstl_queue_destroy(cstl_queue *queue)
{
   return cstl_list_destroy(queue);
}

int cstl_queue_size(cstl_queue *queue)
{
   return cstl_list_size(queue);
}

void *cstl_queue_front(cstl_queue *queue)
{
   return cstl_list_data(cstl_list_begin(queue));
}

int cstl_queue_push(cstl_queue *queue,
                    void *data)
{
   return cstl_list_push_back(queue, data);
}

int cstl_queue_pop(cstl_queue *queue)
{
   return cstl_list_pop_front(queue);
}
