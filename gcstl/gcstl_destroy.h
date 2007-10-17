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

#ifndef GCSTL_CLEANUP_H
#define GCSTL_CLEANUP_H

/**
 * @defgroup gcstl gcstl
 * @defgroup destroy destroy
 *
 * @ingroup gcstl
 * @ingroup gcstl destroy
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief default cleup function, calls free() on data
 * @param[in] data the anonymous container element to free
 * */
extern void gcstl_destroy_default(void *data);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif
