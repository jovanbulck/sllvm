#include "modexp2.h"

#define MOD 7

int modexp2_enter(int y, __attribute__((secret)) int k)
{
  int r = 1;

  for (int i = 0; i < (sizeof(int) * 8); i++)
  {
    /* if ((k % 2) == 1) */
    {
      /* Compute true and false masks */
      int condition = ((k % 2) == 1);
      int tmask = -condition;
      int fmask = ~tmask;

      /* r = (r * y) % MOD; */
      int tr = ((r * y) % MOD) & tmask;
      int fr = r               & fmask;
      r = tr | fr;

      /* y = (y * y) % MOD; */
      int ty = ((y * y) % MOD) & tmask;
      int fy = y               & fmask;
      y = ty | fy;

      /* k >>= 1; */
      int tk = (k >> 1) & tmask;
      int fk = k        & fmask;
      k = tk | fk;
    }
  }

  return r % MOD;
}
