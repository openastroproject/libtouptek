/*****************************************************************************
 *
 * connection.c -- Handle setting up/tearing down connections to cameras
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
#include <string.h>
#include <libusb-1.0/libusb.h>

#include <toupcam.h>

#include "internals.h"


void*
oaTouptek_Open ( uint8_t brand, const char* id )
{
	unsigned								result;
	libusb_device_handle*		handle;
	unsigned short					bus, addr, vid, pid;

	if ( id == NULL ) {
		result = enumerate ( brand, NULL, 0, 0, 0, &handle );
	} else {
		if ( sscanf ( id, "tp-%hu-%hu-%hu-%hu", &bus, &addr, &vid, &pid ) != 4 ) {
			result = 0;
		} else {
			result = enumerate ( brand, NULL, bus, addr, 0, &handle );
		}
	}

	if ( result ) {
		return ( void* ) handle;
	}

	return ( void* ) NULL;
}


void*
oaTouptek_OpenByIndex ( uint8_t brand, unsigned int index )
{
	unsigned								result;
	libusb_device_handle*		handle;

	result = enumerate ( brand, NULL, 0, 0, index, &handle );

	if ( result ) {
		return ( void* ) handle;
	}

	return ( void* ) NULL;
}
