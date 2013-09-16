/* ISC license. */

#include "ttymodes.h"

void ttymodes_pack (char *s, ttymodes const *t)
{
  ttymodes_packw(s, t) ;
  ttymodes_packt(s + WINSIZE_PACK, t) ;
}
