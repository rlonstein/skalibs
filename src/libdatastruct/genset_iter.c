/* ISC license. */

#include "bitarray.h"
#include "functypes.h"
#include "genset.h"

unsigned int genset_iter (genset_ref g, iterfunc_t_ref f, void *stuff)
{
  unsigned int i = 0, j = 0, n = 0 ;
  for (; (i < g->max) && (j < g->n) ; i++) if (bitarray_peek(g->bits, i))
  {
    j++ ;
    if ((*f)(g->storage + i * g->esize, stuff)) n++ ;
  }
  return n ;
}
