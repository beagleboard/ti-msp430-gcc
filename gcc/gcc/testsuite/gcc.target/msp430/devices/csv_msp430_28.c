/* { dg-do link } */
/* { dg-msp-options "-mmcu=msp430_28" } */
/* { dg-warning "supports '430X' ISA but '-mcpu' option is set to '430'" "" { target 430_selected } 0 } */
/* { dg-warning "supports 'f5series' hardware multiply" "" { target msp430_hwmul_not_f5 } 0 } */

#include "../devices-main.c"
