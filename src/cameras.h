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

typedef struct cameraFuncs {
	int												( *abbOnce )();
	int												( *abbOnePush )();
	int												( *awbInit )();
	int												( *awbOnce )();
	int												( *awbOnePush )();
	int												( *dfcExport )();
	int												( *dfcImport )();
	int												( *dfcOnce )();
	int												( *dfcOnePush )();
	int												( *feedPipe )();
	int												( *ffcExport )();
	int												( *ffcImport )();
	int												( *ffcOnce )();
	int												( *ffcOnePush )();
	int												( *flush )();
	int												( *getABBAuxRect )();
	int												( *getAEAuxRect )();
	int												( *getAfParam )();
	int												( *getAutoExpoEnable )();
	int												( *getAutoExpoTarget )();
	int												( *getAWBAuxRect )();
	int												( *getBlackBalance )();
	int												( *getBrightness )();
	int												( *getChrome )();
	int												( *getContrast )();
	int												( *geteSize )();
	int												( *getExpoAGain )();
	int												( *getExpoAGainRange )();
	int												( *getExpoTime )();
	int												( *getExpTimeRange )();
	int												( *getFanMaxSpeed )();
	int												( *getField )();
	int												( *getFinalSize )();
	int												( *getFrameRate )();
	int												( *getGamma )();
	int												( *getHFlip )();
	int												( *getHistogram )();
	int												( *getHue )();
	int												( *getHZ )();
	int												( *getLevelRange )();
	int												( *getLevelRangeV2 )();
	int												( *getMaxAutoExpoTimeAGain )();
	int												( *getMaxBitDepth )();
	int												( *getMaxSpeed )();
	int												( *getMinAutoExpoTimeAGain )();
	int												( *getMode )();
	int												( *getMonoMode )();
	int												( *getNegative )();
	int												( *getOption )();
	int												( *getPixelSize )();
	int												( *getRawFormat )();
	int												( *getRealExpoTime )();
	int												( *getRealTime )();
	int												( *getResolution )();
	int												( *getResolutionNumber )();
	int												( *getResolutionRatio )();
	int												( *getRoi )();
	int												( *getRoiMode )();
	int												( *getSaturation )();
	int												( *getSize )();
	int												( *getSpeed )();
	int												( *getStillResolutionNumber )();
	int												( *getTemperature )();
	int												( *getTempTint )();
	int												( *getVFlip )();
	int												( *getVignetteAmountInt )();
	int												( *getVignetteEnable )();
	int												( *getVignetteMidPointInt )();
	int												( *getWhiteBalanceGain )();
	int												( *ioControl )();
	int												( *levelRangeAuto )();
	int												( *pause )();
	int												( *pullImageWithRowPitchV2 )();
	int												( *pullStillImageV2 )();
	int												( *pullStillImageWithRowPitchV2 )();
	int												( *putABBAuxRect )();
	int												( *putAEAuxRect )();
	int												( *putAutoExpoEnable )();
	int												( *putAutoExpoTarget )();
	int												( *putAWBAuxRect )();
	int												( *putBlackBalance )();
	int												( *putBrightness )();
	int												( *putChrome )();
	int												( *putChromeCallback )();
	int												( *putColorMatrix )();
	int												( *putContrast )();
	int												( *putCurve )();
	int												( *puteSize )();
	int												( *putExpoAGain )();
	int												( *putExpoCallback )();
	int												( *putExpoTime )();
	int												( *putGamma )();
	int												( *putHFlip )();
	int												( *putHue )();
	int												( *putHZ )();
	int												( *putInitWBGain )();
	int												( *putLEDState )();
	int												( *putLevelRange )();
	int												( *putLevelRangeV2 )();
	int												( *putLinear )();
	int												( *putMaxAutoExpoTimeAGain )();
	int												( *putMinAutoExpoTimeAGain )();
	int												( *putMode )();
	int												( *putNegative )();
	int												( *putOption )();
	int												( *putRealTime )();
	int												( *putRoi )();
	int												( *putRoiMode )();
	int												( *putSaturation )();
	int												( *putSize )();
	int												( *putSpeed )();
	int												( *putTemperature )();
	int												( *putTempTint )();
	int												( *putVFlip )();
	int												( *putVignetteAmountInt )();
	int												( *putVignetteEnable )();
	int												( *putVignetteMidPointInt )();
	int												( *putWhiteBalanceGain )();
	int												( *readEEPROM )();
	int												( *readPipe )();
	int												( *readUART )();
	int												( *snap )();
	int												( *snapN )();
	int												( *ST4PulseGuide )();
	int												( *trigger )();
	int												( *writeEEPROM )();
	int												( *writePipe )();
	int												( *writeUART )();
} cameraFuncs;

extern cameraData		cameras[ MAX_CAMERAS ];
extern cameraFuncs	functionGroups[ MAX_FUNCTION_GROUPS ];

#endif	/* CAMERAS_H */
