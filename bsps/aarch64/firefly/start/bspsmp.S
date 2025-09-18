/* SPDX-License-Identifier: BSD-2-Clause */

/**
 * @file
 *
 * @ingroup RTEMSBSPsAArch64Firefly
 *
 * @brief This source file contains the
 *   _AArch64_Get_current_processor_for_system_start() default implementation
 *   using the MPIDR_EL1.
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

#include <bsp.h>
#include <rtems/asm.h>

FUNCTION_ENTRY(_AArch64_Get_current_processor_for_system_start)

    mrs x0, MPIDR_EL1
    and x0, x0, #BSP_CORE_AFF_MASK

    ldr x1, =BSP_CORE2_AFF
    cmp x0, x1
    beq core0

    ldr x1, =BSP_CORE3_AFF
    cmp x0, x1
    beq core1

    ldr x1, =BSP_CORE0_AFF
    cmp x0, x1
    beq core2

    ldr x1, =BSP_CORE1_AFF
    cmp x0, x1
    beq core3

    b default

core0:
    mov x0, #0
    b return

core1:
    mov x0, #1
    b return

core2:
    mov x0, #2
    b return

core3:
    mov x0, #3
    b return

core4:
    mov x0, #4
    b return

core5:
    mov x0, #5
    b return

core6:
    mov x0, #6
    b return

core7:
    mov x0, #7
    b return

default:
    and x0, x0, #15

return:
    RET

FUNCTION_END(_AArch64_Get_current_processor_for_system_start)
