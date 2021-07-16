/*****************************************************************************
 *
 * flags.h -- Flag values for Touptek-style SDK
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

#ifndef OA_TOUPTEK_FLAGS_H
#define OA_TOUPTEK_FLAGS_H

// Handle change of name of flags and options
#ifndef TOUPCAM_FLAG_TEC_ONOFF
#ifdef TOUPCAM_FLAG_COOLERONOFF
#define TOUPCAM_FLAG_TEC_ONOFF TOUPCAM_FLAG_COOLERONOFF
#endif
#endif

#ifndef TOUPCAM_OPTION_TEC
#ifdef TOUPCAM_OPTION_COOLER
#define TOUPCAM_OPTION_TEC TOUPCAM_OPTION_COOLER
#endif
#endif

#ifndef TOUPCAM_OPTION_RGB
#ifdef TOUPCAM_OPTION_RGB48
#define TOUPCAM_OPTION_RGB TOUPCAM_OPTION_RGB48
#endif
#endif

#endif	/* OA_TOUPTEK_FLAGS_H */
