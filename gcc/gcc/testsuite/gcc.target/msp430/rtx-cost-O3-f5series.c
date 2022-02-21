/* { dg-do compile } */
/* { dg-options "-O3 -mhwmult=f5series" } */
/* { dg-final { scan-assembler-not "__mspabi_slll" } } */
/* { dg-final { scan-assembler-not "__mspabi_mpyl_f5hw" } } */

/* Verify the MSP430 cost model is working as expected for the default ISA
   (msp430x) and f5series hwmult, when compiling at -O3.  */

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
  /* Emit 7 inline shifts for this.  */
  res2 *= 128;
  /* Perform this multiplication inline, using addition and shifts.  */
  res3 *= 100;
}
