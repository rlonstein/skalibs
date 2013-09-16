/* ISC license. */

#include "ttymodes.h"

unsigned int ttymodes_unpack (char const *s, ttymodes_ref t)
{
  unsigned int n = ttymodes_unpackt(s + WINSIZE_PACK, t) ;
  if (!n) return 0 ;
  ttymodes_unpackw(s, t) ;
  return WINSIZE_PACK + n ;
}
