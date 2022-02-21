/* { dg-do run } */
/* { dg-shouldfail { *-*-* } } */
/* { dg-output "STACK OVERFLOW" } */

/* Test for stack overflow detection when sbrk is not used.  */

#include <stdlib.h>

long long external;

/* Pass 0 for heap and stack collision or 1 for stack overflow.  */
long long __attribute__((noinline))
recurser (long long a)
{
  if (external == -1)
    return a;
  a = recurser (a);
  external = a;
  return a;
}

int
main (void)
{
  recurser (1);
}
