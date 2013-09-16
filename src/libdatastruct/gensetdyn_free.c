/* ISC license. */

#include "stralloc.h"
#include "gensetdyn.h"

void gensetdyn_free (gensetdyn_ref g)
{
  stralloc_free(&g->storage) ;
  stralloc_free(&g->bits) ;
  *g = gensetdyn_zero ;
}
