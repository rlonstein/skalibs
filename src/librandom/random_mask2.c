/* ISC license. */

#include "random-internal.h"

unsigned int random_mask2 (register unsigned int n)
{
  for (;;)
  {
    register unsigned int m = n | (n >> 1) ;
    if (m == n) return n ;
    n = m ;
  }
}
