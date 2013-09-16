/* ISC license. */

#include <termios.h>
#include <errno.h>
#include "ttymodes.h"

int ttymodes_sett_nohang (int fd, ttymodes const *t)
{
  register int r ;
  do r = tcsetattr(fd, TCSADRAIN, (struct termios *)&t->ti) ;
  while ((r == -1) && (errno == EINTR)) ;
  return r ;
}
