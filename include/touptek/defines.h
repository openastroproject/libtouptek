/*****************************************************************************
 *
 * defines.h -- Defined values for Touptek-style SDK
 *
 * Copyright 2021 James Fidell (james@openastroproject.org)
 *
 * License:
 *
 * This file is part of the Open Astro Project.
 *
 * The Open Astro Project is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Open Astro Project is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Open Astro Project.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#ifndef OA_TOUPTEK_DEFINES_H
#define OA_TOUPTEK_DEFINES_H

#ifndef HRESULT
#define	HRESULT		int
#endif

#define	OA_TOUPTEK_MAX	16
#define	OA_STRING_MAX		64

#ifndef	SUCCEEDED
#define	SUCCEEDED(r)		((( HRESULT )( r )) >= 0 )
#endif

#ifndef	FAILED
#define	FAILED(r)				((( HRESULT )( r )) < 0 )
#endif

// Can't see a generic way to do this at the moment, short of using
// a const or something like that
#define	TOUPCAM_MAX			OA_TOUPTEK_MAX
#define	ALTAIRCAM_MAX		OA_TOUPTEK_MAX
#define	MALLINCAM_MAX		OA_TOUPTEK_MAX

#endif	/* OA_TOUPTEK_DEFINES_H */
