/**
 *
 * Spi.h is part of the FIGnition firmware.
 *
 * The FIGnition firmware is the built-in software for the
 * FIGnition DIY 8-bit computer and compatible computers.
 *
 * Copyright (C) 2011  Julian Skidmore.
 *
 * The FIGnition firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Version. Date (DD/MM/YYY)
 * ************************
 *
 * 1.0.0.  
 *
 * Contact
 * *******
 * TheOriginalSnial@Gmail.com
 *
 *
 * Introduction:
 * *************
 *
 */

#ifndef _SPI_H
#define _SPI_H

#include "CoreDefs.h"

//#define __TESTSPIDEBUG__
//#define __TESTRNDGEN__

#ifdef __TESTRNDGEN__

extern ushort gSeed;
extern ushort Rnd(ushort max);

#endif

#ifdef __TESTSPIDEBUG__

extern void _SpiDebug(byte data);

#else

#define _SpiDebug(data)

#endif

#define kSpiMosiBit 3
#define kSpiMosi (1<<kSpiMosiBit)
#define kSpiSck (1<<5)
#define kSpiMisoBit 4
#define kSpiMiso (1<<kSpiMisoBit)
#define kSpiCsSram (1<<1)
#define kSpiCsFlash (1<<2)

#define __AUTOSPI__

//byte gSpiResVal;


extern void SpiMasterInit(void);

//#define __TESTSPIREADY__

extern void SpiMasterTransmit(byte cData);

extern byte SpiMasterAutoReadByte(void);

#ifdef __AUTOSPI__

#define SpiMasterReadByte() SpiMasterAutoReadByte()

#else

#define SpiMasterReadByte() SpiMasterTransmit(0)

#endif

//#define __TestSpiSignals__

#ifdef __TestSpiSignals__

extern void DelayTick(byte sec);

extern void DelaySec(byte sec);

extern void TestSpiSignals(void);

#else

#define TestSpiSignals()

#endif

#endif
