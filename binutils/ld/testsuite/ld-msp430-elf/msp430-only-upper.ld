/* Script for ld testsuite */
OUTPUT_ARCH(msp430)
ENTRY(_start)

SECTIONS
{
  .upper.text :
  {
    . = ALIGN(2);
    PROVIDE (_start = .);
    *(.upper.text.* .upper.text)
  }

  .upper.rodata :
  {
    . = ALIGN(2);
    *(.upper.rodata .upper.rodata.*)
  }

  .upper.data :
  {
    . = ALIGN(2);
    *(.upper.data .upper.data.*)
  }

  .upper.bss :
  {
    . = ALIGN(2);
    *(.upper.bss .upper.bss.*)
  }
}
