/* ISC license. */

#include "uint16.h"
#include "ttymodes.h"

void ttymodes_packw (char *s, ttymodes const *t)
{
  uint16_pack(s, (uint16)t->ws.ws_row) ;
  s += 2 ;
  uint16_pack(s, (uint16)t->ws.ws_col) ;
  s += 2 ;
  uint16_pack(s, (uint16)t->ws.ws_xpixel) ;
  s += 2 ;
  uint16_pack(s, (uint16)t->ws.ws_ypixel) ;
}
