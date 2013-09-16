/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_unpack (char const *s, struct taia *t)
{
  uint32 x ;
  tai_unpack(s, &t->sec) ;
  uint32_unpack_big(s+8, &x) ;
  t->nano = x ;
  uint32_unpack_big(s+12, &x) ;
  t->atto = x ;
}