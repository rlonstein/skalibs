/* ISC license. */

#include <termios.h>
#include <errno.h>
#include "ttymodes.h"

int ttymodes_gett (int fd, ttymodes_ref t)
{
  register int r ;
  do
    r = tcgetattr(fd, &t->ti) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}
