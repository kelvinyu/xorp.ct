/* -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*- */
/* vim:set sts=4 ts=8: */

/*
 * Copyright (c) 2001-2009 XORP, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, Version 2, June
 * 1991 as published by the Free Software Foundation. Redistribution
 * and/or modification of this program under the terms of any other
 * version of the GNU General Public License is not permitted.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
 * see the GNU General Public License, Version 2, a copy of which can be
 * found in the XORP LICENSE.gpl file.
 * 
 * XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
 * http://xorp.net
 */

/*
 * $XORP: xorp/mrt/max_vifs.h,v 1.14 2008/10/02 21:57:45 bms Exp $
 */

#ifndef __MRT_MAX_VIFS_H__
#define __MRT_MAX_VIFS_H__

/*
 * Header file to define the maximum number of multicast-capable vifs:
 * the constant MAX_VIFS.
 */

#include "libxorp/xorp.h"

#include "mrt/include/ip_mroute.h"


/*
 * Constants definitions
 */

/*
 * XXX: Define MAX_VIFS to be the largest of MAXVIFS, MAXMIFS, and 32
 */
#ifndef MAX_VIFS
#  define MAX_VIFS 32
#elif (32 > MAX_VIFS)
#  undef MAX_VIFS
#  define MAX_VIFS 32
#endif

#if defined(MAXVIFS) && (MAXVIFS > MAX_VIFS)
#  undef MAX_VIFS
#  define MAX_VIFS MAXVIFS
#endif // MAXVIFS > MAX_VIFS

#if defined(MAXMIFS) && (MAXMIFS > MAX_VIFS)
#  undef MAX_VIFS
#  define MAX_VIFS MAXMIFS
#endif // MAXMIFS > MAX_VIFS


/*
 * Structures, typedefs and macros
 */

/*
 * Global variables
 */

/*
 * Global functions prototypes
 */

__BEGIN_DECLS

__END_DECLS

#endif /* __MRT_MAX_VIFS_H__ */
