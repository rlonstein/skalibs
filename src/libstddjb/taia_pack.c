/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_pack (char *s, struct taia const *t)
{
  tai_pack(s, &t->sec) ;
  uint32_pack_big(s+8, (uint32)t->nano) ;
  uint32_pack_big(s+12, (uint32)t->atto) ;
}
