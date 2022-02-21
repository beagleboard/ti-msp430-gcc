/* { dg-do compile } */
/* { dg-options "-O3" } */
/* { dg-final { scan-assembler "(?n)MOV.*\\&a, \\&arr\\+1" } } */
/* { dg-final { scan-assembler "(?n)MOV.*#arr\\+2, \\&ptr" } } */
/* { dg-final { scan-assembler-times "(?n)CALL.*ext" 2 } } */

/* Verify the MSP430 cost model is working as expected for the default ISA
   (msp430x) and hwmult (none), when compiling at -O3.  */

char arr[2];
char a;
char *ptr;

void
foo (void)
{
  arr[1] = a;
  ptr = arr + 2;
}

extern void ext (void);

void
bar (void)
{
  ext ();
  ext ();
}
