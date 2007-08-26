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

#include <gcstl/gcstl_queue.h>

void gcstl_queue_destroy_null(void *data)
{
   /* do nothing */
}

int gcstl_queue_initialize(gcstl_queue *queue)
{
   return gcstl_list_initialize(queue, gcstl_queue_destroy_null);
}

int gcstl_queue_destroy(gcstl_queue *queue)
{
   return gcstl_list_destroy(queue);
}

int gcstl_queue_size(gcstl_queue *queue)
{
   return gcstl_list_size(queue);
}

void *gcstl_queue_front(gcstl_queue *queue)
{
   return gcstl_list_data(gcstl_list_begin(queue));
}

int gcstl_queue_push(gcstl_queue *queue,
                    void *data)
{
   return gcstl_list_push_back(queue, data);
}

int gcstl_queue_pop(gcstl_queue *queue)
{
   return gcstl_list_pop_front(queue);
}
