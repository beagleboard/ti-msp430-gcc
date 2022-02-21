/* Copyright (c) 2013 Red Hat, Inc. All rights reserved.

   This copyrighted material is made available to anyone wishing to use, modify,
   copy, or redistribute it subject to the terms and conditions of the BSD
   License.   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY expressed or implied, including the implied warranties
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  A copy of this license
   is available at http://www.opensource.org/licenses. Any Red Hat trademarks that
   are incorporated in the source code or documentation are not subject to the BSD
   License and may only be used or replicated with the express permission of
   Red Hat, Inc.
*/

int write (int fd, const char *buf, int len);
void abort (void);

/* The end of data and start of available memory for the heap.
   It's defined in the linker script.  */
extern char end[];
/* A global symbol where the current position of the heap can be examined.  */
char *_sbrk_heap = end;

char *
_sbrk (int adj)
{
  char *         rv = _sbrk_heap;
  char *        sp = (char *) & sp;	/* Stack grows down, heap grows up...  */

  if (_sbrk_heap + adj > sp)
    {
#define MESSAGE "Heap and stack collision\n"
      write (1, MESSAGE, sizeof (MESSAGE) - 1);
      abort ();
    }

  _sbrk_heap += adj;
  return rv;
}

char * sbrk (int) __attribute__((weak, alias ("_sbrk")));
