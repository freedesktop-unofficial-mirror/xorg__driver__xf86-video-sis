/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/sis/sis_driver.h,v 1.29 2003/11/29 12:08:02 twini Exp $ */
/*
 * Global data and definitions
 *
 * Copyright 2002, 2003 by Thomas Winischhofer, Vienna, Austria
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the copyright holder not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  The copyright holder makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDER DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * Author:     	Thomas Winischhofer <thomas@winischhofer.net>
 *
 */

/* VESA */
/*     The following is included because there are BIOSes out there that
 *     report incomplete mode lists. These are 630 BIOS versions <2.01.2x
 *
 *     -) VBE 3.0 on SiS300 and 315 series do not support 24 fpp modes
 *     -) Only SiS315 series support 1920x1440x32
 */
				             /*     8      16    (24)    32   */
static const UShort  VESAModeIndex_320x200[]   = {0x138, 0x10e, 0x000, 0x000};
static const UShort  VESAModeIndex_320x240[]   = {0x132, 0x135, 0x000, 0x000};
static const UShort  VESAModeIndex_400x300[]   = {0x133, 0x136, 0x000, 0x000};
static const UShort  VESAModeIndex_512x384[]   = {0x134, 0x137, 0x000, 0x000};
static const UShort  VESAModeIndex_640x400[]   = {0x100, 0x139, 0x000, 0x000};
static const UShort  VESAModeIndex_640x480[]   = {0x101, 0x111, 0x000, 0x13a};
static const UShort  VESAModeIndex_800x600[]   = {0x103, 0x114, 0x000, 0x13b};
static const UShort  VESAModeIndex_1024x768[]  = {0x105, 0x117, 0x000, 0x13c};
static const UShort  VESAModeIndex_1280x1024[] = {0x107, 0x11a, 0x000, 0x13d};
static const UShort  VESAModeIndex_1600x1200[] = {0x130, 0x131, 0x000, 0x13e};
static const UShort  VESAModeIndex_1920x1440[] = {0x13f, 0x140, 0x000, 0x141};

/* For calculating refresh rate index (CR33) */
static const struct _sis_vrate {
    CARD16 idx;
    CARD16 xres;
    CARD16 yres;
    CARD16 refresh;
    BOOLEAN SiS730valid32bpp;
} sisx_vrate[] = {
	{1,  320,  200,  70,  TRUE},
	{1,  320,  240,  60,  TRUE},
	{1,  400,  300,  60,  TRUE},
        {1,  512,  384,  60,  TRUE},
	{1,  640,  400,  72,  TRUE},
	{1,  640,  480,  60,  TRUE}, {2,  640,  480,  72,  TRUE}, {3,  640,  480,  75,  TRUE}, 
	{4,  640,  480,  85,  TRUE}, {5,  640,  480, 100,  TRUE}, {6,  640,  480, 120,  TRUE}, 
	{7,  640,  480, 160, FALSE}, {8,  640,  480, 200, FALSE},
	{1,  720,  480,  60,  TRUE},
	{1,  720,  576,  58,  TRUE},
	{1,  768,  576,  58,  TRUE},
	{1,  800,  480,  60,  TRUE}, {2,  800,  480,  75,  TRUE}, {3,  800,  480,  85,  TRUE},
	{1,  800,  600,  56,  TRUE}, {2,  800,  600,  60,  TRUE}, {3,  800,  600,  72,  TRUE}, 
	{4,  800,  600,  75,  TRUE}, {5,  800,  600,  85,  TRUE}, {6,  800,  600, 105,  TRUE}, 
	{7,  800,  600, 120, FALSE}, {8,  800,  600, 160, FALSE},
	{1,  848,  480,  39,  TRUE}, {2,  848,  480,  60,  TRUE},
	{1,  856,  480,  39,  TRUE}, {2,  856,  480,  60,  TRUE},
	{1, 1024,  576,  60,  TRUE}, {2, 1024,  576,  75,  TRUE}, {3, 1024,  576,  85,  TRUE},
	{1, 1024,  600,  60,  TRUE},
	{1, 1024,  768,  43,  TRUE}, {2, 1024,  768,  60,  TRUE}, {3, 1024,  768,  70, FALSE},
	{4, 1024,  768,  75, FALSE}, {5, 1024,  768,  85,  TRUE}, {6, 1024,  768, 100,  TRUE},
	{7, 1024,  768, 120,  TRUE},
	{1, 1152,  768,  60,  TRUE},
	{1, 1152,  864,  75,  TRUE}, {2, 1152,  864,  84, FALSE},
	{1, 1280,  720,  60,  TRUE}, {2, 1280,  720,  75, FALSE}, {3, 1280,  720,  85,  TRUE},
	{1, 1280,  768,  60,  TRUE},
	{1, 1280,  960,  60,  TRUE}, {2, 1280,  960,  85,  TRUE},
	{1, 1280, 1024,  43, FALSE}, {2, 1280, 1024,  60,  TRUE}, {3, 1280, 1024,  75, FALSE},
	{4, 1280, 1024,  85,  TRUE},
	{1, 1360,  768,  60,  TRUE},
	{1, 1400, 1050,  60,  TRUE}, {2, 1400, 1050,  75,  TRUE},
	{1, 1600, 1200,  60,  TRUE}, {2, 1600, 1200,  65,  TRUE}, {3, 1600, 1200,  70,  TRUE}, 
	{4, 1600, 1200,  75,  TRUE}, {5, 1600, 1200,  85,  TRUE}, {6, 1600, 1200, 100,  TRUE}, 
	{7, 1600, 1200, 120,  TRUE},
	{1, 1920, 1440,  60,  TRUE}, {2, 1920, 1440,  65,  TRUE}, {3, 1920, 1440,  70,  TRUE},
	{4, 1920, 1440,  75,  TRUE}, {5, 1920, 1440,  85,  TRUE}, {6, 1920, 1440, 100,  TRUE},
	{1, 2048, 1536,  60,  TRUE}, {2, 2048, 1536,  65,  TRUE}, {3, 2048, 1536,  70,  TRUE}, 
	{4, 2048, 1536,  75,  TRUE}, {5, 2048, 1536,  85,  TRUE},
	{0,    0,    0,   0, FALSE}
};

/*     Some 300-series laptops have a badly designed BIOS and make it
 *     impossible to detect the correct panel delay compensation. This
 *     table used to detect such machines by their PCI subsystem IDs;
 *     however, I don't know how reliable this method is. (With Asus
 *     machines, it is to general, ASUS uses the same ID for different
 *     boxes)
 */
static const pdctable mypdctable[] = {
        { 0x1071, 0x7522, 32, "Mitac", "7521T" },
	{ 0,      0,       0, ""     , ""      }
};

/*     These machines require setting/clearing a GPIO bit for enabling/
 *     disabling communication with the Chrontel TV encoder
 */
static const chswtable mychswtable[] = {
        { 0x1631, 0x1002, "Mitachi", "0x1002" },
	{ 0x1071, 0x7521, "Mitac"  , "7521P"  },
	{ 0,      0,      ""       , ""       }
};

/*     These machines require special timing/handling
 */
const customttable mycustomttable[] = {
        { SIS_630, "2.00.07", "09/27/2002-13:38:25",
	  0x3240A8,
	  { 0x220, 0x227, 0x228, 0x229, 0x0ee },
	  {  0x01,  0xe3,  0x9a,  0x6a,  0xef },
	  0x1039, 0x6300,
	  "Barco", "iQ R200L/300/400", CUT_BARCO1366, "BARCO_1366"
	},
	{ SIS_630, "2.00.07", "09/27/2002-13:38:25",
	  0x323FBD,
	  { 0x220, 0x227, 0x228, 0x229, 0x0ee },
	  {  0x00,  0x5a,  0x64,  0x41,  0xef },
	  0x1039, 0x6300,
	  "Barco", "iQ G200L/300/400/500", CUT_BARCO1024, "BARCO_1024"
	},
	{ SIS_650, "", "",
	  0,
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x0e11, 0x083c,
	  "Inventec (Compaq)", "3017cl/3045US", CUT_COMPAQ12802, "COMPAQ_1280"
	},
	{ SIS_650, "", "",
	  0,	/* Special 1024x768 / dual link */
	  { 0x00c, 0, 0, 0, 0 },
	  { 'e'  , 0, 0, 0, 0 },
	  0x1558, 0x0287,
	  "Clevo", "L285/L287 (Version 1)", CUT_CLEVO1024, "CLEVO_L28X_1"
	},
	{ SIS_650, "", "",
	  0,	/* Special 1024x768 / single link */
	  { 0x00c, 0, 0, 0, 0 },
	  { 'y'  , 0, 0, 0, 0 },
	  0x1558, 0x0287,
	  "Clevo", "L285/L287 (Version 2)", CUT_CLEVO10242, "CLEVO_L28X_2"
	},
	{ SIS_650, "", "",
	  0,	/* Special 1400x1050 */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1558, 0x0400,  /* possibly 401 and 402 as well; not panelsize specific? */
	  "Clevo", "D400S/D410S/D400H/D410H", CUT_CLEVO1400, "CLEVO_D4X0"
	},
	{ SIS_650, "", "",
	  0,	/* Shift LCD in LCD-via-CRT1 mode */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1558, 0x2263,
	  "Clevo", "D22ES/D27ES", CUT_UNIWILL1024, "CLEVO_D2X0ES"
	},
	{ SIS_650, "", "",
	  0,	/* Shift LCD in LCD-via-CRT1 mode */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1734, 0x101f,
	  "Uniwill", "N243S9", CUT_UNIWILL1024, "UNIWILL_N243S9"
	},
	{ SIS_650, "", "",
	  0,	/* Shift LCD in LCD-via-CRT1 mode */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1584, 0x5103,
	  "Uniwill", "N35BS1", CUT_UNIWILL10242, "UNIWILL_N35BS1"
	},
	{ SIS_650, "1.09.2c", "",  /* Other versions, too? */
	  0,	/* Shift LCD in LCD-via-CRT1 mode */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1019, 0x0f05,
	  "ECS", "A928", CUT_UNIWILL1024, "ECS_A928"
	},
	{ SIS_740, "1.11.27a", "",
	  0,
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1043, 0x1612,
	  "Asus", "L3000D/L3500D", CUT_ASUSL3000D, "ASUS_L3X00"
	},
	{ SIS_650, "1.10.9k", "",
	  0,	/* For EMI */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1025, 0x0028,
	  "Acer", "Aspire 1700", CUT_ACER1280, "ACER_ASPIRE1700"
	},
	{ SIS_650, "1.10.7w", "",
	  0,	/* For EMI */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x14c0, 0x0012,
	  "Compal", "??? (V1)", CUT_COMPAL1400_1, "COMPAL_1400_1"
	},
	{ SIS_650, "1.10.7x", "",
	  0,	/* For EMI */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x14c0, 0x0012,
	  "Compal", "??? (V2)", CUT_COMPAL1400_2, "COMPAL_1400_2"
	},
	{ SIS_650, "1.10.8o", "",
	  0,	/* For EMI (unknown) */
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0x1043, 0x1612,
	  "Asus", "A2H", CUT_ASUSA2H, "ASUS_A2H"
	},
	{ 4321, "", "",			/* never autodetected */
	  0,
	  { 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0 },
	  0, 0,
	  "Generic", "LVDS/Parallel 848x480", CUT_PANEL848, "PANEL848x480"
	},
	{ 0, "", "",
	  0,
	  { 0, 0, 0, 0 },
	  { 0, 0, 0, 0 },
	  0, 0,
	  "", "", CUT_NONE, ""
	}
};

/*     Our TV modes for the 6326. The data in these structures
 *     is mainly correct, but since we use our private CR and
 *     clock values anyway, small errors do no matter.
 */
static DisplayModeRec SiS6326PAL800x600Mode = {
	NULL, NULL,     /* prev, next */
	"PAL800x600",   /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	36000,		/* Clock frequency */
	800,		/* HDisplay */
	848,		/* HSyncStart */
	912,		/* HSyncEnd */
	1008,		/* HTotal */
	0,		/* HSkew */
	600,		/* VDisplay */
	600,		/* VSyncStart */
	602,		/* VSyncEnd */
	625,		/* VTotal */
	0,		/* VScan */
	V_PHSYNC | V_PVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	36000,		/* SynthClock */
	800,		/* CRTC HDisplay */
	808,            /* CRTC HBlankStart */
	848,            /* CRTC HSyncStart */
	912,            /* CRTC HSyncEnd */
	1008,           /* CRTC HBlankEnd */
	1008,           /* CRTC HTotal */
	0,              /* CRTC HSkew */
	600,		/* CRTC VDisplay */
	600,		/* CRTC VBlankStart */
	600,		/* CRTC VSyncStart */
	602,		/* CRTC VSyncEnd */
	625,		/* CRTC VBlankEnd */
	625,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

/*     Due to the scaling method this mode uses, the vertical data here
 *     does not match the CR data. But this does not matter, we use our
 *     private CR data anyway.
 */
static DisplayModeRec SiS6326PAL800x600UMode = {
	NULL,           /* prev */
	&SiS6326PAL800x600Mode, /* next */
	"PAL800x600U",  /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	37120,		/* Clock frequency */
	800,		/* HDisplay */
	872,		/* HSyncStart */
	984,		/* HSyncEnd */
	1088,		/* HTotal */
	0,		/* HSkew */
	600,		/* VDisplay (548 due to scaling) */
	600,		/* VSyncStart (584) */
	602,		/* VSyncEnd (586) */
	625,		/* VTotal */
	0,		/* VScan */
	V_PHSYNC | V_PVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	37120,		/* SynthClock */
	800,		/* CRTC HDisplay */
	808,            /* CRTC HBlankStart */
	872,            /* CRTC HSyncStart */
	984,            /* CRTC HSyncEnd */
	1024,           /* CRTC HBlankEnd */
	1088,           /* CRTC HTotal */
	0,              /* CRTC HSkew */
	600,		/* CRTC VDisplay (548 due to scaling) */
	600,		/* CRTC VBlankStart (600) */
	600,		/* CRTC VSyncStart (584) */
	602,		/* CRTC VSyncEnd (586) */
	625,		/* CRTC VBlankEnd */
	625,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

static DisplayModeRec SiS6326PAL720x540Mode = {
	NULL,      	/* prev */
	&SiS6326PAL800x600UMode, /* next */
	"PAL720x540",   /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	36000,		/* Clock frequency */
	720,		/* HDisplay */
	816,		/* HSyncStart */
	920,		/* HSyncEnd */
	1008,		/* HTotal */
	0,		/* HSkew */
	540,		/* VDisplay */
	578,		/* VSyncStart */
	580,		/* VSyncEnd */
	625,		/* VTotal */
	0,		/* VScan */
	V_PHSYNC | V_PVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	36000,		/* SynthClock */
	720,		/* CRTC HDisplay */
	736,            /* CRTC HBlankStart */
	816,            /* CRTC HSyncStart */
	920,            /* CRTC HSyncEnd */
	1008,           /* CRTC HBlankEnd */
	1008,           /* CRTC HTotal */
	0,              /* CRTC HSkew */
	540,		/* CRTC VDisplay */
	577,		/* CRTC VBlankStart */
	578,		/* CRTC VSyncStart */
	580,		/* CRTC VSyncEnd */
	625,		/* CRTC VBlankEnd */
	625,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

static DisplayModeRec SiS6326PAL640x480Mode = {
	NULL,      	/* prev */
	&SiS6326PAL720x540Mode, /* next */
	"PAL640x480",   /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	36000,		/* Clock frequency */
	640,		/* HDisplay */
	768,		/* HSyncStart */
	920,		/* HSyncEnd */
	1008,		/* HTotal */
	0,		/* HSkew */
	480,		/* VDisplay */
	532,		/* VSyncStart */
	534,		/* VSyncEnd */
	625,		/* VTotal */
	0,		/* VScan */
	V_NHSYNC | V_NVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	36000,		/* SynthClock */
	640,		/* CRTC HDisplay */
	648,            /* CRTC HBlankStart */
	768,            /* CRTC HSyncStart */
	920,            /* CRTC HSyncEnd */
	944,            /* CRTC HBlankEnd */
	1008,           /* CRTC HTotal */
	0,              /* CRTC HSkew */
	480,		/* CRTC VDisplay */
	481,		/* CRTC VBlankStart */
	532,		/* CRTC VSyncStart */
	534,		/* CRTC VSyncEnd */
	561,		/* CRTC VBlankEnd */
	625,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

static DisplayModeRec SiS6326NTSC640x480Mode = {
	NULL, NULL,	/* prev, next */
	"NTSC640x480",  /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	27000,		/* Clock frequency */
	640,		/* HDisplay */
	664,		/* HSyncStart */
	760,		/* HSyncEnd */
	800,		/* HTotal */
	0,		/* HSkew */
	480,		/* VDisplay */
	489,		/* VSyncStart */
	491,		/* VSyncEnd */
	525,		/* VTotal */
	0,		/* VScan */
	V_NHSYNC | V_NVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	27000,		/* SynthClock */
	640,		/* CRTC HDisplay */
	648,            /* CRTC HBlankStart */
	664,            /* CRTC HSyncStart */
	760,            /* CRTC HSyncEnd */
	792,            /* CRTC HBlankEnd */
	800,            /* CRTC HTotal */
	0,              /* CRTC HSkew */
	480,		/* CRTC VDisplay */
	488,		/* CRTC VBlankStart */
	489,		/* CRTC VSyncStart */
	491,		/* CRTC VSyncEnd */
	517,		/* CRTC VBlankEnd */
	525,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

/*     Due to the scaling method this mode uses, the vertical data here
 *     does not match the CR data. But this does not matter, we use our
 *     private CR data anyway.
 */
static DisplayModeRec SiS6326NTSC640x480UMode = {
	NULL, 		/* prev */
	&SiS6326NTSC640x480Mode, /* next */
	"NTSC640x480U", /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	32215,		/* Clock frequency */
	640,		/* HDisplay */
	696,		/* HSyncStart */
	840,		/* HSyncEnd */
	856,		/* HTotal */
	0,		/* HSkew */
	480,		/* VDisplay (439 due to scaling) */
	489,		/* VSyncStart (473) */
	491,		/* VSyncEnd (475) */
	525,		/* VTotal */
	0,		/* VScan */
	V_NHSYNC | V_NVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	32215,		/* SynthClock */
	640,		/* CRTC HDisplay */
	656,            /* CRTC HBlankStart */
	696,            /* CRTC HSyncStart */
	840,            /* CRTC HSyncEnd */
	856,            /* CRTC HBlankEnd */
	856,            /* CRTC HTotal */
	0,              /* CRTC HSkew */
	480,		/* CRTC VDisplay */
	488,		/* CRTC VBlankStart */
	489,		/* CRTC VSyncStart */
	491,		/* CRTC VSyncEnd */
	517,		/* CRTC VBlankEnd */
	525,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};


static DisplayModeRec SiS6326NTSC640x400Mode = {
	NULL, 	     	/* prev */
	&SiS6326NTSC640x480UMode, /* next */
	"NTSC640x400",  /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	27000,		/* Clock frequency */
	640,		/* HDisplay */
	664,		/* HSyncStart */
	760,		/* HSyncEnd */
	800,		/* HTotal */
	0,		/* HSkew */
	400,		/* VDisplay */
	459,		/* VSyncStart */
	461,		/* VSyncEnd */
	525,		/* VTotal */
	0,		/* VScan */
	V_NHSYNC | V_NVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	27000,		/* SynthClock */
	640,		/* CRTC HDisplay */
	648,            /* CRTC HBlankStart */
	664,            /* CRTC HSyncStart */
	760,            /* CRTC HSyncEnd */
	792,            /* CRTC HBlankEnd */
	800,            /* CRTC HTotal */
	0,              /* CRTC HSkew */
	400,		/* CRTC VDisplay */
	407,		/* CRTC VBlankStart */
	459,		/* CRTC VSyncStart */
	461,		/* CRTC VSyncEnd */
	490,		/* CRTC VBlankEnd */
	525,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

/*     Built-in hi-res modes for the 6326.
 *     For some reason, our default mode lines and the
 *     clock calculation functions in sis_dac.c do no
 *     good job on higher clocks. It seems, the hardware
 *     needs some tricks so make mode with higher clock
 *     rates than ca. 120MHz work. I didn't bother trying
 *     to find out what exactly is going wrong, so I
 *     implemented two special modes instead for 1280x1024
 *     and 1600x1200. These two are automatically added
 *     to the list if they are supported with the current
 *     depth.
 *     The data in the strucures below is a proximation,
 *     in sis_vga.c the register contents are fetched from
 *     fixed tables anyway.
 */
static DisplayModeRec SiS6326SIS1280x1024_75Mode = {
	NULL, 	       	/* prev */
	NULL,           /* next */
	"SIS1280x1024-75",  /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	135000,		/* Clock frequency */
	1280,		/* HDisplay */
	1296,		/* HSyncStart */
	1440,		/* HSyncEnd */
	1688,		/* HTotal */
	0,		/* HSkew */
	1024,		/* VDisplay */
	1025,		/* VSyncStart */
	1028,		/* VSyncEnd */
	1066,		/* VTotal */
	0,		/* VScan */
	V_PHSYNC | V_PVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	135000,		/* SynthClock */
	1280,		/* CRTC HDisplay */
	1280,           /* CRTC HBlankStart */
	1296,           /* CRTC HSyncStart */
	1440,           /* CRTC HSyncEnd */
	1680,           /* CRTC HBlankEnd */
	1688,           /* CRTC HTotal */
	0,              /* CRTC HSkew */
	1024,		/* CRTC VDisplay */
	1024,		/* CRTC VBlankStart */
	1025,		/* CRTC VSyncStart */
	1028,		/* CRTC VSyncEnd */
	1065,		/* CRTC VBlankEnd */
	1066,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

static DisplayModeRec SiS6326SIS1600x1200_60Mode = {
	NULL, 	       	/* prev */
	NULL,           /* next */
	"SIS1600x1200-60",  /* identifier of this mode */
	MODE_OK,        /* mode status */
	M_T_BUILTIN,    /* mode type */
	162000,		/* Clock frequency */
	1600,		/* HDisplay */
	1664,		/* HSyncStart */
	1856,		/* HSyncEnd */
	2160,		/* HTotal */
	0,		/* HSkew */
	1200,		/* VDisplay */
	1201,		/* VSyncStart */
	1204,		/* VSyncEnd */
	1250,		/* VTotal */
	0,		/* VScan */
	V_PHSYNC | V_PVSYNC,	/* Flags */
	-1,		/* ClockIndex */
	162000,		/* SynthClock */
	1600,		/* CRTC HDisplay */
	1600,           /* CRTC HBlankStart */
	1664,           /* CRTC HSyncStart */
	1856,           /* CRTC HSyncEnd */
	2152,            /* CRTC HBlankEnd */
	2160,            /* CRTC HTotal */
	0,              /* CRTC HSkew */
	1200,		/* CRTC VDisplay */
	1200,		/* CRTC VBlankStart */
	1201,		/* CRTC VSyncStart */
	1204,		/* CRTC VSyncEnd */
	1249,		/* CRTC VBlankEnd */
	1250,		/* CRTC VTotal */
	FALSE,		/* CrtcHAdjusted */
	FALSE,		/* CrtcVAdjusted */
	0,		/* PrivSize */
	NULL,		/* Private */
	0.0,		/* HSync */
	0.0		/* VRefresh */
};

/*     TV filters for SiS video bridges
 */
static const struct _SiSTVFilter301 {
	unsigned char filter[7][4];
} SiSTVFilter301[] = {
	{{ {0x00,0xE0,0x10,0x60},   /* NTSCFilter - 320 */
	   {0x00,0xEE,0x10,0x44},
	   {0x00,0xF4,0x10,0x38},
	   {0xF8,0xF4,0x18,0x38},
	   {0xFC,0xFB,0x14,0x2A},
	   {0x00,0x00,0x10,0x20},
	   {0x00,0x04,0x10,0x18} }},
	{{ {0xF5,0xEE,0x1B,0x44},   /* NTSCFilter - 640 */
	   {0xF8,0xF4,0x18,0x38},
	   {0xEB,0x04,0x25,0x18},
	   {0xF1,0x05,0x1F,0x16},
	   {0xF6,0x06,0x1A,0x14},
	   {0xFA,0x06,0x16,0x14},
	   {0x00,0x04,0x10,0x18} }},
	{{ {0xEB,0x04,0x25,0x18},   /* NTSCFilter - 720 */
	   {0xE7,0x0E,0x29,0x04},
	   {0xEE,0x0C,0x22,0x08},
	   {0xF6,0x0B,0x1A,0x0A},
	   {0xF9,0x0A,0x17,0x0C},
	   {0xFC,0x0A,0x14,0x0C},
	   {0x00,0x08,0x10,0x10} }},
	{{ {0xEC,0x02,0x24,0x1C},   /* NTSCFilter - 800/400 */
	   {0xF2,0x04,0x1E,0x18},
	   {0xEB,0x15,0x25,0xF6},
	   {0xF4,0x10,0x1C,0x00},
	   {0xF8,0x0F,0x18,0x02},
	   {0x00,0x04,0x10,0x18},
	   {0x01,0x06,0x0F,0x14} }},
	{{ {0x00,0xE0,0x10,0x60},   /* PALFilter - 320 */
	   {0x00,0xEE,0x10,0x44},
	   {0x00,0xF4,0x10,0x38},
	   {0xF8,0xF4,0x18,0x38},
	   {0xFC,0xFB,0x14,0x2A},
	   {0x00,0x00,0x10,0x20},
	   {0x00,0x04,0x10,0x18} }},
	{{ {0xF5,0xEE,0x1B,0x44},   /* PALFilter - 640 */
	   {0xF8,0xF4,0x18,0x38},
	   {0xF1,0xF7,0x1F,0x32},
	   {0xF5,0xFB,0x1B,0x2A},
	   {0xF9,0xFF,0x17,0x22},
	   {0xFB,0x01,0x15,0x1E},
	   {0x00,0x04,0x10,0x18} }},
	{{ {0xF5,0xEE,0x1B,0x2A},   /* PALFilter - 720 */
	   {0xEE,0xFE,0x22,0x24},
	   {0xF3,0x00,0x1D,0x20},
	   {0xF9,0x03,0x17,0x1A},
	   {0xFB,0x02,0x14,0x1E},
	   {0xFB,0x04,0x15,0x18},
	   {0x00,0x06,0x10,0x14} }},
	{{ {0xF5,0xEE,0x1B,0x44},   /* PALFilter - 800/400 */
	   {0xF8,0xF4,0x18,0x38},
	   {0xFC,0xFB,0x14,0x2A},
	   {0xEB,0x05,0x25,0x16},
	   {0xF1,0x05,0x1F,0x16},
	   {0xFA,0x07,0x16,0x12},
	   {0x00,0x07,0x10,0x12} }}
};

static const struct _SiSTVFilter301B {
	unsigned char filter[7][7];
} SiSTVFilter301B[] = {
	{{ {0x01,0x02,0xfb,0xf8,0x06,0x27,0x3a},   /* NTSC - 640 */
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0x01,0x01,0x00,0xf6,0x00,0x28,0x40},
	   {0xff,0x03,0x02,0xf6,0xfc,0x27,0x46},
	   {0xff,0x01,0x04,0xf8,0xfa,0x27,0x46},
	   {0xff,0x01,0x05,0xf9,0xf7,0x26,0x4a},
	   {0xff,0xff,0x05,0xfc,0xf4,0x24,0x52} }},
	{{ {0x01,0x00,0xfb,0xfb,0x0b,0x25,0x32},   /* NTSC - 720 (?) */
	   {0x01,0x01,0xfb,0xf9,0x09,0x26,0x36},
	   {0x01,0x02,0xfc,0xf8,0x06,0x27,0x38},
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0x01,0x03,0xff,0xf6,0x00,0x27,0x40},
	   {0xff,0x03,0x02,0xf6,0xfe,0x27,0x42},
	   {0xff,0x02,0x03,0xf7,0xfb,0x27,0x46} }},
	{{ {0x01,0xfe,0xfb,0xfe,0x0e,0x23,0x2e},   /* NTSC - 800 */
	   {0x01,0xff,0xfb,0xfc,0x0c,0x25,0x30},
	   {0x01,0x00,0xfb,0xfa,0x0a,0x26,0x34},
	   {0x01,0x01,0xfc,0xf8,0x08,0x26,0x38},
	   {0x01,0x02,0xfd,0xf7,0x06,0x27,0x38},
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0xff,0x03,0x00,0xf6,0x00,0x27,0x42} }},
	{{ {0xff,0xfd,0xfe,0x05,0x11,0x1e,0x24},   /* NTSC - 1024 */
	   {0xff,0xfd,0xfd,0x04,0x11,0x1f,0x26},
	   {0xff,0xfd,0xfc,0x02,0x10,0x22,0x28},
	   {0xff,0xff,0xfc,0x00,0x0f,0x22,0x28},
	   {0x01,0xfe,0xfb,0xff,0x0e,0x23,0x2c},
	   {0x01,0xff,0xfb,0xfd,0x0d,0x24,0x2e},
	   {0x01,0xff,0xfb,0xfb,0x0c,0x25,0x32} }},
	{{ {0x01,0x02,0xfb,0xf8,0x06,0x27,0x3a},   /* PAL - 640 */
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0x01,0x01,0x00,0xf6,0x00,0x28,0x40},
	   {0xff,0x03,0x02,0xf6,0xfc,0x27,0x46},
	   {0xff,0x01,0x04,0xf8,0xfa,0x27,0x46},
	   {0xff,0x01,0x05,0xf9,0xf7,0x26,0x4a},
	   {0xff,0xff,0x05,0xfc,0xf4,0x24,0x52} }},
	{{ {0x01,0x00,0xfb,0xfb,0x0b,0x25,0x32},   /* PAL - 720/768 */
	   {0x01,0x01,0xfb,0xf9,0x09,0x26,0x36},
	   {0x01,0x02,0xfc,0xf8,0x06,0x27,0x38},
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0x01,0x03,0xff,0xf6,0x00,0x27,0x40},
	   {0xff,0x03,0x02,0xf6,0xfe,0x27,0x42},
	   {0xff,0x02,0x03,0xf7,0xfb,0x27,0x46} }},
	{{ {0x01,0xfe,0xfb,0xfe,0x0e,0x23,0x2e},   /* PAL - 800 */
	   {0x01,0xff,0xfb,0xfc,0x0c,0x25,0x30},
	   {0x01,0x00,0xfb,0xfa,0x0a,0x26,0x34},
	   {0x01,0x01,0xfc,0xf8,0x08,0x26,0x38},
	   {0x01,0x02,0xfd,0xf7,0x06,0x27,0x38},
	   {0x01,0x02,0xfe,0xf7,0x03,0x27,0x3c},
	   {0xff,0x03,0x00,0xf6,0x00,0x27,0x42} }},
	{{ {0xff,0xfd,0xfe,0x05,0x11,0x1e,0x24},   /* PAL - 1024 */
	   {0xff,0xfd,0xfd,0x04,0x11,0x1f,0x26},
	   {0xff,0xfd,0xfc,0x02,0x10,0x22,0x28},
	   {0xff,0xff,0xfc,0x00,0x0f,0x22,0x28},
	   {0x01,0xfe,0xfb,0xff,0x0e,0x23,0x2c},
	   {0x01,0xff,0xfb,0xfd,0x0d,0x24,0x2e},
	   {0x01,0xff,0xfb,0xfb,0x0c,0x25,0x32} }}
};

/*     TV scaling data for SiS video bridges
 */
typedef struct _SiSTVVScale {
        unsigned short ScaleVDE;
	int sindex;
	unsigned short RealVDE;
#if 0
	unsigned short HT, HRS, HRE, VT, VRS, VRE;
	unsigned short NFF, HCFACT, HCMAX, VBHT, VBVT, VBHRS;
	unsigned short HT300, HRS300, HRE300, VT300, VRS300, VRE300;
	unsigned short NFF300, HCFACT300, HCMAX300, VBHT300, VBVT300, VBHRS300;
#endif
	unsigned short reg[24];
} MySiSTVVScale, *MySiSTVVScalePtr;

static const MySiSTVVScale SiSTVVScale[] = {
      { 0x01D6, 3, 480,					/* NTSC 640 */
        { 0x037C, 0x02B0, 0x00EF, 0x01FA, 0x01E7, 0x01E9,
          0x0000, 0x004C, 0x008F, 0x037C, 0x01FB, 0x00D4,
	  0x037C, 0x02CB, 0x0049, 0x01FB, 0x01EE, 0x01F0,
	  0x0000, 0x004C, 0x008F, 0x037C, 0x01FB, 0x00E0 }
      },
      { 0x01CC, 2, 480,
        { 0x0369, 0x02AD, 0x00E7, 0x01FF, 0x01E8, 0x01EB,
	  0x0000, 0x004C, 0x008F, 0x0369, 0x0200, 0x00D4,
	  0x0369, 0x02C6, 0x003A, 0x0200, 0x01F0, 0x01F3,
	  0x0000, 0x004C, 0x008F, 0x0369, 0x0200, 0x00E0 }
      },
      { 0x01C2, 1, 480,
        { 0x0356, 0x02AB, 0x00E0, 0x0204, 0x01E9, 0x01EC,
	  0x0000, 0x004C, 0x008F, 0x0356, 0x0205, 0x00D4,
	  0x0356, 0x02C1, 0x002B, 0x0205, 0x01F3, 0x01F6,
	  0x0000, 0x004C, 0x008F, 0x0356, 0x0205, 0x00E0 }
      },
      { 0x01B8, 0, 480, /* default */
        { 0x0343, 0x02A9, 0x00DA, 0x0209, 0x01EA, 0x01ED,
	  0x0000, 0x004C, 0x008F, 0x0343, 0x020A, 0x00D4,
	  0x0343, 0x02BD, 0x001F, 0x020A, 0x01F5, 0x01F8,
	  0x0000, 0x004C, 0x008F, 0x0343, 0x020A, 0x00E0 }
      },
      { 0x01AE, -1, 480,
        { 0x035B, 0x02AC, 0x00E3, 0x020E, 0x01EC, 0x01F0,
	  0x0000, 0x0050, 0x008F, 0x035B, 0x020F, 0x0152,
	  0x035B, 0x02C3, 0x0031, 0x020F, 0x01F8, 0x01FC,
	  0x0000, 0x0050, 0x008F, 0x035B, 0x020F, 0x015E }
      },
      { 0x01A4, -2, 480,
        { 0x0347, 0x02A9, 0x00DB, 0x0213, 0x01ED, 0x01F1,
	  0x0000, 0x0050, 0x008F, 0x0347, 0x0214, 0x0102,
	  0x0347, 0x02BE, 0x0022, 0x0214, 0x01FA, 0x01FE,
	  0x0000, 0x0050, 0x008F, 0x0347, 0x0214, 0x010E }
      },
      { 0x019A, -3, 480,
        { 0x0333, 0x02A7, 0x00D4, 0x0218, 0x01EE, 0x01F2,
	  0x0000, 0x0050, 0x008F, 0x0333, 0x0219, 0x016A,
	  0x0333, 0x02B9, 0x0013, 0x0219, 0x01FD, 0x0201,
	  0x0000, 0x0050, 0x008F, 0x0333, 0x0219, 0x016A }
      },
      { 0x01D6, 3, 480,					/* NTSC 720 */
        { 0x037C, 0x0307, 0x005D, 0x01FB, 0x01EE, 0x01F0,
	  0x0000, 0x004C, 0x008F, 0x037C, 0x01FB, 0x0090 }
      },
      { 0x01CC, 2, 480,
        { 0x0369, 0x0302, 0x004E, 0x0200, 0x01F0, 0x01F3,
	  0x0000, 0x004C, 0x008F, 0x0369, 0x0200, 0x0090 }
      },
      { 0x01C2, 1, 480,
        { 0x0356, 0x02FD, 0x003F, 0x0205, 0x01F3, 0x01F6,
	  0x0000, 0x004C, 0x008F, 0x0356, 0x0205, 0x0090 }
      },
      { 0x01B8, 0, 480, /* default */
        { 0x0343, 0x02F9, 0x0033, 0x020A, 0x01F5, 0x01F8,
	  0x0000, 0x004C, 0x008F, 0x0343, 0x020A, 0x0090 }
      },
      { 0x01AE, -1, 480,
        { 0x035B, 0x02FF, 0x0045, 0x020F, 0x01F8, 0x01FC,
	  0x0000, 0x0050, 0x008F, 0x035B, 0x020F, 0x010E }
      },
      { 0x01A4, -2, 480,
        { 0x0347, 0x02FA, 0x0036, 0x0214, 0x01FA, 0x01FE,
	  0x0000, 0x0050, 0x008F, 0x0347, 0x0214, 0x00BE }
      },
      { 0x019A, -3, 480,
        { 0x0333, 0x02F5, 0x0027, 0x0219, 0x01FD, 0x0201,
	  0x0000, 0x0050, 0x008F, 0x0333, 0x0219, 0x0136 }
      },
      { 0x01D6, 3, 600,					/* NTSC 800 */
        { 0x0438, 0x0353, 0x0099, 0x0272, 0x025F, 0x0261,
	  0x0000, 0x0073, 0x008F, 0x0438, 0x0273, 0x020A,
	  0x0438, 0x0372, 0x00FE, 0x0273, 0x0266, 0x0268,
	  0x0000, 0x0073, 0x008F, 0x0438, 0x0273, 0x020A }
      },
      { 0x01CC, 2, 600,
        { 0x0421, 0x0350, 0x0090, 0x0277, 0x0260, 0x0263,
	  0x0000, 0x0073, 0x008F, 0x0421, 0x0278, 0x020A,
	  0x0421, 0x036C, 0x00EC, 0x0278, 0x0268, 0x026B,
	  0x0000, 0x0073, 0x008F, 0x0421, 0x0278, 0x020A }
      },
      { 0x01C2, 1, 600,
        { 0x0413, 0x034F, 0x008C, 0x027C, 0x0261, 0x0264,
	  0x0000, 0x0074, 0x008F, 0x0413, 0x027D, 0x01FE,
	  0x0413, 0x0369, 0x00E3, 0x027D, 0x026B, 0x026E,
	  0x0000, 0x0074, 0x008F, 0x0413, 0x027D, 0x020C }
      },
      { 0x01B8, 0, 600, /* default */
        { 0x041F, 0x0350, 0x0090, 0x0281, 0x0262, 0x0265,
	  0x0000, 0x0078, 0x008F, 0x041F, 0x0282, 0x0220,
	  0x041F, 0x036C, 0x00EC, 0x0282, 0x026D, 0x0270,
	  0x0001, 0x0078, 0x008F, 0x041F, 0x0282, 0x0220 }
      },
      { 0x01AE, -1, 600,
        { 0x0407, 0x034D, 0x0087, 0x0286, 0x0264, 0x0268,
	  0x0000, 0x0078, 0x008F, 0x0407, 0x0287, 0x0220,
	  0x0407, 0x0366, 0x00DA, 0x0287, 0x0270, 0x0274,
	  0x0001, 0x0078, 0x008F, 0x0407, 0x0287, 0x0220 }
      },
      { 0x01A4, -2, 600,
        { 0x03EF, 0x034A, 0x007E, 0x028B, 0x0265, 0x0269,
	  0x0000, 0x0078, 0x008F, 0x03EF, 0x028C, 0x0220,
	  0x03EF, 0x0360, 0x00C8, 0x028C, 0x0272, 0x0276,
	  0x0001, 0x0078, 0x008F, 0x03EF, 0x028C, 0x0220 }
      },
      { 0x019A, -3, 600,
        { 0x0429, 0x0351, 0x0093, 0x0290, 0x0266, 0x026A,
	  0x0000, 0x0082, 0x008F, 0x0429, 0x0291, 0x024E,
	  0x0429, 0x036E, 0x00F2, 0x0291, 0x0275, 0x0279,
	  0x0001, 0x0082, 0x008F, 0x0429, 0x0291, 0x024E }
      },
      { 0x0230, 3, 480,					/* PAL 640 */
        { 0x0371, 0x02AE, 0x00EA, 0x01FF, 0x01E8, 0x01EB,
	  0x0000, 0x0007, 0x0010, 0x0371, 0x0200, 0x0032,
  	  0x0371, 0x02C8, 0x0040, 0x0200, 0x01F0, 0x01F3,
	  0x0000, 0x000E, 0x0020, 0x0371, 0x0200, 0x0032 }
      },
      { 0x0226, 2, 480,
        { 0x0383, 0x02B1, 0x00F2, 0x0204, 0x01E9, 0x01EC,
	  0x0000, 0x0005, 0x000B, 0x0383, 0x0205, 0x0032,
	  0x0383, 0x02CD, 0x004F, 0x0205, 0x01F3, 0x01F6,
	  0x0000, 0x0005, 0x000B, 0x0383, 0x0205, 0x0032 }
      },
      { 0x021C, 1, 480,
        { 0x035F, 0x02AC, 0x00E4, 0x0209, 0x01EA, 0x01ED,
	  0x0000, 0x0004, 0x0009, 0x035F, 0x020A, 0x0032,
	  0x035F, 0x02C4, 0x0034, 0x020A, 0x01F5, 0x01F8,
	  0x0000, 0x0004, 0x0009, 0x035F, 0x020A, 0x0032 }
      },
      { 0x0212, 0, 480, /* default */
        { 0x034F, 0x02AA, 0x00DE, 0x020E, 0x01EC, 0x01F0,
	  0x0000, 0x0004, 0x0009, 0x034F, 0x020F, 0x0032,
	  0x034F, 0x02C0, 0x0028, 0x020F, 0x01F8, 0x01FC,
	  0x0000, 0x0004, 0x0009, 0x034F, 0x020F, 0x0032 }
      },
      { 0x0208, -1, 480,
        { 0x033F, 0x02A8, 0x00D8, 0x0213, 0x01ED, 0x01F1,
	  0x0000, 0x0004, 0x0009, 0x033F, 0x0214, 0x0032,
	  0x033F, 0x02BC, 0x001C, 0x0214, 0x01FA, 0x01FE,
	  0x0000, 0x0004, 0x0009, 0x033F, 0x0214, 0x0032 }
      },
      { 0x01FE, -2, 480,
        { 0x0395, 0x02B3, 0x00F8, 0x0218, 0x01EE, 0x01F2,
	  0x0000, 0x0001, 0x0002, 0x0395, 0x0219, 0x0032,
	  0x0395, 0x02D1, 0x005B, 0x0219, 0x01FD, 0x0201,
	  0x0000, 0x0001, 0x0002, 0x0395, 0x0219, 0x0032 }
      },
      { 0x01F4, -3, 480,
        { 0x0383, 0x02B1, 0x00F2, 0x021D, 0x01EF, 0x01F3,
	  0x0000, 0x0001, 0x0002, 0x0383, 0x021E, 0x0032,
	  0x0383, 0x02CD, 0x004F, 0x021E, 0x01FF, 0x0203,
	  0x0000, 0x0001, 0x0002, 0x0383, 0x021E, 0x0032 }
      },
      { 0x0230, 2, 576,					/* PAL 720 */
        { 0x03BF, 0x0318, 0x0090, 0x0260, 0x0250, 0x0253,
	  0x0000, 0x0004, 0x0007, 0x03BF, 0x0260, 0x00E0,
	  0x6954, 0x6C6C, 0x5320, 0x666F, 0x6169, 0x4220,
	  0x7265, 0x746E, 0x7373, 0x6E6F, 0x0260, 0x00E0 }
      },
      { 0x0226, 1, 576,
        { 0x03DD, 0x031F, 0x00A5, 0x0265, 0x0253, 0x0256,
	  0x0000, 0x0003, 0x0005, 0x03DD, 0x0265, 0x013B,
	  0x7242, 0x756F, 0x6867, 0x2074, 0x6F74, 0x7920,
	  0x756F, 0x6220, 0x2079, 0x6F6E, 0x2074, 0x2061  }
      },
      { 0x021C, 0, 576, /* default */
        { 0x0437, 0x0336, 0x00EA, 0x026A, 0x0255, 0x0258,
	  0x0000, 0x0002, 0x0003, 0x0437, 0x026A, 0x0180,
	  0x656D, 0x6572, 0x5720, 0x7A69, 0x7261, 0x2064,
	  0x7562, 0x2074, 0x6874, 0x2065, 0x0274, 0x01CE }
      },
      { 0x0212, -1, 576,
        { 0x0423, 0x0331, 0x00DB, 0x026F, 0x0258, 0x025C,
	  0x0001, 0x0002, 0x0003, 0x0423, 0x026F, 0x01CA,
	  0x6957, 0x617A, 0x6472, 0x4520, 0x7478, 0x6172,
	  0x726F, 0x6964, 0x616E, 0x7269, 0x3A65, 0x01CE }
      },
      { 0x0208, -2, 576,
        { 0x040F, 0x032C, 0x00CC, 0x0274, 0x025A, 0x025E,
	  0x0000, 0x0002, 0x0003, 0x040F, 0x0274, 0x01CA,
	  0x6854, 0x6D6F, 0x7361, 0x5720, 0x6E69, 0x7369,
	  0x6863, 0x6F68, 0x6566, 0x2172, 0x027E, 0x01CA }
      },
      { 0x01FE, -3, 576,
        { 0x03FB, 0x0327, 0x00BD, 0x0279, 0x025D, 0x0261,
	  0x0000, 0x0002, 0x0003, 0x03FB, 0x0279, 0x01CA,
	   }
      },
      { 0x01F4, -4, 576,
        { 0x03E7, 0x0322, 0x00AE, 0x027E, 0x025F, 0x0263,
	  0x0000, 0x0002, 0x0003, 0x03E7, 0x027E, 0x01CA,
	  0x6854, 0x7369, 0x7320, 0x6170, 0x6563, 0x6620,
	  0x726F, 0x7320, 0x6C61, 0x0365, 0x027F, 0x01FE }
      },
      { 0x0230, 3, 600,					/* PAL 800 */
        { 0x047F, 0x035C, 0x00B4, 0x0277, 0x0260, 0x0263,
	  0x0000, 0x0005, 0x0007, 0x047F, 0x0278, 0x0170,
	  0x047F, 0x0384, 0x0034, 0x0278, 0x0268, 0x026B,
	  0x0000, 0x0005, 0x0007, 0x047F, 0x0278, 0x017E }
      },
      { 0x0226, 2, 600,
        { 0x044B, 0x0356, 0x00A1, 0x027C, 0x0261, 0x0264,
	  0x0000, 0x0019, 0x0024, 0x044B, 0x027D, 0x0150,
	  0x044B, 0x0377, 0x000D, 0x027D, 0x026B, 0x026E,
	  0x0000, 0x0019, 0x0024, 0x044B, 0x027D, 0x015E }
      },
      { 0x021C, 1, 600,
        { 0x0437, 0x0353, 0x0099, 0x0281, 0x0262, 0x0265,
	  0x0000, 0x0019, 0x0024, 0x0437, 0x0282, 0x0150,
	  0x0437, 0x0372, 0x00FE, 0x0282, 0x026D, 0x0270,
	  0x0000, 0x0019, 0x0024, 0x0437, 0x0282, 0x015E }
      },
      { 0x0212, 0, 600, /* default */
        { 0x0423, 0x0351, 0x0092, 0x0286, 0x0264, 0x0268,
	  0x0000, 0x0019, 0x0024, 0x0423, 0x0287, 0x01C8,
	  0x0423, 0x036D, 0x00EF, 0x0287, 0x0270, 0x0274,
	  0x0000, 0x0019, 0x0024, 0x0423, 0x0287, 0x01D6 }
      },
      { 0x0208, -1, 600,
        { 0x040F, 0x034E, 0x008A, 0x028B, 0x0265, 0x0269,
	  0x0000, 0x0019, 0x0024, 0x040F, 0x028C, 0x01A0,
	  0x040F, 0x0368, 0x00E0, 0x028C, 0x0272, 0x0276,
	  0x0000, 0x0019, 0x0024, 0x040F, 0x028C, 0x01AE }
      },
      { 0x01FE, -2, 600,
        { 0x03FB, 0x034C, 0x0083, 0x0290, 0x0266, 0x026A,
	  0x0000, 0x0019, 0x0024, 0x03FB, 0x0291, 0x01C8,
	  0x03FB, 0x0363, 0x00D1, 0x0291, 0x0275, 0x0279,
	  0x0000, 0x0019, 0x0024, 0x03FB, 0x0291, 0x01D6 }
      },
      { 0x01F4, -3, 600,
        { 0x0437, 0x0353, 0x0099, 0x0295, 0x0267, 0x026B,
	  0x0000, 0x0003, 0x0004, 0x0437, 0x0296, 0x01BF,
	  0x0437, 0x0372, 0x00FE, 0x0296, 0x0277, 0x027B,
	  0x0000, 0x0003, 0x0004, 0x0437, 0x0296, 0x01BA }
      },
};

unsigned const char SiSScalingP1Regs[] = {
	0x08,0x09,0x0b,0x0c,0x0d,0x0e,0x10,0x11,0x12
};
unsigned const char SiSScalingP4Regs[] = {
	0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b
};

/* Mandatory functions */
static void SISIdentify(int flags);
static Bool SISProbe(DriverPtr drv, int flags);
static Bool SISPreInit(ScrnInfoPtr pScrn, int flags);
static Bool SISScreenInit(int Index, ScreenPtr pScreen, int argc, char **argv);
static Bool SISEnterVT(int scrnIndex, int flags);
static void SISLeaveVT(int scrnIndex, int flags);
static Bool SISCloseScreen(int scrnIndex, ScreenPtr pScreen);
static Bool SISSaveScreen(ScreenPtr pScreen, int mode);
static Bool SISSwitchMode(int scrnIndex, DisplayModePtr mode, int flags);
static void SISAdjustFrame(int scrnIndex, int x, int y, int flags);
#ifdef SISDUALHEAD
static Bool SISSaveScreenDH(ScreenPtr pScreen, int mode);
#endif

/* Optional functions */
static void       SISFreeScreen(int scrnIndex, int flags);
static ModeStatus SISValidMode(int scrnIndex, DisplayModePtr mode,
                               Bool verbose, int flags);

/* Internally used functions */
static Bool    SISMapMem(ScrnInfoPtr pScrn);
static Bool    SISUnmapMem(ScrnInfoPtr pScrn);
static void    SISSave(ScrnInfoPtr pScrn);
static void    SISRestore(ScrnInfoPtr pScrn);
static void    SISVESARestore(ScrnInfoPtr pScrn);
static Bool    SISModeInit(ScrnInfoPtr pScrn, DisplayModePtr mode);
static void    SISModifyModeInfo(DisplayModePtr mode);
static void    SiSPreSetMode(ScrnInfoPtr pScrn, DisplayModePtr mode, int viewmode);
static void    SiSPostSetMode(ScrnInfoPtr pScrn, SISRegPtr sisReg);
static void    SiS6326PostSetMode(ScrnInfoPtr pScrn, SISRegPtr sisReg);
static Bool    SiSSetVESAMode(ScrnInfoPtr pScrn, DisplayModePtr pMode);
static void    SiSBuildVesaModeList(ScrnInfoPtr pScrn, vbeInfoPtr pVbe, VbeInfoBlock *vbe);
static UShort  SiSCalcVESAModeIndex(ScrnInfoPtr pScrn, DisplayModePtr mode);
static void    SISVESASaveRestore(ScrnInfoPtr pScrn, vbeSaveRestoreFunction function);
static void    SISBridgeRestore(ScrnInfoPtr pScrn);
static void    SiSEnableTurboQueue(ScrnInfoPtr pScrn);
unsigned char  SISSearchCRT1Rate(ScrnInfoPtr pScrn, DisplayModePtr mode);
static void    SISWaitVBRetrace(ScrnInfoPtr pScrn);
void           SISWaitRetraceCRT1(ScrnInfoPtr pScrn);
void           SISWaitRetraceCRT2(ScrnInfoPtr pScrn);
Bool           InRegion(int x, int y, region r);
#ifdef SISMERGED
static void    SISMergePointerMoved(int scrnIndex, int x, int y);
#endif
BOOLEAN        SiSBridgeIsInSlaveMode(ScrnInfoPtr pScrn);
USHORT 	       SiS_CalcModeIndex(ScrnInfoPtr pScrn, DisplayModePtr mode,
				 unsigned long VBFlags, BOOLEAN hcm);
USHORT         SiS_CheckCalcModeIndex(ScrnInfoPtr pScrn, DisplayModePtr mode,
				 unsigned long VBFlags, BOOLEAN hcm);
unsigned char  SiS_GetSetBIOSScratch(ScrnInfoPtr pScrn, USHORT offset, unsigned char value);
#ifdef DEBUG
static void    SiSDumpModeInfo(ScrnInfoPtr pScrn, DisplayModePtr mode);
#endif

extern USHORT   SiS_GetModeID(int VGAEngine, ULONG VBFlags, int HDisplay, int VDisplay, int Depth, BOOL FSTN);
extern USHORT   SiS_GetModeID_LCD(int VGAEngine, ULONG VBFlags, int HDisplay, int VDisplay, int Depth,
				  BOOLEAN FSTN, USHORT CustomT, int LCDwith, int LCDheight);
extern USHORT   SiS_GetModeID_TV(int VGAEngine, ULONG VBFlags, int HDisplay, int VDisplay, int Depth);
extern USHORT   SiS_GetModeID_VGA2(int VGAEngine, ULONG VBFlags, int HDisplay, int VDisplay, int Depth);
extern int      SiSTranslateToVESA(ScrnInfoPtr pScrn, int modenumber);
extern BOOLEAN 	SiSBIOSSetMode(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension,
                               ScrnInfoPtr pScrn, DisplayModePtr mode, BOOLEAN IsCustom);
extern BOOLEAN  SiSSetMode(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension,
                           ScrnInfoPtr pScrn,USHORT ModeNo, BOOLEAN dosetpitch);
extern void	SiSRegInit(SiS_Private *SiS_Pr, USHORT BaseAddr);
extern void     SiSSetLVDSetc(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension,USHORT ModeNo);
extern void     SiS_GetVBType(SiS_Private *SiS_Pr, PSIS_HW_INFO);
extern DisplayModePtr SiSBuildBuiltInModeList(ScrnInfoPtr pScrn, BOOLEAN includelcdmodes,
					       BOOLEAN isfordvi);
extern BOOLEAN 	SiSBIOSSetModeCRT1(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension,
				   ScrnInfoPtr pScrn, DisplayModePtr mode, BOOLEAN IsCustom);
extern BOOLEAN 	SiSBIOSSetModeCRT2(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension,
				   ScrnInfoPtr pScrn, DisplayModePtr mode, BOOLEAN IsCustom);

/* For power management for 315 series */
extern void SiS_Chrontel701xBLOn(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension);
extern void SiS_Chrontel701xBLOff(SiS_Private *SiS_Pr);
extern void SiS_SiS30xBLOn(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension);
extern void SiS_SiS30xBLOff(SiS_Private *SiS_Pr, PSIS_HW_INFO HwDeviceExtension);


