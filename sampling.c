#include "poly.h"
#include "ntt.h"
#include "randombytes.h"
#include "reduce.h"
#include "fips202.h"
#include "crypto_stream_chacha20.h"

void poly_getnoise(poly *r, unsigned char *seed, unsigned char nonce)
{
#if PARAM_K != 16
#error "poly_getnoise in poly.c only supports k=16"
#endif

  unsigned char buf[4*PARAM_N];
  uint32_t *tp, t,d, a, b;
  unsigned char n[8];
  int i,j;

  tp = (uint32_t *) buf;

  for(i=1;i<8;i++)
    n[i] = 0;
  n[0] = nonce;

  crypto_stream_chacha20(buf,4*PARAM_N,n,seed);

  for(i=0;i<PARAM_N;i++)
  {
    t = tp[i];
    d = 0;
    for(j=0;j<8;j++)
      d += (t >> j) & 0x01010101;
    a = ((d >> 8) & 0xff) + (d & 0xff);
    b = (d >> 24) + ((d >> 16) & 0xff);
    r->coeffs[i] = a + PARAM_Q - b;
  }
}

