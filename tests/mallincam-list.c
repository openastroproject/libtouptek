/*****************************************************************************
 *
 * mallincam-list.c -- List connected Mallincam cameras
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

#include <mallincam.h>

int main()
{
  ToupcamDeviceV2			devList[ MALLINCAM_MAX ];
  unsigned int				numCameras;
  unsigned int				i;

  numCameras = Mallincam_EnumV2 ( devList );
  if ( numCameras < 1 ) {
		fprintf ( stderr, "No Mallincam cameras found\n" );
    return 0;
  }

  for ( i = 0; i < numCameras; i++ ) {
		printf ( "camera %d: %s, id '%s'\n", i + 1, devList[i].displayname,
				devList[i].id );
	}

  return 0;
}
