/* { dg-do compile } */
/* { dg-options "-muse-430x-for-mem -O1" } */
/* { dg-final { scan-assembler "MOVX" } } */
/* { dg-final { scan-assembler "MOV.W\t#1000, R12" } } */
/* { dg-final { scan-assembler-not "(?n)MOV\\..*\\(R" } } */

int arr[10];

int
foo (void)
{
  arr[3] = arr[2];
  arr[2] = arr[1];
  arr[1] = arr[0];
  /* 430X insns should not be used for small constants or registers.  */
  return 1000;
}

