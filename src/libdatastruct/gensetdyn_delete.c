/* ISC license. */

#include <errno.h>
#include "bitarray.h"
#include "stralloc.h"
#include "gensetdyn.h"

int gensetdyn_delete (gensetdyn_ref g, unsigned int i)
{
  if (i >= g->storage.len) return (errno = EINVAL, 0) ;
  if (!bitarray_testandclear((unsigned char *)g->bits.s, i)) return (errno = ENOENT, 0) ;
  g->bits.len-- ;
  while (g->storage.len && !bitarray_peek((unsigned char *)g->bits.s, g->storage.len - 1)) g->storage.len-- ;
  return 1 ;
}
