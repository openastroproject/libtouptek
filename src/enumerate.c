/*****************************************************************************
 *
 * enumerate.c -- List cameras that are connected to the system
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

#include <touptek/defines.h>
#include <touptek/types.h>

#include "cameras.h"
#include "internals.h"


/**
 * Cycle through the sys filesystem looking for USBdevices with one
 * of the appropriate vendor ID and product ID pairs
 */

unsigned
oaTouptek_EnumV2 (
		uint8_t brand, oaTouptekDeviceV2 deviceList[ OA_TOUPTEK_MAX ])
{
	return enumerate ( brand, deviceList, 0, 0, 0, 0, -1, NULL );
}


unsigned
enumerate ( uint8_t brand, oaTouptekDeviceV2 deviceList[ OA_TOUPTEK_MAX ],
		unsigned short matchBus, unsigned short matchAddr,
		unsigned short matchVid, unsigned short matchPid, int index,
		libusb_device_handle** pHandle )
{
  libusb_context*									ctx = 0;
  libusb_device**									devlist;
  libusb_device*									device;
  struct libusb_device_descriptor	desc;
  unsigned int										numUSBDevices;
	unsigned int										i, j, k, stop;
  unsigned int										numFound = 0;
  unsigned int										returnHandle = 0;
  int															nameToUse;
  unsigned short									busNum, addr;

	/*
	oaLogInfo ( OA_LOG_CAMERA, "%s ( %p, %ld, %d ): entered", __func__,
			deviceList, featureFlags, flags );
	*/

  libusb_init ( &ctx );
  // libusb_set_debug ( ctx, LIBUSB_LOG_LEVEL_DEBUG );
  numUSBDevices = libusb_get_device_list ( ctx, &devlist );
  if ( numUSBDevices < 1 ) {
		/*
		oaLogError ( OA_LOG_CAMERA, "%s: libusb_get_device_list() returns %d",
				__func__, numUSBDevices );
		*/
    libusb_free_device_list ( devlist, 1 );
    libusb_exit ( ctx );
    return 0;
  }

  for ( i = 0; i < numUSBDevices && numFound < OA_TOUPTEK_MAX && !returnHandle;
			i++ ) {
    device = devlist[i];
    if ( LIBUSB_SUCCESS != libusb_get_device_descriptor ( device, &desc )) {
      libusb_free_device_list ( devlist, 1 );
      libusb_exit ( ctx );
			/*
			oaLogError ( OA_LOG_CAMERA, "%s: libusb_get_device_descriptor() failed",
				__func__ );
			*/
      return 0;
    }

		stop = 0;
		// Skip any vendor IDs we know we're not going to care about
		if ( desc.idVendor == VID_TOUPTEK || desc.idVendor == VID_OLD_ALTAIR ||
				desc.idVendor == VID_ALT_MEADE ) {
			if (( matchVid == 0 || matchVid == desc.idVendor ) &&
					( matchPid == 0 || matchPid == desc.idProduct )) {
				// Now check against all the cameras we know about
				for ( j = 0; j < MAX_CAMERAS && !stop; j++ ) {
					if ( desc.idVendor == VID_TOUPTEK ||
							( brand == OA_BRAND_ALTAIRCAM && cameras[j].matchOldAltair &&
									desc.idVendor == VID_OLD_ALTAIR ) ||
							( brand == OA_BRAND_MEADECAM && cameras[j].matchAltMeade &&
									desc.idVendor == VID_ALT_MEADE )) {
						// Vendor ID is of interest, now check the product ids
						for ( k = 0; k < MAX_PRODUCT_IDS && cameras[j].productIds[k] &&
								!stop; k++ ) {
							if ( desc.idProduct == cameras[j].productIds[k] ) {
								// If the product Id matches then we're not going to check
								// anything else
								stop = 1;
								// But there's not a definite match unless the camera name for
								// the current brand or for OA_BRAND_TOUPCAM exists
								nameToUse = -1;
								if ( cameras[j].name[ brand ] ) {
									nameToUse = brand;
								} else {
									if ( cameras[j].name[ OA_BRAND_TOUPCAM ]) {
										nameToUse = OA_BRAND_TOUPCAM;
									}
								}
								if ( nameToUse >= 0 ) {
									// At this point we've definitely got something
									busNum = libusb_get_bus_number ( device );
									addr = libusb_get_device_address ( device );
									if ( deviceList ) {
										( void ) strncpy ( deviceList[ numFound ].displayname,
												cameras[j].name[ nameToUse ], OA_STRING_MAX );
										// Format is "tp-<usb-bus-id>-<usb-device-id>-<vid>-<pid>"
										// all numbers are in decimal
										( void ) snprintf ( deviceList[ numFound ].id,
												OA_STRING_MAX, "tp-%hu-%hu-%hu-%hu", busNum, addr,
												desc.idVendor, desc.idProduct );
									}
									if ( matchBus && matchAddr ) {
										if ( busNum == matchBus && addr == matchAddr ) {
											returnHandle = 1;
										}
									}
									if ( index >= 0 && index == numFound ) {
										returnHandle = 1;
									}
									if ( returnHandle ) {
										// FIX ME -- go on then, make a handle!
									}
									numFound++;
								}
							}
						}
					}
				}
			}
		}
  }

  libusb_free_device_list ( devlist, 1 );
	if ( !returnHandle ) {
		libusb_exit ( ctx );
	}

	/*
	oaLogInfo ( OA_LOG_CAMERA, "%s: exiting.  Found %d cameras", __func__,
			numFound );
	*/

  return numFound;
}
