/*****************************************************************************
 *
 * connection.c -- Handle opening and closing cameras
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#include <touptek/defines.h>
#include <touptek/types.h>

#include "cameras.h"
#include "internals.h"
#include "connection.h"


static	cameraCtx*		_openCamera ( uint8_t, const char*, unsigned );


// Can't just call this one open() :)
cameraCtx*
camOpen ( uint8_t brand, const char* id )
{
	return _openCamera ( brand, id, 0 );
}


cameraCtx*
OpenByIndex ( uint8_t brand, unsigned idx )
{
	if ( idx >= OA_TOUPTEK_MAX ) {
		return NULL;
	}
	return _openCamera ( brand, NULL, idx );
}


cameraCtx*
_openCamera ( uint8_t brand, const char* id, unsigned idx )
{
	unsigned short				matchBus = 0;
	unsigned short				matchAddr = 0;
	unsigned short				matchVid = 0;
	unsigned short				matchPid = 0;
	libusb_device_handle*	handle;
	cameraCtx*						ctx;
	cameraSettings*				settings;
	const char*						id2;

	// FIX ME -- we could keep an internal list of opened cameras and prevent
	// a double open here

	if (( ctx = ( cameraCtx* ) malloc ( sizeof ( cameraCtx ))) == NULL ) {
		return NULL;
	}
	if (( settings = ( cameraSettings* ) malloc ( sizeof ( cameraSettings ))) ==
			NULL ) {
		return NULL;
	}

	if ( id != NULL ) {
		// @ or $ at the start of the id are "special"
		// @ means use RGB gain mode instead of Temp/Tint for white balance
		// $ is apparently special, but I don't know what it does yet
		id2 = id;
		if ( *id == '@' || *id == '$' ) {
			id2++;
		}
		if ( sscanf ( id2, "tp-%hu-%hu-%hu-%hu", &matchBus, &matchAddr, &matchVid,
					&matchPid ) != 4 ) {
			return NULL;
		}
	}

	if ( enumerate ( brand, NULL, matchBus, matchAddr, matchVid, matchPid,
				idx, &handle ) != 1 ) {
		return NULL;
	}

	// FIX ME -- lots of setup stuff to do here
	ctx->handle = handle;
	ctx->settings = settings;
	return ctx;
}
