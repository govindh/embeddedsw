/******************************************************************************
*
* Copyright (C) 2015 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*****************************************************************************/
/**
*
* @file xfsbl_hw.h
*
* This is the header file which contains definitions for the hardware
* registers.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date        Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00  kc   10/21/13 Initial release
*
* </pre>
*
* @note
*
******************************************************************************/

#ifndef XFSBL_HW_H
#define XFSBL_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xil_io.h"
#include "xparameters.h"
#include "xil_types.h"
#include "sleep.h"

#include "xfsbl_config.h"
#include "xfsbl_debug.h"
#include "xfsbl_error.h"
#include "xfsbl_hooks.h"
#include "xfsbl_misc.h"

/************************** Constant Definitions *****************************/

/* csu */

/**
 * CSU Base Address
 */
#define CSU_BASEADDR      0XFFCA0000U

/**
 * Register: CSU_CSU_SSS_CFG
 */
#define CSU_CSU_SSS_CFG    ( ( CSU_BASEADDR ) + 0X00000008U )
#define CSU_CSU_SSS_CFG_PCAP_SSS_MASK    0X0000000FU

/**
 * Register: CSU_PCAP_STATUS
 */
#define CSU_PCAP_STATUS    ( ( CSU_BASEADDR ) + 0X00003010U )

/**
 * Register: CSU_PCAP_RDWR
 */
#define CSU_PCAP_RDWR    ( ( CSU_BASEADDR ) + 0X00003004U )

/**
 * Register: CSU_VERSION
 */
#define CSU_VERSION    ( ( CSU_BASEADDR ) + 0X00000044U )

#define CSU_VERSION_PLATFORM_MASK    0X0000F000U

/**
 * Register: CSU_CSU_MULTI_BOOT
 */
#define CSU_CSU_MULTI_BOOT    ( ( CSU_BASEADDR ) + 0X00000010U )

/**
 * Register: CSU_SHA_RESET
 */
#define CSU_SHA_RESET    ( ( CSU_BASEADDR ) + 0X00002004U )
#define CSU_SHA_RESET_RESET_MASK    0X00000001U

/**
 * Register: CSU_SHA_START
 */
#define CSU_SHA_START    ( ( CSU_BASEADDR ) + 0X00002000U )
#define CSU_SHA_START_START_MSG_MASK    0X00000001U

/**
 * Register: CSU_SHA_DONE
 */
#define CSU_SHA_DONE    ( ( CSU_BASEADDR ) + 0X00002008U )
#define CSU_SHA_DONE_SHA_DONE_MASK    0X00000001U

/**
 * Register: CSU_SHA_DIGEST_0
 */
#define CSU_SHA_DIGEST_0    ( ( CSU_BASEADDR ) + 0X00002010U )


/* efuse */

/**
 * EFUSE Base Address
 */
#define EFUSE_BASEADDR      0XFFCC0000U

/**
 * Register: EFUSE_SEC_CTRL
 */
#define EFUSE_SEC_CTRL    ( ( EFUSE_BASEADDR ) + 0X00001058U )
#define EFUSE_SEC_CTRL_RSA_EN_MASK    0X03000000U

/* csudma */

/**
 * CSUDMA Base Address
 */
#define CSUDMA_BASEADDR      0XFFC80000U

/* crf_apb */

/**
 * CRF_APB Base Address
 */
#define CRF_APB_BASEADDR      0XFD1A0000U

/**
 * Register: CRF_APB_RST_FPD_APU
 */
#define CRF_APB_RST_FPD_APU    ( ( CRF_APB_BASEADDR ) + 0X00000104U )
#define CRF_APB_RST_FPD_APU_ACPU0_RESET_MASK    0X00000001U
#define CRF_APB_RST_FPD_APU_APU_L2_RESET_MASK    0X00000100U

/**
 * Register: CRF_APB_ACPU_CTRL
 */
#define CRF_APB_ACPU_CTRL    ( ( CRF_APB_BASEADDR ) + 0X00000060U )
#define CRF_APB_ACPU_CTRL_CLKACT_FULL_MASK    0X01000000U
#define CRF_APB_ACPU_CTRL_CLKACT_HALF_MASK    0X02000000U
#define CRF_APB_RST_FPD_APU_ACPU1_RESET_MASK    0X00000002U
#define CRF_APB_RST_FPD_APU_ACPU2_RESET_MASK    0X00000004U
#define CRF_APB_RST_FPD_APU_ACPU3_RESET_MASK    0X00000008U

#define CRF_APB_RST_FPD_APU_ACPU3_PWRON_RESET_MASK    0X00002000U
#define CRF_APB_RST_FPD_APU_ACPU2_PWRON_RESET_MASK    0X00001000U
#define CRF_APB_RST_FPD_APU_ACPU1_PWRON_RESET_MASK    0X00000800U
#define CRF_APB_RST_FPD_APU_ACPU0_PWRON_RESET_MASK    0X00000400U

/* crl_apb */

/**
 * CRL_APB Base Address
 */
#define CRL_APB_BASEADDR      0XFF5E0000U

/**
 * Register: CRL_APB_CPU_R5_CTRL
 */
#define CRL_APB_CPU_R5_CTRL    ( ( CRL_APB_BASEADDR ) + 0X00000090U )
#define CRL_APB_CPU_R5_CTRL_CLKACT_MASK    0X01000000U

/**
 * Register: CRL_APB_RST_LPD_TOP
 */
#define CRL_APB_RST_LPD_TOP    ( ( CRL_APB_BASEADDR ) + 0X0000023CU )
#define CRL_APB_RST_LPD_TOP_RPU_R50_RESET_MASK    0X00000001U
#define CRL_APB_RST_LPD_TOP_RPU_AMBA_RESET_MASK    0X00000004U
#define CRL_APB_RST_LPD_TOP_RPU_R51_RESET_MASK    0X00000002U

/**
 * Register: CRL_APB_BOOT_MODE_USER
 */
#define CRL_APB_BOOT_MODE_USER    ( ( CRL_APB_BASEADDR ) + 0X00000200U )
#define CRL_APB_BOOT_MODE_USER_BOOT_MODE_MASK    0X0000000FU

/**
 * Register: CRL_APB_RESET_CTRL
 */
#define CRL_APB_RESET_CTRL    ( ( CRL_APB_BASEADDR ) + 0X00000218U )
#define CRL_APB_RESET_CTRL_SOFT_RESET_MASK    0X00000010U

/* apu */

/**
 * APU Base Address
 */
#define APU_BASEADDR      0XFD5C0000U

/**
 * Register: APU_CONFIG_0
 */
#define APU_CONFIG_0    ( ( APU_BASEADDR ) + 0X00000020U )

/**
 * Register: APU_RVBARADDR0L
 */
#define APU_RVBARADDR0L    ( ( APU_BASEADDR ) + 0X00000040U )

/**
 * Register: APU_RVBARADDR0H
 */
#define APU_RVBARADDR0H    ( ( APU_BASEADDR ) + 0X00000044U )

/**
 * Register: APU_RVBARADDR1L
 */
#define APU_RVBARADDR1L    ( ( APU_BASEADDR ) + 0X00000048U )

/**
 * Register: APU_RVBARADDR1H
 */
#define APU_RVBARADDR1H    ( ( APU_BASEADDR ) + 0X0000004CU )

/**
 * Register: APU_RVBARADDR2L
 */
#define APU_RVBARADDR2L    ( ( APU_BASEADDR ) + 0X00000050U )

/**
 * Register: APU_RVBARADDR2H
 */
#define APU_RVBARADDR2H    ( ( APU_BASEADDR ) + 0X00000054U )

/**
 * Register: APU_RVBARADDR3L
 */
#define APU_RVBARADDR3L    ( ( APU_BASEADDR ) + 0X00000058U )

/**
 * Register: APU_RVBARADDR3H
 */
#define APU_RVBARADDR3H    ( ( APU_BASEADDR ) + 0X0000005CU )

/* pmu_global */

/**
 * Register: PMU_GLOBAL_PERS_GLOB_GEN_STORAGE1
 */
#define PMU_GLOBAL_PERS_GLOB_GEN_STORAGE1    ( ( PMU_GLOBAL_BASEADDR ) + 0X00000054U )

/**
 * PMU_GLOBAL Base Address
 */
#define PMU_GLOBAL_BASEADDR      0XFFD80000U

#define PMU_GLOBAL_GLOBAL_CNTRL    ( ( PMU_GLOBAL_BASEADDR ) + 0X00000000U )
#define PMU_GLOBAL_GLOBAL_CNTRL_MB_SLEEP_MASK    0X00010000U

/* rpu */

/**
 * RPU Base Address
 */
#define RPU_BASEADDR      0XFF9A0000U

/**
 * Register: RPU_RPU_GLBL_CNTL
 */
#define RPU_RPU_GLBL_CNTL    ( ( RPU_BASEADDR ) + 0X00000000U )
#define RPU_RPU_GLBL_CNTL_SLSPLIT_MASK    0X00000008U
#define RPU_RPU_GLBL_CNTL_TCM_COMB_MASK    0X00000040U
#define RPU_RPU_GLBL_CNTL_SLCLAMP_MASK    0X00000010U

/**
 * Register: RPU_RPU_0_CFG
 */
#define RPU_RPU_0_CFG    ( ( RPU_BASEADDR ) + 0X00000100U )
#define RPU_RPU_0_CFG_NCPUHALT_MASK    0X00000001U

/**
 * Register: RPU_RPU_1_CFG
 */
#define RPU_RPU_1_CFG    ( ( RPU_BASEADDR ) + 0X00000200U )
#define RPU_RPU_1_CFG_NCPUHALT_MASK    0X00000001U


/* rsa */

/**
 * RSA Base Address
 */
#define RSA_BASEADDR      0XFFCE002CU

/**
 * Register: RSA_WR_DATA_0
 */
#define RSA_WR_DATA_0    ( ( RSA_BASEADDR ) + 0X00000000U )

/**
 * Register: RSA_WR_ADDR
 */
#define RSA_WR_ADDR    ( ( RSA_BASEADDR ) + 0X00000018U )

/**
 * Register: RSA_RD_ADDR
 */
#define RSA_RD_ADDR    ( ( RSA_BASEADDR ) + 0X00000034U )

/**
 * Register: RSA_RD_DATA_0
 */
#define RSA_RD_DATA_0    ( ( RSA_BASEADDR ) + 0X0000001CU )

/* rsa_core */

/**
 * RSA_CORE Base Address
 */
#define RSA_CORE_BASEADDR      0XFFCE0000U

/**
 * Register: RSA_CORE_MINV0
 */
#define RSA_CORE_MINV0    ( ( RSA_CORE_BASEADDR ) + 0X00000018U )

/**
 * Register: RSA_CORE_MINV1
 */
#define RSA_CORE_MINV1    ( ( RSA_CORE_BASEADDR ) + 0X0000001CU )

/**
 * Register: RSA_CORE_MINV2
 */
#define RSA_CORE_MINV2    ( ( RSA_CORE_BASEADDR ) + 0X00000020U )

/**
 * Register: RSA_CORE_MINV3
 */
#define RSA_CORE_MINV3    ( ( RSA_CORE_BASEADDR ) + 0X00000024U )

/**
 * Register: RSA_CORE_STATUS
 */
#define RSA_CORE_STATUS    ( ( RSA_CORE_BASEADDR ) + 0X00000014U )
#define RSA_CORE_STATUS_ERROR_MASK    0X00000004U
#define RSA_CORE_STATUS_DONE_MASK    0X00000001U

/**
 * Register: RSA_CORE_CTRL
 */
#define RSA_CORE_CTRL    ( ( RSA_CORE_BASEADDR ) + 0X00000010U )

/* LPD_SLCR Base Address */
#define LPD_SLCR_BASEADDR      0XFF410000U

/* Register: LPD_SLCR_PERSISTENT4 */
#define LPD_SLCR_PERSISTENT4    ( ( LPD_SLCR_BASEADDR ) + 0X00000030U )

/* Register: LPD_SLCR_PERSISTENT5 */
#define LPD_SLCR_PERSISTENT5    ( ( LPD_SLCR_BASEADDR ) + 0X00000034U )

/* IPI Base Address */
#define IPI_BASEADDR      0XFF300000U

/* Register: IPI_PMU_0_TRIG */
#define IPI_PMU_0_TRIG    ( ( IPI_BASEADDR ) + 0X00030000U )
#define IPI_APU_TRIG_PMU_0_SHIFT    16U

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/



/**
 * For error reporting PMU_GLOBAL_PERS_GLOB_GEN_STORAGE1 is used
 */
#define XFSBL_ERROR_STATUS_REGISTER_OFFSET	(PMU_GLOBAL_PERS_GLOB_GEN_STORAGE1)


/* PMU RAM address for PMU FW */
#define XFSBL_PMU_RAM_START_ADDRESS		(0xFFDC0000U)
#define XFSBL_PMU_RAM_END_ADDRESS		(0xFFDDFFFFU)

/**
 * ARM Processor defines
 */
#define XFSBL_CLUSTER_ID_MASK			(0x00000F00U)
#define XFSBL_A53_PROCESSOR			(0x00000000U)
#define XFSBL_R5_PROCESSOR			(0x00000100U)


/**
 * Other FSBL defines
 * this can defined in xfsbl_main.h
 */
#define XFSBL_DDR_TEMP_ADDRESS			(0x100000U)
#define XFSBL_R5_0				(0x1U)
#define XFSBL_R5_L				(0x2U)

/**
 * TCM address for R5
 */
#define XFSBL_R5_TCM_START_ADDRESS		(0x0U)
#define XFSBL_R5_TCM_END_ADDRESS		(0x20000U)
#define XFSBL_R5L_TCM_END_ADDRESS		(0x40000U)

#define XFSBL_R50_HIGH_TCM_START_ADDRESS	(0xFFE00000U)
#define XFSBL_R51_HIGH_TCM_START_ADDRESS	(0xFFE90000U)

#define XFSBL_R5_TCM_LENGTH			(0x10000U)

/**
 * defines for the FSBL peripherals present
 */

/**
 * Definition for WDT to be included
 */
#ifdef XPAR_XWDTPS_0_DEVICE_ID
/*#define XFSBL_WDT_PRESENT*/
#endif

/**
 * Definition for SD to be included
 */
#if (!defined(FSBL_SD_EXCLUDE) && defined( XPAR_XSDPS_0_DEVICE_ID))
#define XFSBL_SD
#endif

/**
 * Definition for QSPI to be included
 */
#if (!defined(FSBL_QSPI_EXCLUDE) && defined(XPAR_XQSPIPSU_0_DEVICE_ID))
#define XFSBL_QSPI
#define XFSBL_QSPI_BASEADDRESS	XPAR_XQSPIPS_0_BASEADDR
#endif

/**
 * Definition for NAND to be included
 */
#if (!defined(FSBL_NAND_EXCLUDE) && defined(XPAR_XNANDPSU_0_DEVICE_ID))
#define XFSBL_NAND
#endif

/**
 * Definition for RSA to be included
 */
#if !defined(FSBL_RSA_EXCLUDE)
#define XFSBL_RSA
#endif

/**
 * Definition for AES to be included
 */
#if !defined(FSBL_AES_EXCLUDE)
#define XFSBL_AES
#endif

/**
 * Definition for SHA2 to be included
 */
#if !defined(FSBL_SHA2_EXCLUDE)
#define XFSBL_SHA2
#endif

#define XFSBL_QSPI_LINEAR_BASE_ADDRESS_START		(0xC0000000U)
#define XFSBL_QSPI_LINEAR_BASE_ADDRESS_END		(0xDFFFFFFFU)

#define XFSBL_PS_DDR
#define XFSBL_PS_DDR_START_ADDRESS		(0x0U)
#define XFSBL_PS_DDR_END_ADDRESS		(0x80000000U)  //2GB of DDR

#define XFSBL_OCM
#define XFSBL_OCM_START_ADDRESS			(0xFFFE2000U)
#define XFSBL_OCM_END_ADDRESS			(0xFFFF0000U)

#ifdef XFSBL_A53
#define PTRSIZE		u64
#else
#define PTRSIZE		u32
#endif


/****************************************************************************/
/**
*
* Read the given register.
*
* @param	BaseAddr is the base address of the device
* @param	RegOffset is the register offset to be read
*
* @return	The 32-bit value of the register
*
* @note		C-style signature:
*		u32 XFsbl_ReadReg(u32 BaseAddr, u32 RegOffset)
*
*****************************************************************************/
#define XFsbl_ReadReg(BaseAddr, RegOffset)		\
	Xil_In32((BaseAddr) + (RegOffset))

#define XFsbl_In32(Addr)		Xil_In32(Addr)

#define XFsbl_In64(Addr)		Xil_In64(Addr)

/****************************************************************************/
/**
*
* Write to the given register.
*
* @param	BaseAddr is the base address of the device
* @param	RegOffset is the register offset to be written
* @param	Data is the 32-bit value to write to the register
*
* @return	None.
*
* @note		C-style signature:
*		void XFsbl_WriteReg(u32 BaseAddr, u32 RegOffset, u32 Data)
*
*****************************************************************************/
#define XFsbl_WriteReg(BaseAddr, RegOffset, Data)	\
	Xil_Out32((BaseAddr) + (RegOffset), (Data))

#define XFsbl_Out32(Addr, Data)		Xil_Out32(Addr, Data)

#define XFsbl_Out64(Addr, Data)		Xil_Out64(Addr, Data)

/**
 * Platform
 */
#if 1
#define XFSBL_PLATFORM		\
		(Xil_In32(CSU_VERSION) & CSU_VERSION_PLATFORM_MASK )
#else
#define XFSBL_PLATFORM		XFSBL_PLATFORM_VELOCE
#endif

#define XFSBL_PLATFORM_SILICON	(0X00000000U)
#define XFSBL_PLATFORM_REMUS	(0X00001000U)
#define XFSBL_PLATFORM_VELOCE	(0X00002000U)
#define XFSBL_PLATFORM_QEMU	(0X00003000U)

/************************** Function Prototypes ******************************/

/************************** Variable Definitions *****************************/


#ifdef __cplusplus
}
#endif

#endif  /* XFSBL_HW_H */