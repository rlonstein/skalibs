/* ISC license. */

#include "tai.h"
#include "iopause.h"
#include "djbunix.h"

void deepmillisleep (unsigned long millisecs)
{
  struct taia stamp, deadline ;
  taia_from_millisecs(&deadline, millisecs) ;
  taia_now(&stamp) ;
  taia_add(&deadline, &deadline, &stamp) ;
  deepsleepuntil(&deadline, &stamp) ;
}
