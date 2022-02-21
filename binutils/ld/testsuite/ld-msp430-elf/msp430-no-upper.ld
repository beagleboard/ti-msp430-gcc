/* Script for ld testsuite */
OUTPUT_ARCH(msp430)
ENTRY(_start)

SECTIONS
{
  .lower.text :
  {
    . = ALIGN(2);
    *(.lower.text)
  }

  .lower.rodata :
  {
    . = ALIGN(2);
    *(.lower.rodata.* .lower.rodata)
  }

  .lower.data :
  {
    . = ALIGN(2);
    *(.lower.data.* .lower.data)
  }

  .lower.bss :
  {
    . = ALIGN(2);
    *(.lower.bss.* .lower.bss)
  }

  .text :
  {
    . = ALIGN(2);
    PROVIDE (_start = .);
    *(.text)
  }

  .rodata :
  {
    *(.rodata.* .rodata)
  }

  .data :
  {
    . = ALIGN(2);
    *(.data.* .data)
  }

  .bss :
  {
    . = ALIGN(2);
    *(.bss.* .bss)
  }
}
