/* ISC license. */

#include <errno.h>
#include "bitarray.h"
#include "gensetdyn.h"

char *gensetdyn_p (gensetdyn const *g, unsigned int i)
{
  if (i >= g->storage.len) return (errno = EINVAL, (char *)0) ;
  return bitarray_peek((unsigned char *)g->bits.s, i) ? g->storage.s + i * g->esize : (errno = ENOENT, (char *)0) ;
}
