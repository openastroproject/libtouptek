/*****************************************************************************
 *
 * cameras.h -- Camera list management
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

#ifndef CAMERAS_H
#define CAMERAS_H

#include <stdint.h>

#define MAX_PRODUCT_IDS		4
#define	MAX_BRANDS				7
#define	MAX_CAMERAS				798

typedef struct cameraData {
	const uint16_t						productIds[ MAX_PRODUCT_IDS ];
	const uint8_t							matchOldAltair;
	const uint8_t							matchAltMeade;
	const unsigned long long	capabilities;
	const char*								name[ MAX_BRANDS ];
} cameraData;
	
extern cameraData cameras[ MAX_CAMERAS ];

#endif	/* CAMERAS_H */
