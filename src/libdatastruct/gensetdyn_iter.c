/* ISC license. */

#include "bitarray.h"
#include "functypes.h"
#include "gensetdyn.h"

unsigned int gensetdyn_iter (gensetdyn_ref g, iterfunc_t_ref f, void *stuff)
{
  unsigned int i = 0, j = 0, n = 0 ;
  for (; (i < g->storage.len) && (j < g->bits.len) ; i++) if (bitarray_peek((unsigned char *)g->bits.s, i))
  {
    j++ ;
    if ((*f)(gensetdyn_p(g, i), stuff)) n++ ;
  }
  return n ;
}
