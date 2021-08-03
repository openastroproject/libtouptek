/*****************************************************************************
 *
 * starshootg.c -- List StarshootG cameras that are connected to the system
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

#include <starshootg.h>

#include "internals.h"
#include "getSettings.h"


unsigned
Starshootg_EnumV2 ( oaTouptekDeviceV2 deviceList[ OA_TOUPTEK_MAX ])
{
	return oaTouptek_EnumV2 ( OA_BRAND_STARSHOOTG, deviceList );
}


HRESULT
Starshootg_get_BlackBalance ( TT_HANDLE handle, unsigned short bal[3] )
{
	return getBlackBalance ( handle, bal );
}


HRESULT
Starshootg_get_Contrast ( TT_HANDLE handle, int* pContrast )
{
	return getContrast ( handle, pContrast );
}


HRESULT
Starshootg_get_Gamma ( TT_HANDLE handle, int* pGamma )
{
	return getGamma ( handle, pGamma );
}


HRESULT
Starshootg_get_HFlip ( TT_HANDLE handle, int* pHFlip )
{
	return getHFlip ( handle, pHFlip );
}


HRESULT
Starshootg_get_VFlip ( TT_HANDLE handle, int* pVFlip )
{
	return getVFlip ( handle, pVFlip );
}
