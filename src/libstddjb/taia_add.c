/* ISC license. */

#include "tai.h"

void taia_add (struct taia *t, struct taia const *u, struct taia const *v)
{
  tai_add(&t->sec, &u->sec, &v->sec) ;
  t->nano = u->nano + v->nano ;
  t->atto = u->atto + v->atto ;
  if (t->atto > 999999999UL)
  {
    t->atto -= 1000000000UL ;
    ++t->nano ;
  }
  if (t->nano > 999999999UL)
  {
    t->nano -= 1000000000UL ;
    tai_u64(&t->sec, tai_sec(&t->sec)+1) ;
  }
}
