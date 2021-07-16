/*****************************************************************************
 *
 * types.h -- Type declarations for Touptek-style SDK
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

#ifndef OA_TOUPTEK_TYPES_H
#define OA_TOUPTEK_TYPES_H

typedef	void*			TT_HANDLE;

typedef struct {
	unsigned				biSize;
	int							biWidth;
	int							biHeight;
	unsigned short	biPlanes;
	unsigned short	biBitCount;
	unsigned				biCompression;
	unsigned				biSizeImage;
	int							biXPelsPerMeter;
	int							biYPelsPerMeter;
	unsigned				biClrUsed;
	unsigned				biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
	int							left;
	int							top;
	int							right;
	int							bottom;
} RECT;

typedef RECT*			PRECT;

typedef struct {
	unsigned				width;
	unsigned				height;
} oaTouptekResolution;

typedef oaTouptekResolution		TT_TYPE( Resolution );

typedef struct {
	const char*					name;        // camera model name
	unsigned long long	flag;        // camera capabilities
	unsigned						maxspeed;    // = ..._get_MaxSpeed()
	unsigned						preview;     // = ..._get_ResolutionNumber()
	unsigned						still;       // = ..._get_StillResolutionNumber()
	unsigned						maxfanspeed; // maximum fan speed
	unsigned						ioctrol;     // number of i/o control lines
	float								xpixsz;      /* physical pixel width */
	float								ypixsz;      /* physical pixel height */
	oaTouptekResolution	res[ OA_TOUPTEK_MAX ];
} oaTouptekModelV2;

typedef oaTouptekModelV2			TT_TYPE( ModelV2 );

typedef struct {
	char								displayname[ OA_STRING_MAX ];
	char								id [ OA_STRING_MAX ];
} oaTouptekDeviceV2;

typedef oaTouptekDeviceV2			TT_TYPE( DeviceV2 );

#endif	/* OA_TOUPTEK_TYPES_H */
