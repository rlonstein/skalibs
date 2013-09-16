/* ISC license. */

#include <termios.h>
#include "ttymodes.h"

int ttymodes_sett (int fd, ttymodes const *t)
{
  if (ttymodes_sett_nohang(fd, t) == -1) return -1 ;
  return tcdrain(fd) ;
}
