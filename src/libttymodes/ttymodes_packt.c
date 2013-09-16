/* ISC license. */

#include <termios.h>
#include "uint32.h"
#include "uint64.h"
#include "ttymodes.h"

void ttymodes_packt (char *s, ttymodes const *t)
{
  unsigned int i ;
  uint32_pack(s, (uint32)NCCS) ;
  s += 4 ;
  uint64_pack(s, (uint64)t->ti.c_iflag) ;
  s += 8 ;
  uint64_pack(s, (uint64)t->ti.c_oflag) ;
  s += 8 ;
  uint64_pack(s, (uint64)t->ti.c_cflag) ;
  s += 8 ;
  uint64_pack(s, (uint64)t->ti.c_lflag) ;
  s += 8 ;
  for (i = 0 ; i < NCCS ; i++)
  {
    uint64_pack(s, t->ti.c_cc[i]) ;
    s += 8 ;
  }
}
