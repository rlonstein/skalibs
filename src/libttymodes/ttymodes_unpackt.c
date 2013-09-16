/* ISC license. */

#include <termios.h>
#include "uint32.h"
#include "uint64.h"
#include "ttymodes.h"

unsigned int ttymodes_unpackt (char const *s, ttymodes_ref t)
{
  uint32 nccs ;
  uint64 blah ;
  unsigned int i ;
  uint32_unpack(s, &nccs) ;
  if (nccs > NCCS) return 0 ;
  s += 4 ;
  uint64_unpack(s, &blah) ;
  t->ti.c_iflag = blah ;
  s += 8 ;
  uint64_unpack(s, &blah) ;
  t->ti.c_oflag = blah ;
  s += 8 ;
  uint64_unpack(s, &blah) ;
  t->ti.c_cflag = blah ;
  s += 8 ;
  uint64_unpack(s, &blah) ;
  t->ti.c_lflag = blah ;
  s += 8 ;
  for (i = 0 ; i < NCCS ; i++)
  {
    uint64_unpack(s, &blah) ;
    t->ti.c_cc[i] = blah ;
    s += 8 ;
  }
  return 36 + 8*nccs ;
}
