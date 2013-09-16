/* ISC license. */

#include "uint32.h"
#include "tai.h"

void tain_unpack_little (char const *s, struct taia *t)
{
  uint32 x ;
  t->atto = 0 ;
  uint32_unpack(s, &x) ;
  t->nano = x ;
  tai_unpack_little(s+4, &t->sec) ;
}
