/* ISC license. */

#include "bitarray.h"
#include "stralloc.h"
#include "gensetdyn.h"

int gensetdyn_new (gensetdyn_ref g, unsigned int *i)
{
  register unsigned int r ;
  if (g->bits.len < g->storage.len)
    r = bitarray_firstclear((unsigned char *)g->bits.s, g->storage.len) ;
  else
  {
    if (!gensetdyn_readyplus(g, 1)) return 0 ;
    r = g->storage.len++ ;
  }
  g->bits.len++ ; bitarray_set((unsigned char *)g->bits.s, r) ;
  *i = r ;
  return 1 ;
}
