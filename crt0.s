        .global main                    // int main(void)

        .global _etext                  // -> .data initial values in ROM
        .global _data                   // -> .data area in RAM
        .global _edata                  // end of .data area
        .global __bss_start             // -> .bss area in RAM
        .global __bss_end__             // end of .bss area
        .global _stack                  // top of stack

// Stack Sizes
        .set  UND_STACK_SIZE, 0x00000004
        .set  ABT_STACK_SIZE, 0x00000004
        .set  FIQ_STACK_SIZE, 0x00000004
        .set  IRQ_STACK_SIZE, 0X00000080
        .set  SVC_STACK_SIZE, 0x00000004

// Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs
        .set  MODE_USR, 0x10            // User Mode
        .set  MODE_FIQ, 0x11            // FIQ Mode
        .set  MODE_IRQ, 0x12            // IRQ Mode
        .set  MODE_SVC, 0x13            // Supervisor Mode
        .set  MODE_ABT, 0x17            // Abort Mode
        .set  MODE_UND, 0x1B            // Undefined Mode
        .set  MODE_SYS, 0x1F            // System Mode

        .equ  I_BIT, 0x80               // when I bit is set, IRQ is disabled
        .equ  F_BIT, 0x40               // when F bit is set, FIQ is disabled

// VPBDIV definitions
        .set VPBDIV, 0xE01FC100  /* VPBDIV Address */

// <e> VPBDIV Setup
// <i> Peripheral Bus Clock Rate
//   <o1.0..1>   VPBDIV: VPB Clock
//               <0=> VPB Clock = CPU Clock / 4
//               <1=> VPB Clock = CPU Clock
//               <2=> VPB Clock = CPU Clock / 2
//   <o1.4..5>   XCLKDIV: XCLK Pin
//               <0=> XCLK Pin = CPU Clock / 4
//               <1=> XCLK Pin = CPU Clock
//               <2=> XCLK Pin = CPU Clock / 2
// </e>
        .set VPBDIV_Val, 0x00000001

// Phase Locked Loop (PLL) definitions
        .set PLL_BASE,      0xE01FC080  /* PLL Base Address */
        .set PLLCON_OFS,    0x00        /* PLL Control Offset*/
        .set PLLCFG_OFS,    0x04        /* PLL Configuration Offset */
        .set PLLSTAT_OFS,   0x08        /* PLL Status Offset */
        .set PLLFEED_OFS,   0x0C        /* PLL Feed Offset */
        .set PLLCON_PLLE,   (1<<0)      /* PLL Enable */
        .set PLLCON_PLLC,   (1<<1)      /* PLL Connect */
        .set PLLCFG_MSEL,   (0x1F<<0)   /* PLL Multiplier */
        .set PLLCFG_PSEL,   (0x03<<5)   /* PLL Divider */
        .set PLLSTAT_PLOCK, (1<<10)     /* PLL Lock Status */

// <e> PLL Setup
// <i> Phase Locked Loop
// <i> CCLK - Processor Clock
// <i> Fcco - PLL Oscillator
//   <o1.0..4>   MSEL: PLL Multiplier Selection
//               <1-32><#-1>
//               <i> PLL Multiplier "M" Value
//               <i> CCLK = M * Fosc
//   <o1.5..6>   PSEL: PLL Divider Selection
//               <0=> 1   <1=> 2   <2=> 4   <3=> 8
//               <i> PLL Divider "P" Value
//               <i> Fcco = CCLK * 2 * P
//               <i> 156MHz <= Fcco <= 320MHz
// </e>
        .equ PLLCFG_Val,    0x00000024

// Memory Accelerator Module (MAM) definitions
        .set MAM_BASE,   0xE01FC000  /* MAM Base Address */
        .set MAMCR_OFS,  0x00        /* MAM Control Offset*/
        .set MAMTIM_OFS, 0x04        /* MAM Timing Offset */

// <e> MAM Setup
// <i> Memory Accelerator Module
//   <o1.0..1>   MAM Control
//               <0=> Disabled
//               <1=> Partially Enabled
//               <2=> Fully Enabled
//               <i> Mode
//   <o2.0..2>   MAM Timing
//               <0=> Reserved  <1=> 1   <2=> 2   <3=> 3
//               <4=> 4         <5=> 5   <6=> 6   <7=> 7
//               <i> Fetch Cycles
// </e>
        .set MAMCR_Val,    0x00000002
        .set MAMTIM_Val,   0x00000004

        .text
        .code 32
        .align 2

        .global _boot
        .func   _boot
_boot:

// Runtime Interrupt Vectors
// -------------------------
Vectors:
        b     _start                    // reset - _start
        ldr   pc, Undef_Addr
        ldr   pc, SWI_Addr
        ldr   pc, PAbt_Addr
        ldr   pc, DAbt_Addr
        nop                             // reserved
//        ldr   pc, IRQ_Addr
        ldr   pc, [pc, #-0x0FF0]        // Vector from VicVectAddr (magic!  It's at 0xfffff030)
        ldr   pc, FIQ_Addr

Undef_Addr:  .word Undef_Handler
SWI_Addr:    .word SWI_Handler
PAbt_Addr:   .word PAbt_Handler
DAbt_Addr:   .word DAbt_Handler
IRQ_Addr:    .word IRQ_Handler
FIQ_Addr:    .word FIQ_Handler

Undef_Handler: b     .
SWI_Handler:   b     .
PAbt_Handler:  b     .
DAbt_Handler:  b     .
IRQ_Handler:   b     .
FIQ_Handler:   b     .

        .size _boot, . - _boot
        .endfunc


// Setup the operating mode & stack.
// ---------------------------------
        .global _start, start
//, _mainCRTStartup
        .func   _start

_start:
start:
_mainCRTStartup:

// Setup VPBDIV
       ldr     r0, =VPBDIV
       ldr     r1, =VPBDIV_Val
       str     r1, [r0]

// Setup PLL
       ldr     r0, =PLL_BASE
       mov     r1, #0xAA
       mov     r2, #0x55

//  Configure and Enable PLL
       mov     r3, #PLLCFG_Val
       str     r3, [r0, #PLLCFG_OFS]
       mov     r3, #PLLCON_PLLE
       str     r3, [r0, #PLLCON_OFS]
       str     r1, [r0, #PLLFEED_OFS]
       str     R2, [r0, #PLLFEED_OFS]

//  Wait until PLL Locked
PLL_Loop:
       ldr     r3, [r0, #PLLSTAT_OFS]
       ands    r3, r3, #PLLSTAT_PLOCK
       beq     PLL_Loop

//  Switch to PLL Clock
       mov     r3, #(PLLCON_PLLE|PLLCON_PLLC)
       str     r3, [r0, #PLLCON_OFS]
       str     r1, [r0, #PLLFEED_OFS]
       str     r2, [r0, #PLLFEED_OFS]

// Setup MAM
       ldr     r0, =MAM_BASE
       mov     r1, #MAMTIM_Val
       str     r1, [r0, #MAMTIM_OFS]
       mov     r1, #MAMCR_Val
       str     r1, [r0, #MAMCR_OFS]

// Setup Stack for each mode
        ldr   r0,=_stack

// Enter Undefined Instruction Mode and set its Stack Pointer
        msr   CPSR_c,#MODE_UND|I_BIT|F_BIT
        mov   sp,r0
        sub   r0,r0,#UND_STACK_SIZE

// Enter Abort Mode and set its Stack Pointer
        msr   CPSR_c,#MODE_ABT|I_BIT|F_BIT
        mov   sp,r0
        sub   r0,r0,#ABT_STACK_SIZE

// Enter FIQ Mode and set its Stack Pointer
        msr   CPSR_c,#MODE_FIQ|I_BIT|F_BIT
        mov   sp,r0
        sub   r0,r0,#FIQ_STACK_SIZE

// Enter IRQ Mode and set its Stack Pointer
        msr   CPSR_c,#MODE_IRQ|I_BIT|F_BIT
        mov   sp,r0
        sub   r0,r0,#IRQ_STACK_SIZE

// Enter Supervisor Mode and set its Stack Pointer
        msr   CPSR_c,#MODE_SVC|I_BIT|F_BIT
        mov   sp,r0
        sub   r0,r0,#SVC_STACK_SIZE

// Enter User Mode and set its Stack Pointer
        msr   CPSR_c, #MODE_USR
//        msr   CPSR_c,#MODE_SYS|I_BIT|F_BIT // System Mode
        mov   sp,r0

/* Relocate .data section (Copy from ROM to RAM) */
                LDR     R1, =_etext
                LDR     R2, =_data
                LDR     R3, =_edata
                CMP     R2, R3
                BEQ     DataIsEmpty
LoopRel:        CMP     R2, R3
                LDRLO   R0, [R1], #4
                STRLO   R0, [R2], #4
                BLO     LoopRel
DataIsEmpty:

/* Clear .bss section (Zero init) */
                MOV     R0, #0
                LDR     R1, =__bss_start__
                LDR     R2, =__bss_end__
                CMP     R1,R2
                BEQ     BSSIsEmpty
LoopZI:         CMP     R1, R2
                STRLO   R0, [R1], #4
                BLO     LoopZI
BSSIsEmpty:

// Enter the C code
        ldr   r0, =main
        bx    r0

        .size   _start, . - _start
        .endfunc

        .global _reset, reset, exit, abort
        .func   _reset
_reset:
reset:
exit:
abort:
        b     .                         // loop until reset

        .size _reset, . - _reset
        .endfunc

        .end
