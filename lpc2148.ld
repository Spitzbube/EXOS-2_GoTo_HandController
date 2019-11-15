/***********************************************************************/
/*                                                                     */
/*  ROM.ld:  Linker Script File                                        */
/*                                                                     */
/***********************************************************************/
ENTRY(_boot)
STACK_SIZE = 0x400;

/* Memory Definitions */
/* lpc2138 mt */
MEMORY
{
  ROM (rx) : ORIGIN = 0x00000000, LENGTH = 0x00080000
  RAM (rw) : ORIGIN = 0x40000000, LENGTH = 0x00008000
}

/* Section Definitions */
SECTIONS
{
  /* first section is .text which is used for code */
  .text :
  {
    *crt0.o (.text)            /* Startup code */
    *(.text)                   /* remaining code */
    *(.rodata)                 /* read-only data (constants) */
    *(.rodata*)
    *(.glue_7)
    *(.glue_7t)
  } > ROM

  . = ALIGN(4);
    
  _etext = . ;
  PROVIDE (etext = .);

  /* .data section which is used for initialized data */
  .data : AT (_etext)
  {
    _data = .;
    *(.data)
  } > RAM
 
  . = ALIGN(4);
  _edata = . ;
  PROVIDE (edata = .);

  /* .bss section which is used for uninitialized data */
  .bss (NOLOAD) :
  {
    __bss_start = . ;
    __bss_start__ = . ;
    *(.bss)
    *(COMMON)
    . = ALIGN(4);
  } > RAM

  . = ALIGN(4);
  __bss_end__ = . ;
  PROVIDE (__bss_end = .);

  /* .stack ALIGN(256) : */
  .stack :
  {
    . = ALIGN(256);
    . += STACK_SIZE;
    PROVIDE (_stack = .);
  } > RAM

  __heap_beg__ = .;
  __heap_end__ = .; 
  
  PROVIDE(__HEAP_START = __heap_beg__ );

  _end = . ;
  PROVIDE (end = .);  
}
