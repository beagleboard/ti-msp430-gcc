/* { dg-do link { target { msp430_large_memory_model } } } */
/* { dg-do run { target { ! msp430_large_memory_model } } } */
/* { dg-options "-save-temps" } */
/* { dg-final { scan-assembler ".section\t.persistent,\"aw\"\n" } } */

/* Test the "persistent" attribute.  */
#include "attr-persistent-main.inc"
