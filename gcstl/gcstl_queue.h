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

#ifndef GCSTL_QUEUE_H
#define GCSTL_QUEUE_H

#include <gcstl/gcstl_list.h>

/*!
 * @defgroup gcstl gcstl
 * @defgroup queue queue
 *
 * @ingroup gcstl
 * @ingroup gcstl queue
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* forward declarations */
typedef gcstl_list_element gcstl_queue_element;
typedef gcstl_list gcstl_queue;

/* initialize a doubly linked queue */
extern int gcstl_queue_initialize(gcstl_queue *queue);

/* destroy a doubly linked queue */
extern int gcstl_queue_destroy(gcstl_queue *queue);

/* retrieve the number of elements in a queue */
extern int gcstl_queue_size(gcstl_queue *queue);

/* retrieve the data from a queue element */
extern void *gcstl_queue_front(gcstl_queue *queue);

/* insert the data at the beginning of the linked queue */
extern int gcstl_queue_push(gcstl_queue *queue,
                           void *data);

/* remove the element from the end of the linked queue while calling the
 * destroy method */
extern int gcstl_queue_pop(gcstl_queue *queue);

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif
