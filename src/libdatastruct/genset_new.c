/* ISC license. */

#include <errno.h>
#include "bitarray.h"
#include "genset.h"

unsigned int genset_new (genset_ref x)
{
  register unsigned int i ;
  if (x->n >= x->max) return (errno = ENOSPC, x->max) ;
  x->n++ ;
  i = bitarray_firstclear(x->bits, x->max) ;
  bitarray_set(x->bits, i) ;
  return i ;
}
