/* ISC license. */

#include "uint16.h"
#include "ttymodes.h"

void ttymodes_unpackw (char const *s, ttymodes_ref t)
{
  uint16 u ;
  uint16_unpack(s, &u) ;
  t->ws.ws_row = u ;
  s += 2 ;
  uint16_unpack(s, &u) ;
  t->ws.ws_col = u ;
  s += 2 ;
  uint16_unpack(s, &u) ;
  t->ws.ws_xpixel = u ;
  s += 2 ;
  uint16_unpack(s, &u) ;
  t->ws.ws_ypixel = u ;
}
