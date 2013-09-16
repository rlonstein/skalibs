/* ISC license. */

/* MT-unsafe */

#include "surf.h"
#include "random-internal.h"
#include "random.h"

unsigned int dns_random (unsigned int n)
{
  unsigned int i = n ;
  unsigned int m ;
  if (!n) return 0 ;
  m = random_mask2(n-1) ;
  while (i >= n)
  {
    surf(&surf_here, (char *)&i, sizeof(unsigned int)) ;
    i &= m ;
  }
  return i ;
}
