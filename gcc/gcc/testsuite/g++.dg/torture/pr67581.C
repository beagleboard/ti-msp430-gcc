/* { dg-do compile } */
union U 
{
  long x; 
  float y;
} __attribute__ ((__transparent_union__));
