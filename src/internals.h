/*****************************************************************************
 *
 * internals.h -- Internal library header
 *
 * Copyright 2021
 *   James Fidell (james@openastroproject.org)
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

#ifndef INTERNALS_H
#define INTERNALS_H

#include <stdint.h>
#include <libusb-1.0/libusb.h>

#include <touptek/defines.h>

#define	OA_BRAND_TOUPCAM			0
#define	OA_BRAND_NNCAM				1
#define	OA_BRAND_ALTAIRCAM		2
#define	OA_BRAND_MALLINCAM		3
#define	OA_BRAND_MEADECAM			4
#define	OA_BRAND_OMEGONPROCAM	5
#define	OA_BRAND_STARSHOOTG		6

#define	VID_TOUPTEK						0x0547
#define	VID_OLD_ALTAIR				0x16d0
#define	VID_ALT_MEADE					0x0549

extern unsigned oaTouptek_EnumV2 ( uint8_t, oaTouptekDeviceV2* );

extern unsigned enumerate ( uint8_t, oaTouptekDeviceV2*, unsigned short,
		unsigned short, int, libusb_device_handle** );

#endif	/* INTERNALS_H */
