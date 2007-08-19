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

#ifndef CSTL_QUEUE_H
#define CSTL_QUEUE_H

#include "cstl_list.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef cstl_list_element cstl_queue_element;
typedef cstl_list cstl_queue;

/* initialize a doubly linked queue */
extern int cstl_queue_initialize(cstl_queue *queue);

/* destroy a doubly linked queue */
extern int cstl_queue_destroy(cstl_queue *queue);

/* retrieve the number of elements in a queue */
extern int cstl_queue_size(cstl_queue *queue);

/* retrieve the data from a queue element */
extern void *cstl_queue_front(cstl_queue *queue);

/* insert the data at the beginning of the linked queue */
extern int cstl_queue_push(cstl_queue *queue,
                           void *data);

/* remove the element from the end of the linked queue while calling the
 * destroy method */
extern int cstl_queue_pop(cstl_queue *queue);

#ifdef __cplusplus
}
#endif

#endif
