/* { dg-do link { target { msp430_large_memory_model } } } */
/* { dg-do run { target { ! msp430_large_memory_model } } } */
/* { dg-options "-flto -save-temps" } */
/* { dg-final { scan-file attr-persistent-3.exe.ltrans0.s ".section\t\.persistent,\"aw\"\n" } } */

/* Test the "persistent" attribute with -flto.  Specifically examine the
   final LTO assembly file, to ensure the "persistent" setting on the variable
   hasn't been lost.  */
#include "attr-persistent-main.inc"
