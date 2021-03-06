/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MT6575_EMI_BW_LIMITER__
#define __MT6575_EMI_BW_LIMITER__

/*
 * Define EMI hardware registers.
 */

#define EMI_CONA    (EMI_BASE + 0x0000)
#define EMI_CONB    (EMI_BASE + 0x0008)
#define EMI_CONC    (EMI_BASE + 0x0010)
#define EMI_COND    (EMI_BASE + 0x0018)
#define EMI_CONE    (EMI_BASE + 0x0020)
#define EMI_ARBA    (EMI_BASE + 0x0100)
#define EMI_ARBB    (EMI_BASE + 0x0108)
#define EMI_ARBC    (EMI_BASE + 0x0110)
#define EMI_ARBD    (EMI_BASE + 0x0118)
#define EMI_ARBE    (EMI_BASE + 0x0120)
#define EMI_ARBF    (EMI_BASE + 0x0128)
#define EMI_ARBG    (EMI_BASE + 0x0130)
#define EMI_ARBI    (EMI_BASE + 0x0140)
#define EMI_ARBJ    (EMI_BASE + 0x0148)
#define EMI_ARBK    (EMI_BASE + 0x0150)
#define EMI_SLCT    (EMI_BASE + 0x0158)

/*
 * Define constants.
 */

/* define concurrency scenario ID */
enum 
{
#define X_CON_SCE(con_sce, arba, arbc, arbd, arbe, arbf, arbg) con_sce,
#include "mach/mt6575_con_sce.h"
#undef X_CON_SCE
    NR_CON_SCE
};

/* define control operation */
enum
{
    ENABLE_CON_SCE = 0,
    DISABLE_CON_SCE = 1
};

#define EN_CON_SCE_STR "ON"
#define DIS_CON_SCE_STR "OFF"

/*
 * Define data structures.
 */

/* define control table entry */
struct emi_bwl_ctrl
{
    unsigned int ref_cnt; 
};

/*
 * Define function prototype.
 */

extern int mtk_mem_bw_ctrl(int sce, int op);

#endif  /* !__MT6575_EMI_BWL_H__ */

