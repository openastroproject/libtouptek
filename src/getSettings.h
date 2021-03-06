/*****************************************************************************
 *
 * getSettings.h -- Header for camera settings read functions
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

#ifndef GET_SETTINGS_H
#define GET_SETTINGS_H

#include "cameras.h"

extern HRESULT	getBlackBalance ( const cameraCtx*, unsigned short bal[3] );
extern HRESULT	getContrast ( const cameraCtx*, int* );
extern HRESULT	getGamma ( const cameraCtx*, int* );
extern HRESULT	getHFlip ( const cameraCtx*, int* );
extern HRESULT	getVFlip ( const cameraCtx*, int* );

#endif	/* GET_SETTINGS_H */
