/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/sis/init301.h,v 1.42 2004/01/27 11:58:27 twini Exp $ */
/*
 * Data and prototypes for init301.c
 *
 * Copyright (C) 2001-2004 by Thomas Winischhofer, Vienna, Austria
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License as published by
 * * the Free Software Foundation; either version 2 of the named License,
 * * or any later version.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) All advertising materials mentioning features or use of this software
 * *    must display the following acknowledgement: "This product includes
 * *    software developed by Thomas Winischhofer, Vienna, Austria."
 * * 4) The name of the author may not be used to endorse or promote products
 * *    derived from this software without specific prior written permission.
 * *
 * * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESSED OR
 * * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: 	Thomas Winischhofer <thomas@winischhofer.net>
 *
 */

#ifndef  _INIT301_
#define  _INIT301_

#include "osdef.h"

#include "initdef.h"
#include "vgatypes.h"
#include "vstruct.h"

#ifdef LINUX_XF86
#include "xf86.h"
#include "xf86Pci.h"
#include "xf86PciInfo.h"
#include "sis.h"
#include "sis_regs.h"
#endif

#ifdef LINUX_KERNEL
#ifdef SIS_CP
#undef SIS_CP
#endif
#include <linux/config.h>
#include <linux/version.h>
#include <asm/io.h>
#include <linux/types.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,0)
#include <linux/sisfb.h>
#else
#include <video/sisfb.h>
#endif
#endif

const UCHAR SiS_YPbPrTable[3][64] = {
  {
    0x17,0x1d,0x03,0x09,0x05,0x06,0x0c,0x0c,
    0x94,0x49,0x01,0x0a,0x06,0x0d,0x04,0x0a,
    0x06,0x14,0x0d,0x04,0x0a,0x00,0x85,0x1b,
    0x0c,0x50,0x00,0x97,0x00,0xda,0x4a,0x17,
    0x7d,0x05,0x4b,0x00,0x00,0xe2,0x00,0x02,
    0x03,0x0a,0x65,0x9d,0x08,0x92,0x8f,0x40,
    0x60,0x80,0x14,0x90,0x8c,0x60,0x14,0x53,
    0x00,0x40,0x44,0x00,0xdb,0x02,0x3b,0x00
  },
  {
    0x1d,0x11,0x06,0x09,0x0b,0x0c,0x0c,0x0c,
    0x98,0x0a,0x01,0x0d,0x06,0x0d,0x04,0x0a,
    0x06,0x14,0x0d,0x04,0x0a,0x00,0x85,0x3f,
    0x0c,0x50,0xb2,0x9f,0x16,0x59,0x4f,0x13,
    0xad,0x11,0xad,0x1d,0x40,0x8a,0x3d,0xb8,
    0x51,0x5e,0x60,0x49,0x7d,0x92,0x0f,0x40,
    0x60,0x80,0x14,0x90,0x8c,0x60,0x14,0x4b,
    0x43,0x41,0x11,0x00,0xfc,0xff,0x32,0x00
  },
  {
    0x13,0x1d,0xe8,0x09,0x09,0xed,0x0c,0x0c,
    0x98,0x0a,0x01,0x0c,0x06,0x0d,0x04,0x0a,
    0x06,0x14,0x0d,0x04,0x0a,0x00,0x85,0x3f,
    0xed,0x50,0x70,0x9f,0x16,0x59,0x2b,0x13,
    0x27,0x0b,0x27,0xfc,0x30,0x27,0x1c,0xb0,
    0x4b,0x4b,0x6f,0x2f,0x63,0x92,0x0f,0x40,
    0x60,0x80,0x14,0x90,0x8c,0x60,0x14,0x27,
    0x00,0x40,0x11,0x00,0xfc,0xff,0x32,0x00
  }
};

const UCHAR SiS_HiTVGroup3_1[] = {
    0x00, 0x14, 0x15, 0x25, 0x55, 0x15, 0x0b, 0x13,
    0xb1, 0x41, 0x62, 0x62, 0xff, 0xf4, 0x45, 0xa6,
    0x25, 0x2f, 0x67, 0xf6, 0xbf, 0xff, 0x8e, 0x20,
    0xac, 0xda, 0x60, 0xfe, 0x6a, 0x9a, 0x06, 0x10,
    0xd1, 0x04, 0x18, 0x0a, 0xff, 0x80, 0x00, 0x80,
    0x3b, 0x77, 0x00, 0xef, 0xe0, 0x10, 0xb0, 0xe0,
    0x10, 0x4f, 0x0f, 0x0f, 0x05, 0x0f, 0x08, 0x6e,
    0x1a, 0x1f, 0x25, 0x2a, 0x4c, 0xaa, 0x01
};

const UCHAR SiS_HiTVGroup3_2[] = {
    0x00, 0x14, 0x15, 0x25, 0x55, 0x15, 0x0b, 0x7a,
    0x54, 0x41, 0xe7, 0xe7, 0xff, 0xf4, 0x45, 0xa6,
    0x25, 0x2f, 0x67, 0xf6, 0xbf, 0xff, 0x8e, 0x20,
    0xac, 0x6a, 0x60, 0x2b, 0x52, 0xcd, 0x61, 0x10,
    0x51, 0x04, 0x18, 0x0a, 0x1f, 0x80, 0x00, 0x80,
    0xff, 0xa4, 0x04, 0x2b, 0x94, 0x21, 0x72, 0x94,
    0x26, 0x05, 0x01, 0x0f, 0xed, 0x0f, 0x0a, 0x64,
    0x18, 0x1d, 0x23, 0x28, 0x4c, 0xaa, 0x01
};

/* 301C / 302ELV (?) extended Part2 TV registers */

static const UCHAR SiS_Part2CLVX_1[] = {
    0x00,0x00,
    0x00,0x20,0x00,0x00,0x7F,0x20,0x02,0x7F,0x7D,0x20,0x04,0x7F,0x7D,0x1F,0x06,0x7E,
    0x7C,0x1D,0x09,0x7E,0x7C,0x1B,0x0B,0x7E,0x7C,0x19,0x0E,0x7D,0x7C,0x17,0x11,0x7C,
    0x7C,0x14,0x14,0x7C,0x7C,0x11,0x17,0x7C,0x7D,0x0E,0x19,0x7C,0x7E,0x0B,0x1B,0x7C,
    0x7E,0x09,0x1D,0x7C,0x7F,0x06,0x1F,0x7C,0x7F,0x04,0x20,0x7D,0x00,0x02,0x20,0x7E
};

static const UCHAR SiS_Part2CLVX_2[] = {
    0x00,0x00,
    0x00,0x20,0x00,0x00,0x7F,0x20,0x02,0x7F,0x7D,0x20,0x04,0x7F,0x7D,0x1F,0x06,0x7E,
    0x7C,0x1D,0x09,0x7E,0x7C,0x1B,0x0B,0x7E,0x7C,0x19,0x0E,0x7D,0x7C,0x17,0x11,0x7C,
    0x7C,0x14,0x14,0x7C,0x7C,0x11,0x17,0x7C,0x7D,0x0E,0x19,0x7C,0x7E,0x0B,0x1B,0x7C,
    0x7E,0x09,0x1D,0x7C,0x7F,0x06,0x1F,0x7C,0x7F,0x04,0x20,0x7D,0x00,0x02,0x20,0x7E
};

static const UCHAR SiS_Part2CLVX_3[] = {  /* NTSC, 525i, 525p */
    0xE0,0x01,
    0x04,0x1A,0x04,0x7E,0x03,0x1A,0x06,0x7D,0x01,0x1A,0x08,0x7D,0x00,0x19,0x0A,0x7D,
    0x7F,0x19,0x0C,0x7C,0x7E,0x18,0x0E,0x7C,0x7E,0x17,0x10,0x7B,0x7D,0x15,0x12,0x7C,
    0x7D,0x13,0x13,0x7D,0x7C,0x12,0x15,0x7D,0x7C,0x10,0x17,0x7D,0x7C,0x0E,0x18,0x7E,
    0x7D,0x0C,0x19,0x7E,0x7D,0x0A,0x19,0x00,0x7D,0x08,0x1A,0x01,0x7E,0x06,0x1A,0x02,
    0x58,0x02,
    0x07,0x14,0x07,0x7E,0x06,0x14,0x09,0x7D,0x05,0x14,0x0A,0x7D,0x04,0x13,0x0B,0x7E,
    0x03,0x13,0x0C,0x7E,0x02,0x12,0x0D,0x7F,0x01,0x12,0x0E,0x7F,0x01,0x11,0x0F,0x7F,
    0x00,0x10,0x10,0x00,0x7F,0x0F,0x11,0x01,0x7F,0x0E,0x12,0x01,0x7E,0x0D,0x12,0x03,
    0x7E,0x0C,0x13,0x03,0x7E,0x0B,0x13,0x04,0x7E,0x0A,0x14,0x04,0x7D,0x09,0x14,0x06,
    0x00,0x03,
    0x09,0x0F,0x09,0x7F,0x08,0x0F,0x09,0x00,0x07,0x0F,0x0A,0x00,0x06,0x0F,0x0A,0x01,
    0x06,0x0E,0x0B,0x01,0x05,0x0E,0x0B,0x02,0x04,0x0E,0x0C,0x02,0x04,0x0D,0x0C,0x03,
    0x03,0x0D,0x0D,0x03,0x02,0x0C,0x0D,0x05,0x02,0x0C,0x0E,0x04,0x01,0x0B,0x0E,0x06,
    0x01,0x0B,0x0E,0x06,0x00,0x0A,0x0F,0x07,0x00,0x0A,0x0F,0x07,0x00,0x09,0x0F,0x08,
    0xFF,0xFF
};

static const UCHAR SiS_Part2CLVX_4[] = {   /* PAL */
    0x58,0x02,
    0x05,0x19,0x05,0x7D,0x03,0x19,0x06,0x7E,0x02,0x19,0x08,0x7D,0x01,0x18,0x0A,0x7D,
    0x00,0x18,0x0C,0x7C,0x7F,0x17,0x0E,0x7C,0x7E,0x16,0x0F,0x7D,0x7E,0x14,0x11,0x7D,
    0x7D,0x13,0x13,0x7D,0x7D,0x11,0x14,0x7E,0x7D,0x0F,0x16,0x7E,0x7D,0x0E,0x17,0x7E,
    0x7D,0x0C,0x18,0x7F,0x7D,0x0A,0x18,0x01,0x7D,0x08,0x19,0x02,0x7D,0x06,0x19,0x04,
    0x00,0x03,
    0x08,0x12,0x08,0x7E,0x07,0x12,0x09,0x7E,0x06,0x12,0x0A,0x7E,0x05,0x11,0x0B,0x7F,
    0x04,0x11,0x0C,0x7F,0x03,0x11,0x0C,0x00,0x03,0x10,0x0D,0x00,0x02,0x0F,0x0E,0x01,
    0x01,0x0F,0x0F,0x01,0x01,0x0E,0x0F,0x02,0x00,0x0D,0x10,0x03,0x7F,0x0C,0x11,0x04,
    0x7F,0x0C,0x11,0x04,0x7F,0x0B,0x11,0x05,0x7E,0x0A,0x12,0x06,0x7E,0x09,0x12,0x07,
    0x40,0x02,
    0x04,0x1A,0x04,0x7E,0x02,0x1B,0x05,0x7E,0x01,0x1A,0x07,0x7E,0x00,0x1A,0x09,0x7D,
    0x7F,0x19,0x0B,0x7D,0x7E,0x18,0x0D,0x7D,0x7D,0x17,0x10,0x7C,0x7D,0x15,0x12,0x7C,
    0x7C,0x14,0x14,0x7C,0x7C,0x12,0x15,0x7D,0x7C,0x10,0x17,0x7D,0x7C,0x0D,0x18,0x7F,
    0x7D,0x0B,0x19,0x7F,0x7D,0x09,0x1A,0x00,0x7D,0x07,0x1A,0x02,0x7E,0x05,0x1B,0x02,
    0xFF,0xFF
};

static const UCHAR SiS_Part2CLVX_5[] = {   /* 750p */
    0x00,0x03,
    0x05,0x19,0x05,0x7D,0x03,0x19,0x06,0x7E,0x02,0x19,0x08,0x7D,0x01,0x18,0x0A,0x7D,
    0x00,0x18,0x0C,0x7C,0x7F,0x17,0x0E,0x7C,0x7E,0x16,0x0F,0x7D,0x7E,0x14,0x11,0x7D,
    0x7D,0x13,0x13,0x7D,0x7D,0x11,0x14,0x7E,0x7D,0x0F,0x16,0x7E,0x7D,0x0E,0x17,0x7E,
    0x7D,0x0C,0x18,0x7F,0x7D,0x0A,0x18,0x01,0x7D,0x08,0x19,0x02,0x7D,0x06,0x19,0x04,
    0xFF,0xFF
};

static const UCHAR SiS_Part2CLVX_6[] = {   /* 1080i */
    0x00,0x04,
    0x04,0x1A,0x04,0x7E,0x02,0x1B,0x05,0x7E,0x01,0x1A,0x07,0x7E,0x00,0x1A,0x09,0x7D,
    0x7F,0x19,0x0B,0x7D,0x7E,0x18,0x0D,0x7D,0x7D,0x17,0x10,0x7C,0x7D,0x15,0x12,0x7C,
    0x7C,0x14,0x14,0x7C,0x7C,0x12,0x15,0x7D,0x7C,0x10,0x17,0x1D /* 0x7D? */ ,0x7C,0x0D,0x18,0x7F,
    0x7D,0x0B,0x19,0x7F,0x7D,0x09,0x1A,0x00,0x7D,0x07,0x1A,0x02,0x7E,0x05,0x1B,0x02,
    0xFF,0xFF,
};


#ifdef SIS315H
/* 661 et al LCD data structure */
static const UCHAR SiS_LCDStruct661[] = {
    /* 1600x1200 */
    0x0B,0xEA,0x81,0x10,0x00,0xC0,0x03,0x21,0x5A,0x23,0x5A,0x23,0x02,
    0x14,0x0A,0x02,0x00,0x30,0x10,0x5A,0x10,0x10,0x0A,0xC0,0x30,0x10,
    /* 1400x1050 */
    0x09,0xEA,0x81,0x80,0xA3,0x70,0x03,0x19,0xD2,0x2A,0xF8,0x2F,0x02,
    0x14,0x0A,0x02,0x00,0x30,0x10,0x5A,0x10,0x10,0x0A,0xC0,0x30,0x10,
    /* 1280x1024 */
    0x03,0xEA,0x81,0x40,0xA1,0x70,0x03,0x19,0xD2,0x2A,0xF8,0x2F,0x02,
    0x14,0x0A,0x02,0x00,0x30,0x10,0x5A,0x10,0x10,0x0A,0xC0,0x30,0x10,
    /* 1024x768 */
    0x02,0xEA,0x80,0x00,0x11,0x88,0x06,0x0B,0xF5,0x6C,0x35,0x62,0x02,
    0x14,0x0A,0x02,0x00,0x30,0x10,0x5A,0x10,0x10,0x0A,0xC0,0x28,0x10,
    0xFF,
};
#endif

void	SiS_UnLockCRT2(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void	SiS_LockCRT2(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void	SiS_EnableCRT2(SiS_Private *SiS_Pr);
USHORT	SiS_GetRatePtr(SiS_Private *SiS_Pr, USHORT ModeNo, USHORT ModeIdIndex, PSIS_HW_INFO HwInfo);
void	SiS_WaitRetrace1(SiS_Private *SiS_Pr);
BOOLEAN	SiS_IsDualEdge(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
BOOLEAN	SiS_IsVAMode(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void	SiS_SetChrontelGPIO(SiS_Private *SiS_Pr, USHORT myvbinfo);
void	SiS_GetVBInfo(SiS_Private *SiS_Pr, USHORT ModeNo,
              USHORT ModeIdIndex,PSIS_HW_INFO HwInfo,
	      int checkcrt2mode);
void	SiS_SetYPbPr(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void    SiS_SetTVMode(SiS_Private *SiS_Pr, USHORT ModeNo, USHORT ModeIdIndex, PSIS_HW_INFO HwInfo);
void	SiS_GetLCDResInfo(SiS_Private *SiS_Pr, USHORT ModeNo, USHORT ModeIdIndex, PSIS_HW_INFO HwInfo);
USHORT	SiS_GetVCLK2Ptr(SiS_Private *SiS_Pr, USHORT ModeNo, USHORT ModeIdIndex,
                USHORT RefreshRateTableIndex, PSIS_HW_INFO HwInfo);
USHORT	SiS_GetResInfo(SiS_Private *SiS_Pr,USHORT ModeNo,USHORT ModeIdIndex);
void	SiS_DisableBridge(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void	SiS_EnableBridge(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
BOOLEAN	SiS_SetCRT2Group(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo, USHORT ModeNo);
void	SiS_SiS30xBLOn(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void	SiS_SiS30xBLOff(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);

void   	SiS_SetCH700x(SiS_Private *SiS_Pr, USHORT tempax);
USHORT 	SiS_GetCH700x(SiS_Private *SiS_Pr, USHORT tempax);
void   	SiS_SetCH701x(SiS_Private *SiS_Pr, USHORT tempax);
USHORT 	SiS_GetCH701x(SiS_Private *SiS_Pr, USHORT tempax);
void   	SiS_SetCH70xx(SiS_Private *SiS_Pr, USHORT tempax);
USHORT 	SiS_GetCH70xx(SiS_Private *SiS_Pr, USHORT tempax);
void   	SiS_SetCH70xxANDOR(SiS_Private *SiS_Pr, USHORT tempax,USHORT tempbh);
#ifdef SIS315H
void   	SiS_Chrontel701xOn(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void   	SiS_Chrontel701xOff(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void   	SiS_ChrontelInitTVVSync(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void   	SiS_ChrontelDoSomething1(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void   	SiS_Chrontel701xBLOn(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo);
void   	SiS_Chrontel701xBLOff(SiS_Private *SiS_Pr);
#endif /* 315 */

USHORT   SiS_ReadDDC1Bit(SiS_Private *SiS_Pr);
void     SiS_SetSwitchDDC2(SiS_Private *SiS_Pr);
USHORT   SiS_SetStart(SiS_Private *SiS_Pr);
USHORT   SiS_SetStop(SiS_Private *SiS_Pr);
void     SiS_DDC2Delay(SiS_Private *SiS_Pr, USHORT delaytime);
USHORT   SiS_SetSCLKLow(SiS_Private *SiS_Pr);
USHORT   SiS_SetSCLKHigh(SiS_Private *SiS_Pr);
USHORT   SiS_ReadDDC2Data(SiS_Private *SiS_Pr, USHORT tempax);
USHORT   SiS_WriteDDC2Data(SiS_Private *SiS_Pr, USHORT tempax);
USHORT   SiS_CheckACK(SiS_Private *SiS_Pr);

USHORT   SiS_InitDDCRegs(SiS_Private *SiS_Pr, unsigned long VBFlags, int VGAEngine,
                         USHORT adaptnum, USHORT DDCdatatype, BOOLEAN checkcr32);
USHORT   SiS_WriteDABDDC(SiS_Private *SiS_Pr);
USHORT   SiS_PrepareReadDDC(SiS_Private *SiS_Pr);
USHORT   SiS_PrepareDDC(SiS_Private *SiS_Pr);
void     SiS_SendACK(SiS_Private *SiS_Pr, USHORT yesno);
USHORT   SiS_DoProbeDDC(SiS_Private *SiS_Pr);
USHORT   SiS_ProbeDDC(SiS_Private *SiS_Pr);
USHORT   SiS_ReadDDC(SiS_Private *SiS_Pr, USHORT DDCdatatype, unsigned char *buffer);
USHORT   SiS_HandleDDC(SiS_Private *SiS_Pr, unsigned long VBFlags, int VGAEngine,
		       USHORT adaptnum, USHORT DDCdatatype, unsigned char *buffer);
#ifdef LINUX_XF86
USHORT   SiS_SenseLCDDDC(SiS_Private *SiS_Pr, SISPtr pSiS);
USHORT   SiS_SenseVGA2DDC(SiS_Private *SiS_Pr, SISPtr pSiS);
#endif

#ifdef SIS315H
void     SiS_OEM310Setting(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo,
                           USHORT ModeNo,USHORT ModeIdIndex);
void     SiS_OEM661Setting(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo,
                           USHORT ModeNo,USHORT ModeIdIndex, USHORT RRTI);
void     SiS_FinalizeLCD(SiS_Private *, USHORT, USHORT, PSIS_HW_INFO);
#endif
#ifdef SIS300
void     SiS_OEM300Setting(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo,
                           USHORT ModeNo, USHORT ModeIdIndex, USHORT RefTabindex);
void     SetOEMLCDData2(SiS_Private *SiS_Pr, PSIS_HW_INFO HwInfo,
			USHORT ModeNo, USHORT ModeIdIndex,USHORT RefTableIndex);
#endif

extern void     SiS_SetReg(SISIOADDRESS, USHORT, USHORT);
extern void     SiS_SetRegByte(SISIOADDRESS, USHORT);
extern void     SiS_SetRegShort(SISIOADDRESS, USHORT);
extern void     SiS_SetRegLong(SISIOADDRESS, ULONG);
extern UCHAR    SiS_GetReg(SISIOADDRESS, USHORT);
extern UCHAR    SiS_GetRegByte(SISIOADDRESS);
extern USHORT   SiS_GetRegShort(SISIOADDRESS);
extern ULONG    SiS_GetRegLong(SISIOADDRESS);
extern void     SiS_SetRegANDOR(SISIOADDRESS Port,USHORT Index,USHORT DataAND,USHORT DataOR);
extern void     SiS_SetRegOR(SISIOADDRESS Port,USHORT Index,USHORT DataOR);
extern void     SiS_SetRegAND(SISIOADDRESS Port,USHORT Index,USHORT DataAND);

extern void     SiS_DisplayOff(SiS_Private *SiS_Pr);
extern void     SiS_DisplayOn(SiS_Private *SiS_Pr);

extern BOOLEAN  SiS_SearchModeID(SiS_Private *, USHORT *, USHORT *);
extern UCHAR    SiS_GetModePtr(SiS_Private *SiS_Pr, USHORT ModeNo,USHORT ModeIdIndex);

extern USHORT   SiS_GetColorDepth(SiS_Private *SiS_Pr,USHORT ModeNo,USHORT ModeIdIndex);
extern USHORT   SiS_GetOffset(SiS_Private *SiS_Pr,USHORT ModeNo,USHORT ModeIdIndex,
                              USHORT RefreshRateTableIndex,PSIS_HW_INFO HwInfo);

extern void     SiS_LoadDAC(SiS_Private *SiS_Pr, PSIS_HW_INFO,USHORT ModeNo,
                            USHORT ModeIdIndex);


#endif
