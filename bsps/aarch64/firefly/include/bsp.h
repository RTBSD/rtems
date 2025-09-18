/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup RTEMSBSPsAArch64Firefly
 *
 * @brief Core BSP definitions
 */

/*
 * Copyright (C) 2025 RTBSD
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

 #ifndef LIBBSP_AARCH64_FIREFLY_BSP_H
 #define LIBBSP_AARCH64_FIREFLY_BSP_H
 
 #include <bspopts.h>
 
 #ifndef ASM
 #include <bsp/default-initial-extension.h>
 #include <bsp/start.h>
 #endif
 
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
 
 /* definition of core information */
 #define BSP_CORE0_AFF       0x000U
 #define BSP_CORE1_AFF       0x100U 
 #define BSP_CORE2_AFF       0x200U
 #define BSP_CORE3_AFF       0x201U
 #define BSP_CORE_AFF_MASK   0xFFF
 #define BSP_CORE_NUM        4
 
 #ifndef ASM
 
 #define BSP_CPU_ON_USES_SMC
 
 /* definition for interrupts */
 #define BSP_SGI_INT_MAX     16U
 #define BSP_PPI_INT_LAST    (32U - 1)
 
 #define BSP_ARM_GIC_CPUIF_BASE  0x30800000U
 #define BSP_ARM_GIC_DIST_BASE   0x30800000U
 #define BSP_ARM_GIC_RD0_BASE   (BSP_ARM_GIC_CPUIF_BASE + 0x80000U)
 #define BSP_ARM_GIC_SGI0_BASE  (BSP_ARM_GIC_CPUIF_BASE + 0x90000U)
 #define BSP_ARM_GIC_RD1_BASE   (BSP_ARM_GIC_CPUIF_BASE + 0xA0000U)
 #define BSP_ARM_GIC_SGI1_BASE  (BSP_ARM_GIC_CPUIF_BASE + 0xB0000U)
 #define BSP_ARM_GIC_RD2_BASE   (BSP_ARM_GIC_CPUIF_BASE + 0xC0000U)
 #define BSP_ARM_GIC_SGI2_BASE  (BSP_ARM_GIC_CPUIF_BASE + 0xD0000U)
 #define BSP_ARM_GIC_RD3_BASE   (BSP_ARM_GIC_CPUIF_BASE + 0xE0000U)
 #define BSP_ARM_GIC_SGI3_BASE  (BSP_ARM_GIC_CPUIF_BASE + 0xF0000U)
 
 #ifdef  BSP_ARM_GIC_REDIST_BASE
 #undef  BSP_ARM_GIC_REDIST_BASE
 #endif
 
 /* assert primary core is physical core-2, affinity 0x200 */
 #define BSP_ARM_GIC_MAIN_AFF    BSP_CORE2_AFF
 
 /* definition for peripherals */
 #define BSP_FDT_IS_SUPPORTED
 
 #define BSP_FIREFLY_UART1_BASE    0x2800d000U
 #define BSP_FIREFLY_UART1_LENGTH  0x18000U
 
 #define BSP_FIREFLY_CONSOLE_UART_BASE   BSP_FIREFLY_UART1_BASE
 #define BSP_FIREFLY_CONSOLE_UART_LENGTH BSP_FIREFLY_UART1_LENGTH

 #define BSP_FIREFLY_CONSOLE_UART_BAUD   115200U
 #define BSP_FIREFLY_CONSOLE_UART_CLOCK  100000000U

 
 #endif /* ASM */
 
 #ifdef __cplusplus
 }
 #endif /* __cplusplus */
 
 
 /** @} */
 
 #endif /* LIBBSP_AARCH64_FIREFLY_BSP_H */
 