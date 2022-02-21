typedef signed short ee_s16;
typedef signed long ee_s32;
typedef unsigned long ee_u32;

typedef ee_s16 MATDAT;
typedef ee_s32 MATRES;

void matrix_mul_const(ee_u32 N, MATRES *C, MATDAT *A, MATDAT val) {
  ee_u32 j;
  for (j=0; j<N; j++) {
    C[N+j]=(MATRES)A[N+j] * (MATRES)val;
  }
}
