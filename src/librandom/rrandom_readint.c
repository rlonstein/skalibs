/* ISC license. */

#include "unirandom.h"
#include "random-internal.h"
#include "rrandom.h"

unsigned int rrandom_readint (rrandom_ref z, unsigned int n, unsigned int (*f) (unirandom_ref, char *, unsigned int))
{
  unsigned int i = n ;
  unsigned int m ;
  if (!n) return 0 ;
  m = random_mask2(n-1) ;
  while (i >= n)
  {
    if (rrandom_read(z, (char *)&i, sizeof(unsigned int), f) < (int)sizeof(unsigned int)) return 0 ;
    i &= m ;
  }
  return i ;
}
