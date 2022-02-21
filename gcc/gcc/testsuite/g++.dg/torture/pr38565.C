// { dg-do compile }
// Ignore warning on some powerpc-linux configurations.
// { dg-prune-output "non-standard ABI extension" }
// { dg-prune-output "changes the ABI" }
#define vector __attribute__((vector_size(16) ))
vector unsigned long f(long a)
{
  vector unsigned long mask = a ? (vector unsigned long){ 0x80000000, 0x80000000,
0x80000000, 0x80000000 } : (vector unsigned long){0};
  return mask;
}

