/* { dg-do link { target { msp430_large_memory_model } } } */
/* { dg-do run { target { ! msp430_large_memory_model } } } */
/* { dg-options "-flto -save-temps" } */
/* { dg-final { scan-file attr-noinit-3.exe.ltrans0.s  ".section\t\.noinit,\"aw\"\n" } } */

/* Test the "noinit" attribute with -flto.  Specifically examine the
   final LTO assembly file, to ensure the "noinit" setting on the variable
   hasn't been lost.  */
#include "attr-noinit-main.inc"

