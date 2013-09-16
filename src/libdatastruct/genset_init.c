/* ISC license. */

#include "bytestr.h"
#include "bitarray.h"
#include "genset.h"

void genset_init (genset_ref x, void *storage, unsigned char *bits, unsigned int esize, unsigned int max)
{
  x->storage = (char *)storage ;
  x->bits = bits ;
  x->esize = esize ;
  x->max = max ;
  x->n = 0 ;
  byte_zero(bits, bitarray_div8(max)) ;
}
