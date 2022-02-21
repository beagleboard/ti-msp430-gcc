// PR c++/37146
// { dg-do run }

extern "C" void abort ();
long a, b;
struct A { long i:8; long j:8; long k:16; long l:32; } c;

long
f1 (long x)
{
  return x ? a : b;
}

long
f2 (long x)
{
  return x ? c.i : c.j;
}

long
f3 (long x)
{
  return x ? c.i : a;
}

long
f4 (long x)
{
  return x ? c.i : c.k;
}

long
f5 (long x)
{
  return x ? c.l : b;
}

int
main ()
{
  a = 17;
  b = 18;
  c.i = 19;
  c.j = 20;
  c.k = 21;
  c.l = 22;
  if (f1 (1) != a)
    abort ();
  if (f1 (0) != b)
    abort ();
  if (f2 (1) != c.i)
    abort ();
  if (f2 (0) != c.j)
    abort ();
  if (f3 (1) != c.i)
    abort ();
  if (f3 (0) != a)
    abort ();
  if (f4 (1) != c.i)
    abort ();
  if (f4 (0) != c.k)
    abort ();
  if (f5 (1) != c.l)
    abort ();
  if (f5 (0) != b)
    abort ();
}
