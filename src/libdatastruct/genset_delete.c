/* ISC license. */

#include <errno.h>
#include "bitarray.h"
#include "genset.h"

int genset_delete (genset_ref x, unsigned int i)
{
  if (i >= x->max) return (errno = EINVAL, 0) ;
  if (!bitarray_testandclear(x->bits, i)) return (errno = EINVAL, 0) ;
  return 1 ;
}
