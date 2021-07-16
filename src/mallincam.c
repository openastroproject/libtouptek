/*****************************************************************************
 *
 * mallincam.c -- List Mallincam cameras that are connected to the system
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

#include <mallincam.h>

#include "internals.h"


unsigned
Mallincam_EnumV2 ( oaTouptekDeviceV2 deviceList[ OA_TOUPTEK_MAX ])
{
	return oaTouptek_EnumV2 ( OA_BRAND_MALLINCAM, deviceList );
}
