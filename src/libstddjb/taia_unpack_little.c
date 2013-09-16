/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_unpack_little (char const *s, struct taia *t)
{
  uint32 x ;
  uint32_unpack(s, &x) ;
  t->atto = x ;
  uint32_unpack(s+4, &x) ;
  t->nano = x ;
  tai_unpack_little(s+8, &t->sec) ;
}
