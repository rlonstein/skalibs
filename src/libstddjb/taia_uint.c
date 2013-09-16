/* ISC license. */

#include "tai.h"

void taia_uint (struct taia *t, unsigned int s)
{
  tai_uint(&t->sec, s) ;
  t->nano = 0 ;
  t->atto = 0 ;
}
