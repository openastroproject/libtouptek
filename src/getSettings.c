/*****************************************************************************
 *
 * getSettings.c -- Handle requests for camera settings
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

#include <touptek/defines.h>

#include "getSettings.h"


HRESULT
getContrast ( const cameraCtx* ctx, int* pContrast )
{
	// FIX ME -- may not be supported for all cameras

	cameraSettings*		settings = ctx->settings;

	*pContrast = settings->contrast;
	return S_OK;
}


HRESULT
getGamma ( const cameraCtx* ctx, int* pGamma )
{
	// FIX ME -- may not be supported for all cameras

	cameraSettings*		settings = ctx->settings;

	*pGamma = settings->gamma;
	return S_OK;
}


HRESULT
getBlackBalance ( const cameraCtx* ctx, unsigned short bal[3] )
{
	// FIX ME -- may not be supported for all cameras

	cameraSettings*		settings = ctx->settings;

	bal[0] = settings->blackBalanceRed;
	bal[1] = settings->blackBalanceGreen;
	bal[2] = settings->blackBalanceBlue;
	return S_OK;
}
