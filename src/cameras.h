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

#include <touptek/defines.h>

#include "internals.h"

#define MAX_PRODUCT_IDS			4
#define	MAX_BRANDS					7
#define	MAX_CAMERAS					798
#define	MAX_FUNCTION_GROUPS	412

typedef struct cameraData {
	const uint16_t						productIds[ MAX_PRODUCT_IDS ];
	const uint8_t							matchOldAltair;
	const uint8_t							matchAltMeade;
	const unsigned long long	capabilities;
	const char*								name[ MAX_BRANDS ];
	const unsigned int				functionGroup;
} cameraData;

typedef struct cameraSettings {
	int								contrast;
	unsigned short		blackBalanceRed;
	unsigned short		blackBalanceGreen;
	unsigned short		blackBalanceBlue;
} cameraSettings;

typedef struct cameraCtx {
	cameraSettings*		settings;
} cameraCtx;

typedef struct cameraFuncs {
	HRESULT	( *abbOnce )();
	HRESULT	( *abbOnePush )();
	HRESULT	( *awbInit )();
	HRESULT	( *awbOnce )();
	HRESULT	( *awbOnePush )();
	HRESULT	( *dfcExport )();
	HRESULT	( *dfcImport )();
	HRESULT	( *dfcOnce )();
	HRESULT	( *dfcOnePush )();
	HRESULT	( *feedPipe )();
	HRESULT	( *ffcExport )();
	HRESULT	( *ffcImport )();
	HRESULT	( *ffcOnce )();
	HRESULT	( *ffcOnePush )();
	HRESULT	( *flush )();
	HRESULT	( *getABBAuxRect )();
	HRESULT	( *getAEAuxRect )();
	HRESULT	( *getAfParam )();
	HRESULT	( *getAutoExpoEnable )();
	HRESULT	( *getAutoExpoTarget )();
	HRESULT	( *getAWBAuxRect )();
	HRESULT	( *getBlackBalance )( const cameraCtx*, unsigned short bal[3]);
	HRESULT	( *getBrightness )();
	HRESULT	( *getChrome )();
	HRESULT	( *getContrast )( const cameraCtx*, int* );
	HRESULT	( *geteSize )();
	HRESULT	( *getExpoAGain )();
	HRESULT	( *getExpoAGainRange )();
	HRESULT	( *getExpoTime )();
	HRESULT	( *getExpTimeRange )();
	HRESULT	( *getFanMaxSpeed )();
	HRESULT	( *getField )();
	HRESULT	( *getFinalSize )();
	HRESULT	( *getFrameRate )();
	HRESULT	( *getGamma )();
	HRESULT	( *getHFlip )();
	HRESULT	( *getHistogram )();
	HRESULT	( *getHue )();
	HRESULT	( *getHZ )();
	HRESULT	( *getLevelRange )();
	HRESULT	( *getLevelRangeV2 )();
	HRESULT	( *getMaxAutoExpoTimeAGain )();
	HRESULT	( *getMaxBitDepth )();
	HRESULT	( *getMaxSpeed )();
	HRESULT	( *getMinAutoExpoTimeAGain )();
	HRESULT	( *getMode )();
	HRESULT	( *getMonoMode )();
	HRESULT	( *getNegative )();
	HRESULT	( *getOption )();
	HRESULT	( *getPixelSize )();
	HRESULT	( *getRawFormat )();
	HRESULT	( *getRealExpoTime )();
	HRESULT	( *getRealTime )();
	HRESULT	( *getResolution )();
	HRESULT	( *getResolutionNumber )();
	HRESULT	( *getResolutionRatio )();
	HRESULT	( *getRoi )();
	HRESULT	( *getRoiMode )();
	HRESULT	( *getSaturation )();
	HRESULT	( *getSize )();
	HRESULT	( *getSpeed )();
	HRESULT	( *getStillResolutionNumber )();
	HRESULT	( *getTemperature )();
	HRESULT	( *getTempTint )();
	HRESULT	( *getVFlip )();
	HRESULT	( *getVignetteAmountInt )();
	HRESULT	( *getVignetteEnable )();
	HRESULT	( *getVignetteMidPointInt )();
	HRESULT	( *getWhiteBalanceGain )();
	HRESULT	( *ioControl )();
	HRESULT	( *levelRangeAuto )();
	HRESULT	( *pause )();
	HRESULT	( *pullImageWithRowPitchV2 )();
	HRESULT	( *pullStillImageV2 )();
	HRESULT	( *pullStillImageWithRowPitchV2 )();
	HRESULT	( *putABBAuxRect )();
	HRESULT	( *putAEAuxRect )();
	HRESULT	( *putAutoExpoEnable )();
	HRESULT	( *putAutoExpoTarget )();
	HRESULT	( *putAWBAuxRect )();
	HRESULT	( *putBlackBalance )();
	HRESULT	( *putBrightness )();
	HRESULT	( *putChrome )();
	HRESULT	( *putChromeCallback )();
	HRESULT	( *putColorMatrix )();
	HRESULT	( *putContrast )();
	HRESULT	( *putCurve )();
	HRESULT	( *puteSize )();
	HRESULT	( *putExpoAGain )();
	HRESULT	( *putExpoCallback )();
	HRESULT	( *putExpoTime )();
	HRESULT	( *putGamma )();
	HRESULT	( *putHFlip )();
	HRESULT	( *putHue )();
	HRESULT	( *putHZ )();
	HRESULT	( *putInitWBGain )();
	HRESULT	( *putLEDState )();
	HRESULT	( *putLevelRange )();
	HRESULT	( *putLevelRangeV2 )();
	HRESULT	( *putLinear )();
	HRESULT	( *putMaxAutoExpoTimeAGain )();
	HRESULT	( *putMinAutoExpoTimeAGain )();
	HRESULT	( *putMode )();
	HRESULT	( *putNegative )();
	HRESULT	( *putOption )();
	HRESULT	( *putRealTime )();
	HRESULT	( *putRoi )();
	HRESULT	( *putRoiMode )();
	HRESULT	( *putSaturation )();
	HRESULT	( *putSize )();
	HRESULT	( *putSpeed )();
	HRESULT	( *putTemperature )();
	HRESULT	( *putTempTint )();
	HRESULT	( *putVFlip )();
	HRESULT	( *putVignetteAmountInt )();
	HRESULT	( *putVignetteEnable )();
	HRESULT	( *putVignetteMidPointInt )();
	HRESULT	( *putWhiteBalanceGain )();
	HRESULT	( *readEEPROM )();
	HRESULT	( *readPipe )();
	HRESULT	( *readUART )();
	HRESULT	( *snap )();
	HRESULT	( *snapN )();
	HRESULT	( *ST4PulseGuide )();
	HRESULT	( *trigger )();
	HRESULT	( *writeEEPROM )();
	HRESULT	( *writePipe )();
	HRESULT	( *writeUART )();
} cameraFuncs;

extern cameraData		cameras[ MAX_CAMERAS ];
extern cameraFuncs	functionGroups[ MAX_FUNCTION_GROUPS ];

#endif	/* CAMERAS_H */
