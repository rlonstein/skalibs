/* ISC license. */

#include "fmtscan.h"
#include "tai.h"

unsigned int tain_scan (char const *s, struct taia *a)
{
  char pack[TAIN_PACK] ;
  register unsigned int r = scan_ucharn(s, pack, TAIN_PACK) ;
  if (r) tain_unpack(pack, a) ;
  return r ;
}
