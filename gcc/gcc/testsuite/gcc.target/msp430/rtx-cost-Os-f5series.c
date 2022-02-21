/* { dg-do compile } */
/* { dg-options "-Os -mhwmult=f5series" } */
/* { dg-final { scan-assembler-times "__mspabi_slll" 1 } } */
/* { dg-final { scan-assembler-times "__mspabi_mpyl_f5hw" 1 } } */

/* Verify the MSP430 cost model is working as expected for the default ISA
   (msp430x) and f5series hwmult, when compiling at -Os.  */

volatile unsigned long a;
volatile unsigned int b;
volatile unsigned long c;
unsigned long res1;
unsigned long res2;
unsigned long res3;

void foo (void)
{
  /* The shift here should get optimized out and replaced with a MOV.  */
  res1 = (a << 16) | b;
  /* Use the shift library function for this.  */
  res2 *= 128;
  /* Use the hardware multiply library function for this.  */
  res3 *= 100;
}
