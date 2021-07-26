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
#define	TOUPCAM_MAX				OA_TOUPTEK_MAX
#define	ALTAIRCAM_MAX			OA_TOUPTEK_MAX
#define	MALLINCAM_MAX			OA_TOUPTEK_MAX
#define	STARSHOOTG_MAX		OA_TOUPTEK_MAX
#define	MEADECAM_MAX			OA_TOUPTEK_MAX
#define	NNCAM_MAX					OA_TOUPTEK_MAX
#define	OMEGONPROCAM_MAX	OA_TOUPTEK_MAX

#define	S_OK							0x00000000
#define	S_FALSE						0x00000001
#define	E_FAIL						0x80004005
#define	E_ACCESS_DEFINED	0x80070005
#define	E_INVALIDARG			0x80070057
#define	E_NOTIMPL					0x80004001
#define	E_POINTER					0x80004003
#define	E_UNEXPECTED			0x8000FFFF
#define	E_OUTOFMEMORY			0x8007000E
#define	E_WRONG_THREAD		0x8001010E
#define	E_GEN_FAILURE			0x8007001F
#define	E_PENDING					0x8000000A

#endif	/* OA_TOUPTEK_DEFINES_H */
