/* ISC license. */

#include "bitarray.h"
#include "stralloc.h"
#include "gensetdyn.h"

int gensetdyn_ready (gensetdyn_ref g, unsigned int n)
{
  int wasnull = !g->storage.s ;
  if (!stralloc_ready_tuned(&g->storage, n * g->esize, g->base * g->esize, g->fracnum, g->fracden)) return 0 ;
  if (!stralloc_ready_tuned(&g->bits, bitarray_div8(n), bitarray_div8(g->base), g->fracnum, g->fracden))
  {
    if (wasnull) stralloc_free(&g->storage) ;
    return 0 ;
  }
  return 1 ;
}
