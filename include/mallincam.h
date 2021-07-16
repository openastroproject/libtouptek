/*****************************************************************************
 *
 * mallincam.h -- Touptek library header for Mallincam cameras
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

#ifndef OA_MALLINCAM_H
#define OA_MALLINCAM_H

// Defines for:
//
// 1. function name
// 2. library handle type
// 3. config flag prefix
// 4. option flag prefix
// 5. pointer to library function
// 6. defined value prefix
// 7. function prototype for callback parameters

// Function name
#define TT_FUNC( suffix)			Mallincam_ ## suffix

// library handle type
#define	TT_HANDLE							HToupCam

// config flag prefix
#define	TT_FLAG( flag )				MALLINCAM_FLAG_ ## flag

// option flag prefix
#define	TT_OPTION( option )		MALLINCAM_OPTION_ ## option

// define prefix
#define	TT_DEFINE( var )			MALLINCAM_ ## var

// variable type prefix
#define TT_TYPE( type )				Toupcam ## type

// function type
#define TT_FUNC_TYPE( prefix, suffix )	prefix ## MALLINCAM_ ## suffix


#include <touptek/defines.h>
#include <touptek/types.h>
#include <touptek/flags.h>
#include <touptek/options.h>
#include <touptek/functions.h>

#endif	/* OA_MALLINCAM_H */
