/* { dg-do run } */
/* { dg-shouldfail { *-*-* } } */
/* { dg-output "STACK OVERFLOW" } */

#include <stdlib.h>

long long external;

/* Pass 0 for heap and stack collision or 1 for stack overflow.  */
long long __attribute__((noinline))
recurser (long long a)
{
  long long *on_the_heap = NULL;
  if (a == 0)
  {
    if (external == -1)
      return a;
    on_the_heap = (long long *)malloc (sizeof (long long));
    *on_the_heap = a;
    recurser (*on_the_heap);
    external = *on_the_heap;
  }
  else
  {
    if (external == -1)
      return a;
    on_the_heap = (long long *)malloc (2);
    recurser (a);
    external = a;
  }
  if (*on_the_heap)
    return *on_the_heap;
  return 1;
}

long long *global_on_the_heap;

int
main (void)
{
  global_on_the_heap = (long long *)malloc (0x100);
  recurser (1);
}
