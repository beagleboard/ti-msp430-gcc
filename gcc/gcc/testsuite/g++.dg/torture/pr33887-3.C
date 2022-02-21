/* { dg-do run } */

extern "C" void abort (void);

struct s
{
  unsigned long long f1 : 40;
  unsigned long f2 : 24;
};

s sv;

void __attribute__((noinline)) foo(unsigned long i)
{
  unsigned long tmp;
  sv.f2 = i;
  tmp = sv.f2;
  if (tmp != 0)
    abort ();
}

int main()
{
  foo (0xff000000u);
  return 0;
}
