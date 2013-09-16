/* ISC license. */

#include "tai.h"
#include "iopause.h"
#include "djbunix.h"

void deepsleep (unsigned int seconds)
{
  struct taia stamp, deadline ;
  taia_now(&stamp) ;
  taia_addsec(&deadline, &stamp, seconds) ;
  deepsleepuntil(&deadline, &stamp) ;
}
